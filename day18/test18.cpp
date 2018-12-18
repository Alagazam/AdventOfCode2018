#include "gtest/gtest.h"
#include "day18.h"



TEST(Day18, calcResourceValue) {
	std::istringstream ss(	// end result
		"||||||||||\n"
		".||##.....\n"
		"||###.....\n"
		"||##......\n"
		"|##.....##\n"
		"|##.....##\n"
		"|##....##|\n"
		"||##.####|\n"
		"||#####|||\n"
		"||||#|||||\n"
	);
	auto	input = aoc2018::ReadInputLines(ss);
	EXPECT_EQ(1147, aoc2018_18::calcResourceValue(input));
}

TEST(Day18, develop) {
	std::istringstream ss(
		".#.#...|#.\n"
		".....#|##|\n"
		".|..|...#.\n"
		"..|#.....#\n"
		"#.#|||#|#|\n"
		"...#.||...\n"
		".|....|...\n"
		"||...#|.#|\n"
		"|.||||..|.\n"
		"...#.|..|.\n"
	);
	auto	input = aoc2018::ReadInputLines(ss);

	std::istringstream ssRes(
		".......##.\n"
		"......|###\n"
		".|..|...#.\n"
		"..|#||...#\n"
		"..##||.|#|\n"
		"...#||||..\n"
		"||...|||..\n"
		"|||||.||.|\n"
		"||||||||||\n"
		"....||..|.\n"
	);
	auto	res = aoc2018::ReadInputLines(ssRes);
	EXPECT_EQ(res, aoc2018_18::develop(input));
}

TEST(Day18, Day18_A_1) {
	std::istringstream ss(
		".#.#...|#.\n"
		".....#|##|\n"
		".|..|...#.\n"
		"..|#.....#\n"
		"#.#|||#|#|\n"
		"...#.||...\n"
		".|....|...\n"
		"||...#|.#|\n"
		"|.||||..|.\n"
		"...#.|..|.\n"
	);
	auto	input = aoc2018::ReadInputLines(ss);
	EXPECT_EQ(1147, aoc2018_18::developAndCountResources(input, 10));
}

TEST(Day18, Day18_B_1) {
	auto	file = aoc2018::OpenInputFile("day18.txt");
	auto	input = aoc2018::ReadInputLines(*file);
	EXPECT_EQ(201335, aoc2018_18::developAndCountResourcesFindingLoops(input, 2000));
}
