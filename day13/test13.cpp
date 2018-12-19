#include "gtest/gtest.h"
#include "day13.h"



TEST(Day13, findCarts) {
	std::istringstream ss(
		"|\n"
		"v\n"
		"|\n"
		"|\n"
		"|\n"
		"^\n"
		"|\n"
	);
	auto	input = aoc2018::ReadInputLines(ss);
	EXPECT_EQ(2, aoc2018_13::findCarts(input).size());
	EXPECT_EQ('|', input[1][0]);
	EXPECT_EQ('|', input[5][0]);
}
TEST(Day13, findCarts2) {
	std::istringstream ss(
		"/->-\\        \n"
		"|   |  /----\\\n"
		"| /-+--+-\\  |\n"
		"| | |  | v  |\n"
		"\\-+-/  \\-+--/\n"
		"  \\------/   \n"
	);
	auto	input = aoc2018::ReadInputLines(ss);
	auto carts = aoc2018_13::findCarts(input);
	EXPECT_EQ(2, carts.size());
	EXPECT_EQ(2, carts[0].x);
	EXPECT_EQ(0, carts[0].y);
	EXPECT_EQ(1, carts[0].dx);
	EXPECT_EQ(0, carts[0].dy);
}


TEST(Day13, Day13_A_1) {
	std::istringstream ss(
		"|\n"
		"v\n"
		"|\n"
		"|\n"
		"|\n"
		"^\n"
		"|\n"
	);
	auto	input = aoc2018::ReadInputLines(ss);
	EXPECT_EQ("0,3", aoc2018_13::findFirstCrash(input));
}

TEST(Day13, Day13_A_2) {
	std::istringstream ss(
		"/->-\\        \n"
		"|   |  /----\\\n"
		"| /-+--+-\\  |\n"
		"| | |  | v  |\n"
		"\\-+-/  \\-+--/\n"
		"  \\------/   \n"
	);
	auto	input = aoc2018::ReadInputLines(ss);
	EXPECT_EQ("7,3", aoc2018_13::findFirstCrash(input));
}
