#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by Riccardo Petraglia on 10.07.21.
//

#include<gtest/gtest.h>
#include<string>

#include "garmin_files_editor/tcx/models/Position.h"

class PositionF : public ::testing::Test {
 protected:
  void SetUp() override {
    std::string position_node_xml = "<Position attr='attr'><LatitudeDegrees>";
    position_node_xml.append(latitude);
    position_node_xml.append("</LatitudeDegrees><LongitudeDegrees>");
    position_node_xml.append(longitude);
    position_node_xml.append("</LongitudeDegrees></Position>");

    pugi::xml_document doc;
    pugi::xml_parse_result parse_result = doc.load_buffer(position_node_xml.c_str(), position_node_xml.size());
    ASSERT_TRUE(parse_result);

    node = doc.root().child("Position");
  }

  void TearDown() override {}

  pugi::xml_node node; // if this is inside the SetUp it gets destroyed at the end of the setup.
  std::string latitude = "46.643460458144546";
  std::string longitude = "7.241974733769894";
};

TEST_F(PositionF, ShouldReturnLatitude)
{
  auto sus = gar_edit::Position(node);
  ASSERT_EQ(sus.latitude(), std::stold(latitude));
}

TEST_F(PositionF, ShouldReturnLongitude)
{
  auto sus = gar_edit::Position(node);
  ASSERT_EQ(sus.longitude(), std::stold(longitude));
}

TEST_F(PositionF, ShouldReturnBothLongAndLat)
{
  auto sus = gar_edit::Position(node);
  ASSERT_EQ(sus.latitude(), std::stold(latitude));
  ASSERT_EQ(sus.longitude(), std::stold(longitude));
}

TEST_F(PositionF, CheckStringOutput)
{
  auto sus = gar_edit::Position(node);
  std::stringstream expected_string;
  expected_string << "<Position>{lat: " << latitude << " - long: " << longitude << "}";
  ASSERT_EQ(sus.str(), expected_string.str());
}

TEST_F(PositionF, CheckXMLNode)
{
  ASSERT_STREQ(node.child_value("LatitudeDegrees"), latitude.c_str());
  ASSERT_STREQ(node.child_value("LongitudeDegrees"), longitude.c_str());
}

#pragma clang diagnostic pop
