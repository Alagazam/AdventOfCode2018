#pragma once
#include "..\common\inputReader.h"
#include <array>

namespace aoc2018_11 {

int	power(int serial, int x, int y)
{
	//Find the fuel cell's rack ID, which is its X coordinate plus 10.
	auto rackId = x + 10;
	//Begin with a power level of the rack ID times the Y coordinate.
	auto power = rackId * y;
	//Increase the power level by the value of the grid serial number (your puzzle input).
	power += serial;
	//Set the power level to itself multiplied by the rack ID.
	power *= rackId;
	//Keep only the hundreds digit of the power level (so 12345 becomes 3; numbers with no hundreds digit become 0).
	power = power / 100;
	power = power % 10;
	//Subtract 5 from the power level.
	power -= 5;
	return power;
}

struct subGrid
{
	int x{ 0 };
	int y{ 0 };
	int size{ 0 };
	int pow{ 0 };
	bool operator==(const subGrid& rhs) const { return x == rhs.x && y == rhs.y && size == rhs.size && pow == rhs.pow; };
};

const int gridSize{ 301 };
using grid_t = std::array<std::array<int, gridSize>, gridSize>;

void	initGrid(grid_t &grid, int serial)
{
	for (int y = 1; y != gridSize; ++y)
	{
		for (int x = 1; x != gridSize; ++x)
		{
			grid[x][y] = power(serial, x, y);
		}
	}
}

subGrid	bestSubGrid(const int size, const grid_t &grid)
{
	int maxPow{ 0 };
	std::pair<int, int> maxPowPos{ 0,0 };
	for (int y = 1; y + size != gridSize; ++y)
	{
		for (int x = 1; x + size != gridSize; ++x)
		{
			auto power{ 0 };
			for (int dy = 0; dy != size; ++dy)
			{
				for (int dx = 0; dx != size; ++dx)
				{
					power += grid[x + dx][y + dy];
				}

			}
			if (power > maxPow)
			{
				maxPowPos = std::make_pair(x, y);
				maxPow = power;
			}
		}
	}

	return { maxPowPos.first, maxPowPos.second, size, maxPow };
}

subGrid	bestSubGrid(const int serial, const int size = 3)
{
	grid_t	grid;
	initGrid(grid, serial);
	return bestSubGrid(size, grid);
}

subGrid	bestSubGridAnySize(const int serial, int maxSize=gridSize)
{
	grid_t	grid;
	initGrid(grid, serial);

	subGrid maxPowSubGrid;
	for (int size = 1; size != maxSize; ++size)
	{
		auto best = bestSubGrid(size, grid);
		if (maxPowSubGrid.pow < best.pow)
			maxPowSubGrid = best;

		std::cout << '.';
	}
	return maxPowSubGrid;
}
std::string Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day11.txt");
	auto	input = aoc2018::ReadInputLines(*file);
	auto	serial = std::stoi(input[0]);
	auto	subGrid = bestSubGrid(serial);
	std::string s = std::to_string(subGrid.x) + "," + std::to_string(subGrid.y);
	return  s;
}

std::string Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day11.txt");
	auto	input = aoc2018::ReadInputLines(*file);
	auto	serial = std::stoi(input[0]);
	auto	coord = bestSubGridAnySize(serial);
	std::string s = std::to_string(coord.x) + "," + std::to_string(coord.y) + "," + std::to_string(coord.size);
	return  s;
}

}