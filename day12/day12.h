#pragma once
#include "..\common\inputReader.h"

namespace aoc2018_12 {

using	transitions_t = std::map<std::string, char>;

std::string	evolve(const std::string &state, const transitions_t &transitions)
{
	std::string  result{ ".." };
	for (int i = 0; i != state.size()-4; ++i)
	{
		auto trans = transitions.find(state.substr(i, 5));
		if (trans != transitions.end())
		{
			result += trans->second;
		}
		else
		{
			result += '.';
		}
	}
	result += "..";
	return result;
}

int	sumOfPlantPots(const aoc2018::inputContent &input)
{
	auto state = input[0][2];
	int	zeroOffset{ 0 };

	transitions_t	transitions;
	for (auto &row : input)
	{
		if (row.size()==3 && row[0].size() == 5)
		{
			transitions[row[0]] = row[2][0];
		}
	}
	
	for (int i = 0; i != 20; ++i)
	{
		state = evolve("...." + state + "....", transitions);
		if (state[3] == '#' || state[4] == '#')
		{
			state = state.substr(2);
			zeroOffset += 2;
		}
		else
		{
			state = state.substr(4);
		}
		if (state[state.size()-4] == '#' || state[state.size() - 5] == '#')
		{
			state = state.substr(0, state.size() - 2);
		}
		else
		{
			state = state.substr(0, state.size() - 4);
		}
	}

	int sum{ 0 };
	for (int i = 0; i != state.size(); ++i)
	{
		if (state[i] == '#')
			sum += i - zeroOffset;
	}
	return sum;
}

int Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day12.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  sumOfPlantPots(input);
}

int Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day12.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  0;
}

}