#include "gtest/gtest.h"
#include "day06.h"


TEST(Day06, Day06_updateplot) {
	aoc2018_06::grid_t	grid(10, std::vector<aoc2018_06::plot>(10));

	auto expanded = aoc2018_06::updatePlot(1, 3, 3, 0, grid);

	EXPECT_TRUE(expanded);
	EXPECT_EQ(1, grid[3][3].no);
}

TEST(Day06, Day06_expand_0) {
	aoc2018_06::grid_t	grid(10, std::vector<aoc2018_06::plot>(10));

	auto expanded = aoc2018_06::expand(1, 3, 3, 0, grid);

	EXPECT_TRUE(expanded);
	EXPECT_EQ(1, grid[3][3].no);
}

TEST(Day06, Day06_expand_1) {
	aoc2018_06::grid_t	grid(10, std::vector<aoc2018_06::plot>(10));

	auto expanded = aoc2018_06::expand(1, 3, 3, 1, grid);

	EXPECT_TRUE(expanded);
	EXPECT_EQ(0, grid[2][2].no);
	EXPECT_EQ(1, grid[2][3].no);
	EXPECT_EQ(0, grid[2][4].no);
	EXPECT_EQ(1, grid[3][2].no);
	EXPECT_EQ(1, grid[3][4].no);
	EXPECT_EQ(0, grid[4][2].no);
	EXPECT_EQ(1, grid[4][3].no);
	EXPECT_EQ(0, grid[4][4].no);
}
TEST(Day06, Day06_expand_2) {
	aoc2018_06::grid_t	grid(10, std::vector<aoc2018_06::plot>(10));

	auto expanded = aoc2018_06::expand(1, 3, 3, 2, grid);

	EXPECT_TRUE(expanded);
	EXPECT_EQ(1, grid[1][3].no);
	EXPECT_EQ(1, grid[2][4].no);
	EXPECT_EQ(1, grid[3][5].no);
	EXPECT_EQ(1, grid[4][4].no);
	EXPECT_EQ(1, grid[5][3].no);
	EXPECT_EQ(1, grid[4][2].no);
	EXPECT_EQ(1, grid[3][1].no);
	EXPECT_EQ(1, grid[2][2].no);
}

TEST(Day06, Day06_expand_collision) {
	aoc2018_06::grid_t	grid(10, std::vector<aoc2018_06::plot>(10));

	auto expanded1 = aoc2018_06::expand(1, 3, 3, 1, grid);
	outputGridPart(10, grid);
	auto expanded2 = aoc2018_06::expand(2, 5, 3, 1, grid);
	outputGridPart(10, grid);

	EXPECT_TRUE(expanded1);
	EXPECT_TRUE(expanded2);
	EXPECT_EQ(-1, grid[4][3].no);
}

TEST(Day06, Day06_A_1) {
	std::istringstream ss(
		"1, 1\n"
		"1, 6\n"
		"8, 3\n"
		"3, 4\n"
		"5, 5\n"
		"8, 9\n"
	);
	auto	input = aoc2018::ReadInput(ss);
	EXPECT_EQ(17, aoc2018_06::largestArea(input));
}
