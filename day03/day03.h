#pragma once
#include "..\common\inputReader.h"
#include <array>

namespace aoc2018_03 {

std::pair<int,int> getCoord(std::string s)
{
	int x = stoi(s);
	int y = stoi(s.substr(s.find_first_of(",x") + 1));
	return std::make_pair(x, y);
}

std::pair<int,int64_t> calcOverlaps(aoc2018::inputContent input)
{
	std::vector<std::vector<int>>	fabric(1000, std::vector<int>(1000));
	std::vector<bool> claimsOK(input.size()+1, true);
	claimsOK[0] = false;

	int overlaps{ 0 };

	for (auto row : input)
	{
		auto claim = std::stoi(row[0].substr(1));
		auto coord = getCoord(row[2]);
		auto size = getCoord(row[3]);
		for (auto x = 0; x != size.first; ++x)
		{
			for (auto y = 0; y != size.second; ++y)
			{
				auto &currentClaim = fabric[coord.first + x][coord.second + y];
				// this is taken before. First overlap
				if (currentClaim > 0)
				{
					++overlaps;
					currentClaim = -currentClaim;
				}
				// Overlap, mark as not OK
				if (currentClaim < 0)
				{
					claimsOK[claim] = false;
					claimsOK[-currentClaim] = false;
				}
				// Not taken before. Mark first claim
				if (currentClaim == 0)
				{
					currentClaim = claim;
				}
			}
		}
	}
	auto okClaim = std::distance(claimsOK.begin(), std::find(claimsOK.begin(), claimsOK.end(), true));

	return std::make_pair(overlaps, okClaim);
}

std::string Solve_AB()
{
	using namespace std::string_literals;

	auto	file = aoc2018::OpenInputFile("day03.txt");
	auto	input = aoc2018::ReadInput(*file);
	auto	res = calcOverlaps(input);
	return  "A="s + std::to_string(res.first) + " B=" + std::to_string(res.second);
}

}
