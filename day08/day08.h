#pragma once
#include "..\common\inputReader.h"

namespace aoc2018_08 {


int getMetadataSum(aoc2018::rowContent::const_iterator &it)
{
	int metadataSum{ 0 };
	auto childNodes = std::stoi(*it);
	++it;
	auto metadataSize = std::stoi(*it);
	++it;
	for (int i = 0; i != childNodes; ++i)
	{
		metadataSum += getMetadataSum(it);
	}
	for (int i = 0; i != metadataSize; ++i)
	{
		metadataSum += std::stoi(*it);
		++it;
	}
	return metadataSum;
}

int getMetadataSum(aoc2018::inputContent input)
{
	auto it = input[0].cbegin();
	return getMetadataSum(it);
}

int Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day08.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  getMetadataSum(input);
}


int Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day08.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  getMetadataSum(input);
}


}