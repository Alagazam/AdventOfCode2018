#include "gtest/gtest.h"
#include "day05.h"

TEST(Day05, Day05_A_1) {
	std::istringstream ss(
		"aA"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(0, aoc2018_05::reducePolymer(input));
}
TEST(Day05, Day05_A_2) {
	std::istringstream ss(
		"abBA"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(0, aoc2018_05::reducePolymer(input));
}
TEST(Day05, Day05_A_3) {
	std::istringstream ss(
		"abAB"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(4, aoc2018_05::reducePolymer(input));
}
TEST(Day05, Day05_A_4) {
	std::istringstream ss(
		"aabAAB"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(6, aoc2018_05::reducePolymer(input));
}
TEST(Day05, Day05_A_5) {
	std::istringstream ss(
		"dabAcCaCBAcCcaDA"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(10, aoc2018_05::reducePolymer(input));
}
