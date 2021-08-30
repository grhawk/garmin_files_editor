#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by Riccardo Petraglia on 10.07.21.
//

#include<gtest/gtest.h>
#include<string>

#include "garmin_files_editor/tcx/models/Position.h"
#include "test_helper_functions.h"

class PositionF : public ::testing::Test {
 protected:
  void SetUp() override {

    parse_result = doc.load_buffer(pd.position.c_str(), pd.position.size());
    ASSERT_TRUE(parse_result);

    node = doc.root().child("Position");
  }

  void TearDown() override {}

  pugi::xml_document doc;
  pugi::xml_parse_result parse_result;
  pugi::xml_node node; // if this is inside the SetUp it gets destroyed at the end of the setup.
  gar_edit::test_helpers::positionData pd = gar_edit::test_helpers::generateRandomPosition();
};

TEST_F(PositionF, ShouldReturnLatitude)
{
  auto sus = gar_edit::Position(node);
  ASSERT_EQ(sus.latitude(), pd.latitude);
}

TEST_F(PositionF, ShouldReturnLongitude)
{
  auto sus = gar_edit::Position(node);
  ASSERT_EQ(sus.longitude(), pd.longitude);
}

TEST_F(PositionF, ShouldReturnBothLongAndLat)
{
  auto sus = gar_edit::Position(node);
  ASSERT_EQ(sus.latitude(), pd.latitude);
  ASSERT_EQ(sus.longitude(), pd.longitude);
}

TEST_F(PositionF, CheckStringOutput)
{
  auto sus = gar_edit::Position(node);
  std::stringstream expected_string;
  expected_string << std::setprecision(21);
  expected_string << "<Position>{lat: " << pd.latitude << " - long: " << pd.longitude << "}";
  ASSERT_EQ(sus.str(), expected_string.str());
}

TEST_F(PositionF, CheckXMLNode)
{
  ASSERT_EQ(std::stold(node.child_value("LatitudeDegrees")), pd.latitude);
  ASSERT_EQ(std::stold(node.child_value("LongitudeDegrees")), pd.longitude);
}

#pragma clang diagnostic pop
