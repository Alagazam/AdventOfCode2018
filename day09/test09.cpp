#include "gtest/gtest.h"
#include "day09.h"



TEST(Day09, Day09_A_0) {
	std::istringstream ss(
		"9 players; last marble is worth 25 points"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(32, aoc2018_09::play(input));
}
TEST(Day09, Day09_A_1) {
	std::istringstream ss(
		"10 players; last marble is worth 1618 points"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(8317, aoc2018_09::play(input));
}

TEST(Day09, Day09_A_2) {
	std::istringstream ss(
		"13 players; last marble is worth 7999 points"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(146373, aoc2018_09::play(input));
}
TEST(Day09, Day09_A_3) {
	std::istringstream ss(
		"17 players; last marble is worth 1104 points"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(2764, aoc2018_09::play(input));
}
TEST(Day09, Day09_A_4) {
	std::istringstream ss(
		"21 players; last marble is worth 6111 points"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(54718, aoc2018_09::play(input));
}
TEST(Day09, Day09_A_5) {
	std::istringstream ss(
		"30 players; last marble is worth 5807 points"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(37305, aoc2018_09::play(input));
}

