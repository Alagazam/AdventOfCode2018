#include "gtest/gtest.h"
#include "day04.h"


TEST(Day04, sortRows) {
	std::istringstream ss(
		"[1518-11-05 00:45] falls asleep\n"
		"[1518-11-01 00:00] Guard #10 begins shift\n"
		"[1518-11-01 00:05] falls asleep\n"
	);
	auto	input = aoc2018::ReadInput(ss);
	aoc2018_04::sortRows(input);
	EXPECT_EQ("[1518-11-01", input[0][0]);
	EXPECT_EQ("00:00]", input[0][1]);
	EXPECT_EQ("[1518-11-05", input[2][0]);
	EXPECT_EQ("00:45]", input[2][1]);
}

TEST(Day04, Day04_A_1_trivial) {
	std::istringstream ss(
		"[1518-11-01 00:00] Guard #10 begins shift\n"
		"[1518-11-01 00:05] falls asleep\n"
		"[1518-11-01 00:06] wakes up\n");
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(10*5, aoc2018_04::getBestGuard(input));
}

TEST(Day04, Day04_A_1) {
	std::istringstream ss(
		"[1518-11-01 00:00] Guard #10 begins shift\n"
		"[1518-11-01 00:05] falls asleep\n"
		"[1518-11-01 00:55] wakes up\n"
		"[1518-11-05 00:45] falls asleep\n"
		"[1518-11-03 00:29] wakes up\n"
		"[1518-11-04 00:02] Guard #99 begins shift\n"
		"[1518-11-01 23:58] Guard #99 begins shift\n"
		"[1518-11-02 00:40] falls asleep\n"
		"[1518-11-02 00:50] wakes up\n"
		"[1518-11-03 00:05] Guard #10 begins shift\n"
		"[1518-11-01 00:25] wakes up\n"
		"[1518-11-01 00:30] falls asleep\n"
		"[1518-11-03 00:24] falls asleep\n"
		"[1518-11-04 00:36] falls asleep\n"
		"[1518-11-04 00:46] wakes up\n"
		"[1518-11-05 00:03] Guard #99 begins shift\n"
		"[1518-11-05 00:55] wakes up\n");
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(240, aoc2018_04::getBestGuard(input));
}
