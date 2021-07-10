#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by Riccardo Petraglia on 10.07.21.
//

#include<gtest/gtest.h>
#include "garmin_files_editor/tcx/models/Position.h"

class PositionF : public ::testing::Test {
 protected:
  coordinate latitude = 1.2;
  coordinate longitude = 2.1;
  gar_edit::Position sus;
  PositionF() : sus{
      gar_edit::Position(latitude,
                         longitude)}
  {}
};


TEST_F(PositionF, CheckStringOutput)
{
  std::stringstream expected_string;
  expected_string << "<Position>{lat: " << latitude << " - long: " << longitude << "}";
  ASSERT_EQ(sus.str(), expected_string.str());
}

TEST_F(PositionF, ShouldReturnLatitude)
{
  ASSERT_EQ(sus.latitude(), latitude);
}

TEST_F(PositionF, ShouldReturnLongitude)
{
  ASSERT_EQ(sus.longitude(), longitude);
}

#pragma clang diagnostic pop