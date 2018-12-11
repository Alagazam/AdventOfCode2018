#include "gtest/gtest.h"
#include "day07.h"



TEST(Day07, Day07_A_1) {
	std::istringstream ss(
		"Step C must be finished before step A can begin.\n"
		"Step C must be finished before step F can begin.\n"
		"Step A must be finished before step B can begin.\n"
		"Step A must be finished before step D can begin.\n"
		"Step B must be finished before step E can begin.\n"
		"Step D must be finished before step E can begin.\n"
		"Step F must be finished before step E can begin.\n"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ("CABDFE", aoc2018_07::buildOrder(input));
}


TEST(Day07, Day07_B_1) {
	std::istringstream ss(
		"Step C must be finished before step A can begin.\n"
		"Step C must be finished before step F can begin.\n"
		"Step A must be finished before step B can begin.\n"
		"Step A must be finished before step D can begin.\n"
		"Step B must be finished before step E can begin.\n"
		"Step D must be finished before step E can begin.\n"
		"Step F must be finished before step E can begin.\n"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(15, aoc2018_07::build(input, 2, 0));
}
