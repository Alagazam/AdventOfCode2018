#pragma once
#include "..\common\inputReader.h"
#include <array>

namespace aoc2018_18 {

int	calcResourceValue(const aoc2018::inputLines &input)
{
	int	tree{ 0 };
	int yard{ 0 };
	for (const auto &row : input)
	{
		for (const auto acre : row)
		{
			if (acre == '|') ++tree;
			else if (acre == '#') ++yard;
		}
	}

	return tree * yard;
}

char	calcAcre(const aoc2018::inputLines &input, int x, int y)
{
	int open{ 0 };
	int tree{ 0 };
	int yard{ 0 };

	for (int dy = -1; dy <= 1; ++dy)
	{
		for (int dx = -1; dx <= 1; ++dx)
		{
			if (dx == 0 && dy == 0)
				continue;
			if (x + dx < 0 || y + dy < 0 || x + dx >= input[0].size() || y + dy >= input.size())
				continue;
			auto	c = input[y + dy][x + dx];
			if (c == '.') ++open;
			if (c == '|') ++tree;
			if (c == '#') ++yard;
		}
	}
	auto acre = input[y][x];
	if (acre == '.')	return tree >= 3 ? '|' : '.';
	if (acre == '|')	return yard >= 3 ? '#' : '|';
	if (acre == '#')	return (yard >= 1 && tree >=1) ? '#' : '.';

	return '.';
}

aoc2018::inputLines	develop(const aoc2018::inputLines &input)
{
	aoc2018::inputLines result;
	for (int y=0; y!=input.size(); ++y)
	{
		std::string	nextLine;
		for (int x=0; x!=input[y].size(); ++x)
		{
			nextLine += calcAcre(input, x, y);
		}
		result.push_back(nextLine);
	}
	return result;
}

int	developAndCountResources(const aoc2018::inputLines &input, int minutes)
{
	auto	acres = input;
	for (int i = 0; i != minutes; ++i)
	{
		acres = develop(acres);
		if (i % 10000000 == 0) std::cout << i << '\n';
	}
	return calcResourceValue(acres);
}

int Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day18.txt");
	auto	input = aoc2018::ReadInputLines(*file);

	return  developAndCountResources(input, 10);
}

int Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day18.txt");
	auto	input = aoc2018::ReadInputLines(*file);
	return  developAndCountResources(input, 1000000000);
}

}