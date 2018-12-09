#pragma once
#include "..\common\inputReader.h"

namespace aoc2018_06 {

const size_t  gridsize = 400;
struct	plot {
	int no{ 0 };
	int dist{ 0 };
};
using grid_t = std::vector<std::vector<plot>>;
struct coord{
	int x{ 0 };
	int y{ 0 };
};
using coords_t = std::vector<coord>;

void outputGridPart(int size, const grid_t &grid)
{
	for (int y = 0; y != size; ++y)
	{
		for (int x = 0; x != size; ++x)
		{
			auto no = grid[x][y].no;
			std::cerr << (no < 0 ? "." : std::to_string(grid[x][y].no));
		}
		std::cerr << '\n';
	}
}
bool updatePlot(int no, int x, int y, int dist, grid_t &grid)
{
	if (x < 0 || x >= gridsize || y < 0 || y >= gridsize) return false;	// outside grid

	auto &plot = grid[x][y];
	if (plot.no == no) return false;	// already same owner
	if (plot.no == 0)					// free : allocate
	{
		plot = { no, dist };
		return true;
	}
	if (plot.dist < dist) return false;	// owned by someone nearer
	if (plot.dist == dist)				// same distanse : invalidate
	{
		plot = { -1, -1 };
		return false;
	}
	plot = { no, dist };	// we are nearer : allocate
	return true;
}

bool expand(int no, int x, int y, int dist, grid_t &grid)
{
	bool expanded{ false };
	for (int i = 0; i <= dist; ++i)
	{
		auto ex1 = updatePlot(no, x + i, y - dist + i, dist, grid);	// 1	i=0	..1..	i=1	..1..
		auto ex2 = updatePlot(no, x - i, y + dist - i, dist, grid);	// 2	d=2	.....	d=2	.4.1.
		auto ex3 = updatePlot(no, x + dist - i, y + i, dist, grid);	// 3		4.o.3		4.o.3
		auto ex4 = updatePlot(no, x - dist + i, y - i, dist, grid);	// 4		.....		.2.3.
																	//			..2..		..2..
		expanded = expanded || ex1 || ex2 || ex3 || ex4;
	}
	return expanded;
}

int	largestArea(const aoc2018::inputContent&	input)
{
	grid_t	grid(gridsize, std::vector<plot>(gridsize));
	int size{ 0 };
	bool loop{ true };
	while (loop)
	{
		loop = false;
		int no{ 1 };
		for (auto row : input)
		{
			auto x = stoi(row[0]);
			auto y = stoi(row[1]);
			if (expand(no, x, y, size, grid))
			{
				loop = true;
			}
			++no;
		}
		++size;
	}

	std::vector<int> areaCount(input.size()+1);
	for (int x = 0; x != gridsize; ++x)
	{
		for (int y = 0; y != gridsize; ++y)
		{
			auto &plot{ grid[x][y] };
			if (x == 0 || y == 0 || x == gridsize - 1 || y == gridsize - 1)
			{
				if (plot.no > 0) areaCount[plot.no] = -1;
			}
			else if (plot.no > 0 && areaCount[plot.no] != -1)
			{
				++areaCount[plot.no];
			}
		}
	}

	return *std::max_element(areaCount.begin(), areaCount.end());
}

int sizeOfSafeDistance(const aoc2018::inputContent&	input, int safeDist, int gridSize)
{
	coords_t	coords;
	for (auto row : input)
	{
		auto x0 = stoi(row[0]);
		auto y0 = stoi(row[1]);
		coords.push_back({ x0,y0 });
	}
	int safeArea{ 0 };
	for (int x = 0; x != gridSize; ++x)
	{
		for (int y = 0; y != gridSize; ++y)
		{
			int totDist{ 0 };
			for (auto row : coords)
			{
				totDist += abs(x - row.x) + abs(y - row.y);
			}
			if (totDist <= safeDist)
			{
				++safeArea;
			}
		}
		std::cout << '.';
	}
	std::cout << '\n';
	return safeArea;
}

int Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day06.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  largestArea(input);
}

int Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day06.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  sizeOfSafeDistance(input, 10000, 400);
}


}