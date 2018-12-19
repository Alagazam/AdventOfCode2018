#pragma once
#include "..\common\inputReader.h"

namespace aoc2018_14 {

std::string	score(aoc2018::inputLines input)
{
	std::string	recepies = "37";
	int	firstElf{ 0 };
	int secondElf{ 1 };
	auto minLength = std::stoi(input[0]) + 10;
	while (recepies.size() < minLength)
	{
		char sum = recepies[firstElf] - '0' + recepies[secondElf] - '0';
		if (sum > 9) {
			recepies += '1';
			sum -= 10;
		}
		recepies += (sum + '0');
		firstElf = (firstElf + 1 + recepies[firstElf] - '0') % recepies.size();
		secondElf = (secondElf + 1 + recepies[secondElf] - '0') % recepies.size();
	}
	return recepies.substr(std::stoi(input[0]), 10);
}

size_t	skippedRecepies(aoc2018::inputLines input)
{
	std::string	recepies = "37";
	int	firstElf{ 0 };
	int secondElf{ 1 };
	for (;;)
	{
		char sum = recepies[firstElf] - '0' + recepies[secondElf] - '0';
		if (sum > 9) {
			recepies += '1';
			recepies += (sum - 10 + '0');
		}
		else
			recepies += (sum + '0');

		if (recepies.size() > input[0].size())
		{
			if (recepies.substr(recepies.size() - input[0].size()) == input[0])
				return recepies.size() - input[0].size();
			if (sum > 9) {
				if (recepies.substr(recepies.size() - input[0].size() - 1, input[0].size()) == input[0])
					return recepies.size() - input[0].size() - 1;
			}
		}

//		std::cout << recepies.substr(recepies.size()>50 ? recepies.size() - 50 : 0) << '\n';
		firstElf = (firstElf + 1 + recepies[firstElf] - '0') % recepies.size();
		secondElf = (secondElf + 1 + recepies[secondElf] - '0') % recepies.size();
	}

	return 0;
}

std::string Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day14.txt");
	auto	input = aoc2018::ReadInputLines(*file);
	return  score(input);
}

size_t Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day14.txt");
	auto	input = aoc2018::ReadInputLines(*file);
	return  skippedRecepies(input);
}

}