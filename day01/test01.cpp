#include "gtest/gtest.h"
#include "day01.h"

TEST(Day01, Day01_A_1) {
	std::istringstream ss("+1\n-2\n+3\n+1");
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(3, aoc2018_01::SumFreq(input));
}
TEST(Day01, Day01_A_2) {
	std::istringstream ss("+1\r\n+1\r\n+1");
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(3, aoc2018_01::SumFreq(input));
}
TEST(Day01, Day01_A_3) {
	std::istringstream ss("+1\n+1\n-2");
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(0, aoc2018_01::SumFreq(input));
}
TEST(Day01, Day01_A_4) {
	std::istringstream ss("-1\n-2\n-3");
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(-6, aoc2018_01::SumFreq(input));
}

TEST(Day01, Day01_B_1) {
	std::istringstream ss("+1\n-2\n+3\n+1");
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(2, aoc2018_01::FirstRepeat(input));
}
TEST(Day01, Day01_B_2) {
	std::istringstream ss("+1\n-1");
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(0, aoc2018_01::FirstRepeat(input));
}
TEST(Day01, Day01_B_3) {
	std::istringstream ss("+3\n+3\n+4\n-2\n-4");
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(10, aoc2018_01::FirstRepeat(input));
}
TEST(Day01, Day01_B_4) {
	std::istringstream ss("-6\n+3\n+8\n+5\n-6");
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(5, aoc2018_01::FirstRepeat(input));
}
TEST(Day01, Day01_B_5) {
	std::istringstream ss("+7\n+7\n-2\n-7\n-4");
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(14, aoc2018_01::FirstRepeat(input));
}
