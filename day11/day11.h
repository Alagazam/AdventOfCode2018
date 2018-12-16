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

using grid_t = std::array<std::array<int, 301>, 301>;
std::pair<int,int>	bestSubGrid(int serial)
{
	grid_t	grid;
	for (int y = 1; y != 301; ++y)
	{
		for (int x = 1; x != 301; ++x)
		{
			grid[x][y] = power(serial, x, y);
		}
	}

	int maxPow = 0;
	std::pair<int, int> maxPowPos{ 0,0 };
	for (int y = 1; y+2 != 301; ++y)
	{
		for (int x = 1; x+2 != 301; ++x)
		{
			auto power3x3 = grid[x][y] + grid[x][y + 1] + grid[x][y + 2] +
				grid[x + 1][y] + grid[x + 1][y + 1] + grid[x + 1][y + 2] +
				grid[x + 2][y] + grid[x + 2][y + 1] + grid[x + 2][y + 2];
			if (power3x3 > maxPow)
			{
				maxPowPos = std::make_pair(x, y);
				maxPow = power3x3;
			}
		}
	}

	return maxPowPos;
}

std::string Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day11.txt");
	auto	input = aoc2018::ReadInputLines(*file);
	auto	serial = std::stoi(input[0]);
	auto	coord = bestSubGrid(serial);
	std::string s = std::to_string(coord.first) + "," + std::to_string(coord.second);
	return  s;
}

std::string Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day11.txt");
	auto	input = aoc2018::ReadInputLines(*file);
	auto	serial = std::stoi(input[0]);
	auto	coord = bestSubGrid(serial);
	std::string s = std::to_string(coord.first) + "," + std::to_string(coord.second);
	return  s;
}

}