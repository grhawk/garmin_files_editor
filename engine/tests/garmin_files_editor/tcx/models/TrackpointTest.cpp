#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by Riccardo Petraglia on 01.08.21.
//

#include <gtest/gtest.h>
#include <pugixml.hpp>
#include <random>
#include <chrono>

#include "garmin_files_editor/tcx/models/Trackpoint.h"

#include <test_helper_functions.h>

class TrackpointF : public ::testing::Test {
 protected:
  void SetUp() override {
    parse_result = doc.load_buffer(tpd_.trackpoint.c_str(),
                                   tpd_.trackpoint.size());
    ASSERT_TRUE(parse_result);

    node = doc.root().child("Trackpoint");
  }

  static std::string generateRandomLongDoubleWithIn(long double lower_bound, long double upper_bound) {
    std::uniform_real_distribution<long double> unif(lower_bound, upper_bound);
    std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
    return std::to_string(unif(re));
  }

  static std::string generateRandomIntegerWithIn(int lower_bound, int upper_bound) {
    return std::to_string(std::stoi(generateRandomLongDoubleWithIn(std::stold(std::to_string(lower_bound)),
                                                                   std::stold(std::to_string(upper_bound)))));
  }

  void TearDown() override {}

  pugi::xml_document doc;
  pugi::xml_parse_result parse_result;
  gar_edit::test_helpers::trackpointData tpd_ = gar_edit::test_helpers::generateRandomTrackpoint();
  pugi::xml_node node; // if this is inside the SetUp it gets destroyed at the end of the setup.
};

TEST_F(TrackpointF, CheckPositionValue)
{
  auto sus = gar_edit::Trackpoint(node);
  ASSERT_EQ(sus.position()->latitude(), tpd_.position_data.latitude);
  ASSERT_EQ(sus.position()->longitude(), tpd_.position_data.longitude);
}

TEST_F(TrackpointF, ShouldRetureHeartRate)
{
  auto sus = gar_edit::Trackpoint(node);
  ASSERT_EQ(sus.hbpm(), tpd_.hbpm);
}

TEST_F(TrackpointF, ShouldReturnSpeed)
{
  auto sus = gar_edit::Trackpoint(node);
  ASSERT_EQ(sus.speed(), tpd_.speed);
}

TEST_F(TrackpointF, ShouldReturnDistance)
{
  auto sus = gar_edit::Trackpoint(node);
  ASSERT_EQ(sus.distance(), tpd_.distance);
}

TEST_F(TrackpointF, shouldReturnTime)
{
  std::cout << "XML:" << std::endl << tpd_.trackpoint << std::endl;
  auto sus = gar_edit::Trackpoint(node);
  std::cout << "DIFFERENCE: " << sus.time() - tpd_.time << std::endl;
  ASSERT_EQ(sus.time(), tpd_.time);
}

TEST_F(TrackpointF, shouldThrowException_TimeIsInWrongFormat)
{
  node.child("Time").text().set("apppero");
  auto sus = gar_edit::Trackpoint(node);
  ASSERT_THROW(sus.time(), std::runtime_error);
}

#pragma clang diagnostic pop