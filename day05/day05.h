#pragma once
#include "..\common\inputReader.h"
#include <string_view>
#include <cctype>

namespace aoc2018_05 {

int	reducePolymer(const aoc2018::inputContent&	input)
{
	std::string_view	polymer = input[0][0];
	std::string	reduced;
	for (auto c : polymer)
	{
		reduced += c;
		if (reduced.size()>1
			&& std::toupper(*reduced.rbegin()) == std::toupper(*(++reduced.rbegin()))	//  same letter
			&& *reduced.rbegin() != *(++reduced.rbegin())								// but not same case
			)
		{
			reduced.pop_back();
			reduced.pop_back();
		}
	}
	return static_cast<int>(reduced.size());
}

int Solve_AB()
{
	auto	file = aoc2018::OpenInputFile("day05.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  reducePolymer(input);
}


}