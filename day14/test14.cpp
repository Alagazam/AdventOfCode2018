#include "gtest/gtest.h"
#include "day14.h"


TEST(Day14, Day14_A_1) {
	std::istringstream ss(
		"9"
	);
	auto	input = aoc2018::ReadInputLines(ss);
	EXPECT_EQ("5158916779", aoc2018_14::score(input));
}

TEST(Day14, Day14_A_2) {
	std::istringstream ss(
		"5"
	);
	auto	input = aoc2018::ReadInputLines(ss);
	EXPECT_EQ("0124515891", aoc2018_14::score(input));
}
TEST(Day14, Day14_A_3) {
	std::istringstream ss(
		"18"
	);
	auto	input = aoc2018::ReadInputLines(ss);
	EXPECT_EQ("9251071085", aoc2018_14::score(input));
}
TEST(Day14, Day14_A_4) {
	std::istringstream ss(
		"2018"
	);
	auto	input = aoc2018::ReadInputLines(ss);
	EXPECT_EQ("5941429882", aoc2018_14::score(input));
}

TEST(Day14, Day14_B_1) {
	std::istringstream ss(
		"51589"
	);
	auto	input = aoc2018::ReadInputLines(ss);
	EXPECT_EQ(9, aoc2018_14::skippedRecepies(input));
}

TEST(Day14, Day14_B_2) {
	std::istringstream ss(
		"01245"
	);
	auto	input = aoc2018::ReadInputLines(ss);
	EXPECT_EQ(5, aoc2018_14::skippedRecepies(input));
}
TEST(Day14, Day14_B_3) {
	std::istringstream ss(
		"92510"
	);
	auto	input = aoc2018::ReadInputLines(ss);
	EXPECT_EQ(18, aoc2018_14::skippedRecepies(input));
}
TEST(Day14, Day14_B_4) {
	std::istringstream ss(
		"59414"
	);
	auto	input = aoc2018::ReadInputLines(ss);
	EXPECT_EQ(2018, aoc2018_14::skippedRecepies(input));
}
TEST(Day14, Day14_B_5) {
	std::istringstream ss(
		"5891\n"
	);
	auto	input = aoc2018::ReadInputLines(ss);
	EXPECT_EQ(11, aoc2018_14::skippedRecepies(input));
}
