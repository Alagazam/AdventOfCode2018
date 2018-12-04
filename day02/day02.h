#pragma once
#include "..\common\inputReader.h"
#include <array>

namespace aoc2018_02 {

using letterCounts = std::array<int, 26>;

letterCounts countLetters(std::string s)
{
	letterCounts counts{ 0 };
	for (auto c : s)
	{
		++counts[c - 'a'];
	}
	return counts;
}

int checksum(aoc2018::inputContent input)
{
	int twos{ 0 };
	int threes{ 0 };
	for (auto row : input)
	{
		auto counts = countLetters(row[0]);
		if (std::find(counts.begin(), counts.end(), 2) != counts.end())  ++twos;
		if (std::find(counts.begin(), counts.end(), 3) != counts.end())  ++threes;
	}
	return twos*threes;
}

int Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day02.txt");
	auto	input = aoc2018::ReadInput(*file);
	return checksum(input);
}

bool checkIfOffByOne(const std::string a, const std::string b)
{
	if (a.size() != b.size()) return false;
	int count{ 0 };
	for (size_t i = 0; i != a.size(); ++i)
	{
		if (a[i] != b[i]) ++count;
		if (count > 1) return false;
	}
	return count==1;
}
std::string removeMismatchLetter(const std::string a, const std::string b)
{
	std::string s;
	for (size_t i = 0; i != a.size(); ++i)
	{
		if (a[i] == b[i]) s += a[i];
	}
	return s;
}

std::string find_boxes(aoc2018::inputContent input)
{
	for (auto row1 = input.begin(); row1 != input.end()-1; ++row1)
	{
		for (auto row2 = row1 + 1; row2 != input.end(); ++row2)
		{
			std::cout << ".";
			if (checkIfOffByOne((*row1)[0], (*row2)[0]))
			{
				std::cout << "\n";
				return removeMismatchLetter((*row1)[0], (*row2)[0]);
			}
		}
	}
	return "";
}

std::string Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day02.txt");
	auto	input = aoc2018::ReadInput(*file);
	return find_boxes(input);
}

}
