#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by Riccardo Petraglia on 10.07.21.
//

#include<gtest/gtest.h>
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
    sus = gar_edit::Position(node);
  }

  void TearDown() override {}

  gar_edit::Position sus;
  pugi::xml_node node; // if this is inside the SetUp it gets destroyed at the end of the setup.
  std::string latitude = "46.643460458144546";
  std::string longitude = "7.241974733769894";
};

TEST_F(PositionF, ShouldReturnLatitude)
{
  ASSERT_EQ(sus.latitude(), std::strtold(latitude.c_str(), nullptr));
}

TEST_F(PositionF, ShouldReturnLongitude)
{
  ASSERT_EQ(sus.longitude(), std::strtold(longitude.c_str(), nullptr));
}

TEST_F(PositionF, CheckStringOutput)
{
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


#ifdef ASD
template <typename E>  // E is the element type.
class Queue {
 public:
  Queue()= default;;
  void Enqueue(const E& element){};
  E* Dequeue(){};  // Returns NULL if the queue is empty.
  [[nodiscard]] size_t size() const{return 2; }
};

 class QueueTest : public ::testing::Test {
  protected:
   void SetUp() override {
     q1_.Enqueue(1);
     q2_.Enqueue(2);
     q2_.Enqueue(3);
   }

   Queue<int> q0_;
   Queue<int> q1_;
   Queue<int> q2_;
};

TEST_F(QueueTest, IsEmptyInitially) {
  EXPECT_EQ(q0_.size(), 0);
}

TEST_F(QueueTest, DequeueWorks) {
  int* n = q0_.Dequeue();
  EXPECT_EQ(n, nullptr);

  n = q1_.Dequeue();
  ASSERT_NE(n, nullptr);
  EXPECT_EQ(*n, 1);
  EXPECT_EQ(q1_.size(), 0);
  delete n;

  n = q2_.Dequeue();
  ASSERT_NE(n, nullptr);
  EXPECT_EQ(*n, 2);
  EXPECT_EQ(q2_.size(), 1);
  delete n;
}
#endif

// class PrefixTest : public ::testing::Test {
//  protected:
//  void SetUp() override {
//    k = 1;
//  }
//  int k;
//};
//
//TEST_F(PrefixTest, GoBackNumber) {
//  ASSERT_TRUE( k == 1);
//}