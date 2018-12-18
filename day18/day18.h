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
	}
	return calcResourceValue(acres);
}

int	developAndCountResourcesFindingLoops(const aoc2018::inputLines &input, int minutes)
{
	auto	acres = input;
	std::vector<int>		results;
	ptrdiff_t loopStartIndex{ 0 };
	ptrdiff_t loopLength{ 0 };

	for (int i = 0; i != minutes; ++i)
	{
		acres = develop(acres);
		auto result = calcResourceValue(acres);

		// Do we had the same result before
		auto start1 = std::find(results.begin(), results.end(), result);
		if (start1 != results.end())
		{
			// if so: do we have a second finding ?
			auto start2 = std::find(start1 + 1, results.end(), result);
			if (start2 != results.end())
			{
				// do we have another full repetition to compare?
				if (start2 - start1 >= results.end() - start2)
				{
					// Compare repetition
					bool equal = true;
					for (auto it1 = start1, it2 = start2; it1 != start2; ++it1, ++it2)
					{
						if (*it1 != *it2)
						{
							equal = false;
						}
					}
					if (equal)	// found loop: exit loop;
					{
						loopStartIndex = start2 - results.begin();
						loopLength = start2 - start1;
						std::cout << "start:" << loopStartIndex << " loop:" << loopLength << "\n";
						break;
					}
				}
			}
		}
		results.push_back(result);
	}

	auto index = (minutes - loopStartIndex) % loopLength + loopStartIndex - 1;
	return results[index];
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
	return  developAndCountResourcesFindingLoops(input, 1000000000);
}

}