#include "gtest/gtest.h"
#include "day08.h"



TEST(Day08, Day08_A_1) {
	std::istringstream ss(
		"2 3 0 3 10 11 12 1 1 0 1 99 2 1 1 2"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(138, aoc2018_08::getMetadataSum(input));
}


TEST(Day08, Day08_B_1) {
	std::istringstream ss(
		"2 3 0 3 10 11 12 1 1 0 1 99 2 1 1 2"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(66, aoc2018_08::getMetadataValue(input));
}
