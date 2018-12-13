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


int getMetadataValue(aoc2018::rowContent::const_iterator &it)
{
	int metadataSum{ 0 };
	std::vector<int> childValues;
	auto childNodes = std::stoi(*it);
	++it;
	auto metadataSize = std::stoi(*it);
	++it;
	for (int i = 0; i != childNodes; ++i)
	{
		auto childValue = getMetadataValue(it);
		childValues.push_back(childValue);
	}
	for (int i = 0; i != metadataSize; ++i)
	{
		auto childNo = std::stoi(*it);
		if (childNodes != 0)
		{
			if (childNo - 1 < childValues.size())
			{
				metadataSum += childValues[childNo - 1];
			}
		}
		else
		{
			metadataSum += childNo;
		}
		++it;
	}
	return metadataSum;
}

int getMetadataValue(aoc2018::inputContent input)
{
	auto it = input[0].cbegin();
	return getMetadataValue(it);
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
	return  getMetadataValue(input);
}


}