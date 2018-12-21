#include "gtest/gtest.h"
#include "day16.h"

TEST(Day16, parseState) {
	std::istringstream ss(
		"Before: [3, 2, 1, 1]\n"
		"9 2 1 2\n"
		"After:  [3, 2, 2, 1]\n"
	);
	auto	input = aoc2018::ReadInput(ss);
	aoc2018_16::state_t	expect{ 3,2,1,1 };
	EXPECT_EQ(expect, aoc2018_16::parseState(input[0]));
}
TEST(Day16, parseInstruction) {
	std::istringstream ss(
		"Before: [3, 2, 1, 1]\n"
		"9 2 1 2\n"
		"After:  [3, 2, 2, 1]\n"
	);
	auto	input = aoc2018::ReadInput(ss);
	aoc2018_16::instruction_t	expect{ 9,2,1,2 };
	auto	result = aoc2018_16::parseInstruction(input[1]);
	EXPECT_EQ(expect.operation, result.operation);
	EXPECT_EQ(expect.opA, result.opA);
	EXPECT_EQ(expect.opB, result.opB);
	EXPECT_EQ(expect.opC, result.opC);
}


TEST(Day16, Day16_A_1) {
	std::istringstream ss(
		"Before: [3, 2, 1, 1]\n"
		"9 2 1 2\n"
		"After:  [3, 2, 2, 1]\n"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(1, aoc2018_16::opCodesBeahveLikeThreeOrMore(input));
}
