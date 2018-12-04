#include "gtest/gtest.h"
#include "day03.h"


TEST(Day03, getCoord) {
	EXPECT_EQ(std::make_pair(1, 2), aoc2018_03::getCoord("1,2:"));
	EXPECT_EQ(std::make_pair(1, 2), aoc2018_03::getCoord("1x2"));
	EXPECT_EQ(std::make_pair(1234, 5678), aoc2018_03::getCoord("1234,5678:"));
	EXPECT_EQ(std::make_pair(1234, 5678), aoc2018_03::getCoord("1234x5678:"));
}

TEST(Day03, Day03_AB_1) {
	std::istringstream ss(
		"#1 @ 1,3: 4x4\n"
		"#2 @ 3,1: 4x4\n"
		"#3 @ 5,5: 2x2\n"
//		"#4 @ 3,3: 2x2\n"
	);
	auto	input = aoc2018::ReadInput(ss);
	auto	res = aoc2018_03::calcOverlaps(input);
	EXPECT_EQ(4, res.first);
	EXPECT_EQ(3, res.second);
}
