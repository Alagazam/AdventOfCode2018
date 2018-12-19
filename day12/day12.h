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

int64_t	sumOfPlantPots(const aoc2018::inputContent &input, int64_t generations = 20)
{
	auto state = input[0][2];
	int64_t	zeroOffset{ 0 };

	transitions_t	transitions;
	for (auto &row : input)
	{
		if (row.size()==3 && row[0].size() == 5)
		{
			transitions[row[0]] = row[2][0];
		}
	}
	
	int64_t prevSum{ 0 };
	int64_t prevPrevSum{ 0 };
	int64_t	stablePatternStart{ 0 };
	for (int64_t i = 0; i != generations; ++i)
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
		int64_t sum{ 0 };
		for (int j = 0; j != state.size(); ++j)
		{
			if (state[j] == '#')
				sum += j - zeroOffset;
		}

//		std::cout << i << "  " << sum-prevSum << "  " << state.substr(0,200) << '\n';

		// If we got same differences, we reached a stable pattern
		if (sum-prevSum == prevSum-prevPrevSum)
		{
			stablePatternStart = i;
			break;
		}
			
		prevPrevSum = prevSum;
		prevSum = sum;

	}

	int64_t sum{ 0 };
	if (stablePatternStart != 0)
	{
		auto diff = prevSum - prevPrevSum;
		sum = prevSum + diff * (generations - stablePatternStart);
	}
	else
	{
		for (int i = 0; i != state.size(); ++i)
		{
			if (state[i] == '#')
				sum += i - zeroOffset;
		}
	}
	return sum;
}

int64_t Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day12.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  sumOfPlantPots(input);
}

int64_t Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day12.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  sumOfPlantPots(input, 50000000000);
}

}