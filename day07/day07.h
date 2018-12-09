#pragma once
#include "..\common\inputReader.h"

namespace aoc2018_07 {

std::string	buildOrder(const aoc2018::inputContent &input)
{
	std::map<char, std::set<char>> dependencies;
	std::string		order;

	// set up all dependencies
	for (auto row : input)
	{
		if (dependencies.find(row[1][0]) == dependencies.end())	// dont miss "root" steps
			dependencies[row[1][0]] = {};
		dependencies[row[7][0]].insert(row[1][0]);
	}

	while (!dependencies.empty())
	{
		auto nextStep = std::find_if(dependencies.begin(), dependencies.end(), 
			[](const decltype(*dependencies.begin()) & dep) ->bool { return dep.second.empty(); }
		);
		auto step = nextStep->first;
		order += step;
		dependencies.erase(step);
		for (auto &dep : dependencies)
		{
			dep.second.erase(step);
		}
	}

	return order;
}

std::string Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day07.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  buildOrder(input);
}

std::string Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day07.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  buildOrder(input);
}


}