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

class TrackpointF : public ::testing::Test {
 protected:
  void SetUp() override {
    std::stringstream position_node_xml;
    position_node_xml <<
                      "          <Trackpoint>\n"
                      "            <Time>"
                      << time_ <<
                      "            </Time>\n"
                      "            <Position>\n"
                      "              <LatitudeDegrees>"
                      << latitude_ <<
                      "              </LatitudeDegrees>\n"
                      "              <LongitudeDegrees>"
                      << longitude_ <<
                      "              </LongitudeDegrees>\n"
                      "            </Position>\n"
                      "            <HeartRateBpm>\n"
                      "              <Value>"
                      << hbpm_ <<
                      "              </Value>\n"
                      "            </HeartRateBpm>\n"
                      "            <Extensions>\n"
                      "              <ns3:TPX>\n"
                      "                <ns3:Speed>"
                      << speed_ <<
                      "                </ns3:Speed>\n"
                      "              </ns3:TPX>\n"
                      "            </Extensions>\n"
                      "            <AltitudeMeters>"
                      << altimeter_ <<
                      "            </AltitudeMeters>\n"
                      "            <DistanceMeters>"
                      << distance_ <<
                      "            </DistanceMeters>"
                      "          </Trackpoint>";

    pugi::xml_document doc;
    pugi::xml_parse_result parse_result = doc.load_buffer(position_node_xml.str().c_str(),
                                                          position_node_xml.str().size());
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

  pugi::xml_node node; // if this is inside the SetUp it gets destroyed at the end of the setup.
  std::string latitude_ = generateRandomLongDoubleWithIn(0.0l, 90.0l);
  std::string longitude_ = generateRandomLongDoubleWithIn(0.0l, 180.0l);
  std::string hbpm_ = generateRandomIntegerWithIn(20, 250);
  std::string speed_ = generateRandomLongDoubleWithIn(0.0l, 180.0l);
  std::string altimeter_ = generateRandomLongDoubleWithIn(0.0l, 12000.0l);
  std::string distance_ = generateRandomLongDoubleWithIn(0.0l, 180.0l);
  std::string time_ = "2021-06-12T10:49:41.000Z";
};

TEST_F(TrackpointF, CheckPositionValue)
{
  auto sus = gar_edit::Trackpoint(node);
  ASSERT_EQ(sus.position()->latitude(),  std::stold(latitude_));
  ASSERT_EQ(sus.position()->longitude(), std::stold(longitude_));
}

TEST_F(TrackpointF, ShouldRetureHeartRate)
{
  auto sus = gar_edit::Trackpoint(node);
  ASSERT_EQ(sus.hbpm(), std::stoi(hbpm_));
}

TEST_F(TrackpointF, ShouldReturnSpeed)
{
  auto sus = gar_edit::Trackpoint(node);
  ASSERT_EQ(sus.speed(), std::stold(speed_));
}

TEST_F(TrackpointF, ShouldReturnDistance)
{
  auto sus = gar_edit::Trackpoint(node);
  ASSERT_EQ(sus.distance(), std::stold(distance_));
}

TEST_F(TrackpointF, shouldReturnTime)
{
  auto sus = gar_edit::Trackpoint(node);
  ASSERT_EQ(sus.time(), 1623491381L);
}

TEST_F(TrackpointF, shouldThrowException_TimeIsInWrongFormat)
{
  node.child("Time").text().set("apppero");
  auto sus = gar_edit::Trackpoint(node);
  ASSERT_THROW(sus.time(), std::runtime_error);
}

#pragma clang diagnostic pop