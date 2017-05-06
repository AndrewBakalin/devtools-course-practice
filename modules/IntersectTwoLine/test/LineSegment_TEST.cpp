// Copyright 2017 Lobanov Andrey

#include "include/LineSegment.h"
#include <string>
#include <gtest/gtest.h>

using std::string;

TEST(LineSegment, Can_Create_LineSegment_With_Initial_Values) {
  ASSERT_NO_THROW(LineSegment2D line(2.0, 3.1, 4.2));
}

TEST(LineSegment, Can_Set_Initial_A_Value) {
  LineSegment2D line(0, 0, 0);
  ASSERT_NO_THROW(line.Set_A(3.3));
}

TEST(LineSegment, Can_Set_Initial_B_Value) {
  LineSegment2D line(0, 0, 0);
  ASSERT_NO_THROW(line.Set_B(3.3));
}

TEST(LineSegment, Can_Set_Initial_C_Value) {
  LineSegment2D line(0, 0, 0);
  ASSERT_NO_THROW(line.Set_C(3.3));
}

TEST(LineSegment, Can_Get_A_Value) {
  LineSegment2D line(-3.0, -4.0, 5.0);
  EXPECT_EQ(-3.0, line.Get_A());
}

TEST(LineSegment, Can_Get_B_Value) {
  LineSegment2D line(-3.0, -4.0, 5.0);
  EXPECT_EQ(-4.0, line.Get_B());
}

TEST(LineSegment, Can_Get_C_Value) {
  LineSegment2D line(-3.0, -4.0, 5.0);
  EXPECT_EQ(5.0, line.Get_C());
}

TEST(LineSegment, Set_Initial_Value_Work_Correctly) {
  LineSegment2D line(0, 0, 0);
  line.Set_A(1.1);
  line.Set_B(10.3);
  line.Set_C(-3.5);
  EXPECT_TRUE((1.1 == line.Get_A()) &&
             (10.3 == line.Get_B()) &&
             (-3.5 == line.Get_C()));
}

TEST(LineSegmentFunction, Show_That_Lines_Are_Coincide) {
  string str = "Lines are coincide";
  LineSegment2D line(2.0, 3.1, 4.2);
  LineSegment2D line1(4.0, 6.2, 8.4);
  ASSERT_EQ(str, line.checkIntersection(line1));
}

TEST(LineSegment, Show_That_Lines_Are_Parallel) {
  string str = "Lines are parallel";
  LineSegment2D line(2.0, 3.1, 4.2);
  LineSegment2D line1(4.0, 6.2, 1.4);
  ASSERT_EQ(str, line.checkIntersection(line1));
}

TEST(LineSegment, Can_Create_Point_Intersect_Two_LineSegment) {
  LineSegment2D line(2.0, 3.1, 4.2);
  LineSegment2D line1(4.0, 3.2, 1.4);
  ASSERT_NO_THROW(line.checkIntersection(line1));
}

TEST(LineSegment, Show_Point_Intersect_Two_LineSegment) {
  string str = "Intersection point: (-4.73866; 2.61343)";
  LineSegment2D line(8.2, 10.2, 12.2);
  LineSegment2D line1(3.1, 5.2, 1.1);
  EXPECT_EQ(str, line.checkIntersection(line1));
}
