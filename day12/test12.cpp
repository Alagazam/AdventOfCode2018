#include "gtest/gtest.h"
#include "day12.h"


TEST(Day12, evolve0) {
	aoc2018_12::transitions_t trans;
	trans["..#.."] = '#';

	EXPECT_EQ("...#...", aoc2018_12::evolve("...#...", trans));
}
TEST(Day12, evolve1) {
	aoc2018_12::transitions_t trans;
	trans["..#.."] = '.';
	trans[".#..."] = '#';

	EXPECT_EQ("....#..", aoc2018_12::evolve("...#...", trans));
}
TEST(Day12, evolve2) {
	aoc2018_12::transitions_t trans;
	trans["..#.."] = '#';
	trans["....#"] = '#';
	trans["#...."] = '#';

	EXPECT_EQ("..#.#..#.#..", aoc2018_12::evolve("....#..#....", trans));
}

TEST(Day12, Day12_A_1) {
	std::istringstream ss(
		"initial state: #..#.#..##......###...###\n"
		"\n"
		"...## => #\n"
		"..#.. => #\n"
		".#... => #\n"
		".#.#. => #\n"
		".#.## => #\n"
		".##.. => #\n"
		".#### => #\n"
		"#.#.# => #\n"
		"#.### => #\n"
		"##.#. => #\n"
		"##.## => #\n"
		"###.. => #\n"
		"###.# => #\n"
		"####. => #\n"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(325, aoc2018_12::sumOfPlantPots(input));
}

