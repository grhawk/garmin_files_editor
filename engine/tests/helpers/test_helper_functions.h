//
// Created by Riccardo Petraglia on 29.08.21.
//

#ifndef GARMIN_FILES_EDITOR_ENGINE_TESTS_HELPERS_TEST_HELPER_FUNCTIONS_H_
#define GARMIN_FILES_EDITOR_ENGINE_TESTS_HELPERS_TEST_HELPER_FUNCTIONS_H_

#include <random>
#include <string>
#include <iomanip>
#include <sstream>
#include <chrono>
#include "garmin_files_editor/tcx/models/types.h"


namespace gar_edit::test_helpers {

long double generateRandomLongDoubleWithIn(const long double& lower_bound, const long double& upper_bound);

long int generateRandomIntegerWithIn(const int& lower_bound, const int& upper_bound);

std::string timeToString(std::time_t epoch);

struct positionData {
  positionData() : latitude{0}, longitude{0}{}
  positionData(gar_edit::Coordinate latitude, gar_edit::Coordinate longitude) : latitude{latitude},
                                                                                longitude{longitude}{}
  gar_edit::Coordinate latitude;
  gar_edit::Coordinate longitude;

  std::string position;
};

struct trackpointData {
  trackpointData() : time{0}, position_data{positionData()}, altitude{0}, distance{0}, hbpm{0}, speed{0}, trackpoint{0}{}
  long time;
  positionData position_data;
  gar_edit::Altitude altitude;
  gar_edit::Distance distance;
  gar_edit::Hbpm hbpm;
  gar_edit::Speed speed;

  std::string trackpoint;
};

void generatePosition(positionData& pd);

void generateTrackpoint(trackpointData& tcd);

[[nodiscard]] positionData generateRandomPosition();

[[nodiscard]] trackpointData generateRandomTrackpoint();

}

#endif //GARMIN_FILES_EDITOR_ENGINE_TESTS_HELPERS_TEST_HELPER_FUNCTIONS_H_
