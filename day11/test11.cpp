#include "gtest/gtest.h"
#include "day11.h"



TEST(Day11, power) {
	EXPECT_EQ(4, aoc2018_11::power(8, 3, 5));
	//Fuel cell at  122,79, grid serial number 57: power level -5.
	//Fuel cell at 217,196, grid serial number 39: power level  0.
	//Fuel cell at 101,153, grid serial number 71: power level  4.
	EXPECT_EQ(-5, aoc2018_11::power(57, 122, 79));
	EXPECT_EQ(0, aoc2018_11::power(39, 217, 196));
	EXPECT_EQ(4, aoc2018_11::power(71, 101, 153));
}
TEST(Day11, Day11_A_1) {
	EXPECT_EQ(std::make_pair(33, 45), aoc2018_11::bestSubGrid(18));
}
TEST(Day11, Day11_A_2) {
	EXPECT_EQ(std::make_pair(21, 61), aoc2018_11::bestSubGrid(42));
}
