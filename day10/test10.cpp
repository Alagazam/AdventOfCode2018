#include "gtest/gtest.h"
#include "day10.h"


TEST(Day10, StarParse)
{
	aoc2018_10::Star s1("position=< 9,  1> velocity=< 0,  2>");
	EXPECT_EQ(9, s1.x);
	EXPECT_EQ(1, s1.y);
	EXPECT_EQ(0, s1.dx);
	EXPECT_EQ(2, s1.dy);
	aoc2018_10::Star s2("position=<-6, 10> velocity=< 2, -2>");
	EXPECT_EQ(-6, s2.x);
	EXPECT_EQ(10, s2.y);
	EXPECT_EQ(2, s2.dx);
	EXPECT_EQ(-2, s2.dy);
	
	aoc2018_10::Star s3("position=<-19978,  30411> velocity=<-2, -3>");
	EXPECT_EQ(-19978, s3.x);
	EXPECT_EQ(30411, s3.y);
	EXPECT_EQ(-2, s3.dx);
	EXPECT_EQ(-3, s3.dy);
}

TEST(Day10, Day10_AB_1) {
	std::istringstream ss(
		"position=< 9,  1> velocity=< 0,  2>\n"
		"position=< 7,  0> velocity=<-1,  0>\n"
		"position=< 3, -2> velocity=<-1,  1>\n"
		"position=< 6, 10> velocity=<-2, -1>\n"
		"position=< 2, -4> velocity=< 2,  2>\n"
		"position=<-6, 10> velocity=< 2, -2>\n"
		"position=< 1,  8> velocity=< 1, -1>\n"
		"position=< 1,  7> velocity=< 1,  0>\n"
		"position=<-3, 11> velocity=< 1, -2>\n"
		"position=< 7,  6> velocity=<-1, -1>\n"
		"position=<-2,  3> velocity=< 1,  0>\n"
		"position=<-4,  3> velocity=< 2,  0>\n"
		"position=<10, -3> velocity=<-1,  1>\n"
		"position=< 5, 11> velocity=< 1, -2>\n"
		"position=< 4,  7> velocity=< 0, -1>\n"
		"position=< 8, -2> velocity=< 0,  1>\n"
		"position=<15,  0> velocity=<-2,  0>\n"
		"position=< 1,  6> velocity=< 1,  0>\n"
		"position=< 8,  9> velocity=< 0, -1>\n"
		"position=< 3,  3> velocity=<-1,  1>\n"
		"position=< 0,  5> velocity=< 0, -1>\n"
		"position=<-2,  2> velocity=< 2,  0>\n"
		"position=< 5, -2> velocity=< 1,  2>\n"
		"position=< 1,  4> velocity=< 2,  1>\n"
		"position=<-2,  7> velocity=< 2, -2>\n"
		"position=< 3,  6> velocity=<-1, -1>\n"
		"position=< 5,  0> velocity=< 1,  0>\n"
		"position=<-6,  0> velocity=< 2,  0>\n"
		"position=< 5,  9> velocity=< 1, -2>\n"
		"position=<14,  7> velocity=<-2,  0>\n"
		"position=<-3,  6> velocity=< 2, -1>\n"
	);
	auto	input = aoc2018::ReadInputLines(ss);
	EXPECT_EQ(3, aoc2018_10::alignStars(input, 7));
}
