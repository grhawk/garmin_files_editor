//
// Created by Riccardo Petraglia on 29.08.21.
//

//#pragma once
#ifndef GARMIN_FILES_EDITOR_ENGINE_TESTS_HELPERS_TEST_HELPER_FUNCTIONS_H_
#define GARMIN_FILES_EDITOR_ENGINE_TESTS_HELPERS_TEST_HELPER_FUNCTIONS_H_

#include <random>
#include "garmin_files_editor/tcx/models/types.h"


namespace gar_edit::test_helpers {

long double generateRandomLongDoubleWithIn(const long double& lower_bound, const long double& upper_bound) {
  std::uniform_real_distribution<long double> unif(lower_bound, upper_bound);
  std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
  return unif(re);
}

long int generateRandomIntegerWithIn(const int& lower_bound, const int& upper_bound) {
  return std::stol(std::to_string(generateRandomLongDoubleWithIn(std::stold(std::to_string(lower_bound)),
                                                   std::stold(std::to_string(upper_bound)))));
}

std::string timeToString(std::time_t epoch) {
  // "2021-06-12T10:49:41.000Z";
  std::stringstream ss;
  std::time_t tt = epoch;

  struct std::tm* ptm = std::gmtime(&tt);
  ss << std::put_time(ptm, timeFormat);
  return ss.str();
}

struct trackpointData {
  trackpointData() : time{0}, latitude{0}, longitude{0}, altitude{0}, distance{0}, hbpm{0}, speed{0}, trackpoint{0}{}
  long time;
  gar_edit::Coordinate latitude;
  gar_edit::Coordinate longitude;
  gar_edit::Altitude altitude;
  gar_edit::Distance distance;
  gar_edit::Hbpm hbpm;
  gar_edit::Speed speed;

  std::string trackpoint;
};

void generateTrackpoint(trackpointData& tcd) {
  std::stringstream position_node_xml;
  position_node_xml <<
                    std::setprecision(21)
                    <<
                    "          <Trackpoint>\n"
                    "            <Time>"
                    << timeToString(tcd.time) <<
                    "            </Time>\n"
                    "            <Position>\n"
                    "              <LatitudeDegrees>"
                    << tcd.latitude <<
                    "              </LatitudeDegrees>\n"
                    "              <LongitudeDegrees>"
                    << tcd.longitude <<
                    "              </LongitudeDegrees>\n"
                    "            </Position>\n"
                    "            <HeartRateBpm>\n"
                    "              <Value>"
                    << tcd.hbpm <<
                    "              </Value>\n"
                    "            </HeartRateBpm>\n"
                    "            <Extensions>\n"
                    "              <ns3:TPX>\n"
                    "                <ns3:Speed>"
                    << tcd.speed <<
                    "                </ns3:Speed>\n"
                    "              </ns3:TPX>\n"
                    "            </Extensions>\n"
                    "            <AltitudeMeters>"
                    << tcd.altitude <<
                    "            </AltitudeMeters>\n"
                    "            <DistanceMeters>"
                    << tcd.distance <<
                    "            </DistanceMeters>"
                    "          </Trackpoint>";
  tcd.trackpoint = position_node_xml.str();
}

[[nodiscard]] trackpointData generateRandomTrackpoint() {
  trackpointData tcd;
  tcd.latitude = generateRandomLongDoubleWithIn(0.0l, 90.0l);
  tcd.longitude = generateRandomLongDoubleWithIn(0.0l, 180.0l);
  tcd.hbpm = generateRandomIntegerWithIn(20, 250);
  tcd.speed = generateRandomLongDoubleWithIn(0.0l, 180.0l);
  tcd.altitude = generateRandomLongDoubleWithIn(0.0l, 12000.0l);
  tcd.distance = generateRandomLongDoubleWithIn(0.0l, 180.0l);
  tcd.time = generateRandomIntegerWithIn(0, 1630355378);

  generateTrackpoint(tcd);

  return tcd;
}

}

#endif //GARMIN_FILES_EDITOR_ENGINE_TESTS_HELPERS_TEST_HELPER_FUNCTIONS_H_
