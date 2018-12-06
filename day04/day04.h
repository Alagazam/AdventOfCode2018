#pragma once
#include "..\common\inputReader.h"
#include <array>
#include <map>

namespace aoc2018_04 {

auto rowCompare = [](const aoc2018::rowContent &lhs, const aoc2018::rowContent &rhs)
{
	if (lhs[0] < rhs[0]) return true;
	if (rhs[0] < lhs[0]) return false;
	if (lhs[1] < rhs[1]) return true;
	return false;
};
void sortRows(aoc2018::inputContent &input)
{
	std::sort(input.begin(), input.end(), rowCompare);
}

struct Guard
{
	int	number{ 0 };
	int totalMinutes{ 0 };
	std::array<int, 60> sleepMinutes{ 0 };
};

int getBestGuard(aoc2018::inputContent input)
{
	sortRows(input);
	std::map<int,Guard> guards;
	Guard	guard;
	int beginSleep{ 0 };
	int endSleep{ 0 };
	for (auto row : input)
	{
		if (row[2] == "Guard")
		{
			auto guardNo = std::stoi(row[3].substr(1));
			guard = guards[guardNo];
			guard.number = guardNo;
		}
		else if (row[2] == "falls")
		{
			beginSleep = std::stoi(row[1].substr(3,2));
		}
		else if (row[2] == "wakes")
		{
			endSleep = std::stoi(row[1].substr(3, 2));
			guard.totalMinutes += endSleep - beginSleep;
			for (auto i = beginSleep; i != endSleep; ++i)
			{
				guard.sleepMinutes[i]++;
			}
			guards[guard.number] = guard;
		}
	}

	using pair_type = decltype(guards)::value_type;
	auto mostSleep{ max_element(guards.begin(), guards.end(),
		[](const pair_type & p1, const pair_type & p2) { return p1.second.totalMinutes < p2.second.totalMinutes; }
	)->second };

	auto mostSleepMinute{ max_element(mostSleep.sleepMinutes.begin(), mostSleep.sleepMinutes.end())- mostSleep.sleepMinutes.begin() };

	return mostSleep.number * static_cast<int>(mostSleepMinute);
}

int Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day04.txt");
	auto	input = aoc2018::ReadInput(*file);
	return getBestGuard(input);
}

int Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day04.txt");
	auto	input = aoc2018::ReadInput(*file);
	return getBestGuard(input);
}

}