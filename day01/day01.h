#pragma once
#include "..\common\inputReader.h"
#include <set>

namespace aoc2018_01 {

int SumFreq(aoc2018::inputContent input)
{
	int sum = 0;
	for (auto row : input)
	{
		sum += stoi(row[0]);
	}
	return sum;
}

int Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day01.txt");
	auto	input = aoc2018::ReadInput(*file);
	return SumFreq(input);
}

int FirstRepeat(aoc2018::inputContent input)
{
	std::set<int> seen;
	int sum = 0;
	seen.insert(sum);
	for (;;)
	{
		for (auto row : input)
		{
			sum += stoi(row[0]);
			if (seen.find(sum) != seen.end())
			{
				std::cout << '\n';
				return sum;
			}
			seen.insert(sum);
		}
		std::cout << '.';
	}
	return 0;
}


int Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day01.txt");
	auto	input = aoc2018::ReadInput(*file);
	return FirstRepeat(input);
}

}
