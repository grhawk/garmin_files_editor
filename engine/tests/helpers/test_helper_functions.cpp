//
// Created by Riccardo Petraglia on 30.08.21.
//

#include "test_helper_functions.h"
#include <iostream>
#include <cstdlib>

long double gar_edit::test_helpers::generateRandomLongDoubleWithIn(const long double &lower_bound,
                                                                   const long double &upper_bound) {
  std::uniform_real_distribution<long double> unif(lower_bound, upper_bound);
  std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
  return unif(re);
}

long int gar_edit::test_helpers::generateRandomIntegerWithIn(const int &lower_bound, const int &upper_bound) {
  return std::stol(std::to_string(generateRandomLongDoubleWithIn(std::stold(std::to_string(lower_bound)),
                                                                 std::stold(std::to_string(upper_bound)))));
}

std::string gar_edit::test_helpers::timeToString(std::time_t epoch) {
  // "2021-06-12T10:49:41.000Z";
  std::stringstream ss;
  std::time_t tt = epoch;

  std::tm* ptm = nullptr;
  ptm = std::localtime(&tt);
  ptm->tm_isdst = -1;

  ss << std::put_time(ptm, timeFormat);
  std::cout << ss.str() << std::endl;
  return ss.str();
}

void gar_edit::test_helpers::generatePosition(gar_edit::test_helpers::positionData &pd) {
  std::stringstream position_node_xml;
  position_node_xml <<
                    std::setprecision(21)
                    <<
                    "            <Position>\n"
                    "              <LatitudeDegrees>" << pd.latitude << "</LatitudeDegrees>\n"
                    "              <LongitudeDegrees>" << pd.longitude << "</LongitudeDegrees>\n"
                    "            </Position>\n";
  pd.position = position_node_xml.str();
}

void gar_edit::test_helpers::generateTrackpoint(gar_edit::test_helpers::trackpointData &tcd) {
  std::stringstream position_node_xml;
  position_node_xml << std::setprecision(21) <<
                    "          <Trackpoint>\n"
                    "            <Time>" << timeToString(tcd.time) << "</Time>\n"
                    << tcd.position_data.position <<
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
                    "            </DistanceMeters>\n"
                    "          </Trackpoint>";
  tcd.trackpoint = position_node_xml.str();
}

gar_edit::test_helpers::positionData gar_edit::test_helpers::generateRandomPosition() {
  positionData pd;
  pd.latitude = generateRandomLongDoubleWithIn(0.0l, 90.0l);
  pd.longitude = generateRandomLongDoubleWithIn(0.0l, 180.0l);

  generatePosition(pd);
  return pd;
}

gar_edit::test_helpers::trackpointData gar_edit::test_helpers::generateRandomTrackpoint() {
  trackpointData tcd;
  tcd.position_data = generateRandomPosition();

  tcd.hbpm = generateRandomIntegerWithIn(20, 250);
  tcd.speed = generateRandomLongDoubleWithIn(0.0l, 180.0l);
  tcd.altitude = generateRandomLongDoubleWithIn(0.0l, 12000.0l);
  tcd.distance = generateRandomLongDoubleWithIn(0.0l, 180.0l);
  tcd.time = generateRandomIntegerWithIn(0, 1630355378);

  //tcd.time = 1630441529;
  //tcd.time = 1417895934;//generateRandomIntegerWithIn(0, 1630355378);


  generateTrackpoint(tcd);

  return tcd;
}
gar_edit::test_helpers::tracData gar_edit::test_helpers::generateRandomTrack(int lowest_number_of_trackpoints,
																			 int highest_number_of_trackpoints) {
  tracData td;
  td.trackpoint_data_size = generateRandomIntegerWithIn(lowest_number_of_trackpoints,
														highest_number_of_trackpoints);
  std::stringstream ss;
  ss << "        <Track>\n";

  for (std::size_t i = 0; i != td.trackpoint_data_size; i++) {
	auto tp = generateRandomTrackpoint();
	td.average_time += tp.time;
	td.trackpoint_data.push_back(tp);
	ss << tp.trackpoint << std::endl;
  }

  ss << "        </Track>\n";
  td.track = ss.str();
  td.average_time = td.average_time / td.trackpoint_data_size;

  return td;
}
