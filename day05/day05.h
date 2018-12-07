#pragma once
#include "..\common\inputReader.h"
#include <string_view>
#include <cctype>

namespace aoc2018_05 {

std::string	reducePolymer(std::string_view polymer)
{
	std::string	reduced;
	for (auto c : polymer)
	{
		reduced += c;
		if (reduced.size() > 1
			&& std::toupper(*reduced.rbegin()) == std::toupper(*(++reduced.rbegin()))	//  same letter
			&& *reduced.rbegin() != *(++reduced.rbegin())								// but not same case
			)
		{
			reduced.pop_back();
			reduced.pop_back();
		}
	}
	return reduced;
}

int	reducePolymer(const aoc2018::inputContent&	input)
{
	std::string_view	polymer = input[0][0];

	return static_cast<int>(reducePolymer(polymer).size());
}

std::string	reducePolymerEx(std::string polymer, char c)
{
	polymer.erase(std::remove(polymer.begin(), polymer.end(), std::tolower(c)), polymer.end());
	polymer.erase(std::remove(polymer.begin(), polymer.end(), std::toupper(c)), polymer.end());
	return reducePolymer(polymer);
}

int	reducePolymerEx(const aoc2018::inputContent&	input)
{
	std::string_view	polymer = input[0][0];
	auto	initialReduced = reducePolymer(polymer);
	std::string	minReduced;

	for (char c = 'a'; c <= 'z'; ++c)
	{
		 auto reduced = reducePolymerEx(initialReduced,c);
		 if (reduced.size() < minReduced.size() || minReduced.empty())
		 {
			 minReduced = reduced;
		 }
	}
	return static_cast<int>(minReduced.size());
}

int Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day05.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  reducePolymer(input);
}

int Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day05.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  reducePolymerEx(input);
}


}