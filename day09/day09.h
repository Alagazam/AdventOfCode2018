#pragma once
#include "..\common\inputReader.h"
#include <list>

namespace aoc2018_09 {


int64_t play(int players, int marbles)
{
	std::list<int>	circle{ 0 };
	std::vector<int64_t>	score(players);
	auto currentMarble{ circle.begin() };
	int currentPlayer{ 0 };
	int64_t maxScore{ 0 };
	for (decltype(marbles) i = 1; i <= marbles; ++i)
	{
		if (i % 100000 == 0) std::cout << '.';
		if (i % 23 == 0)
		{
			score[currentPlayer] += i;
			for (int x = 0; x != 7; ++x)
			{
				if (currentMarble == circle.begin())
					currentMarble = circle.end();
				--currentMarble;
			}

			score[currentPlayer] += *currentMarble;
			if (maxScore < score[currentPlayer])
			{
				maxScore = score[currentPlayer];
			}
			currentMarble = circle.erase(currentMarble);
		}
		else
		{
			++currentMarble;
			if (currentMarble == circle.end()) currentMarble = circle.begin();
			++currentMarble;
			currentMarble = circle.insert(currentMarble, i);
		}
		currentPlayer = (currentPlayer + 1) % players;

	}
	return maxScore;
}

int64_t play(aoc2018::inputContent input)
{
	auto players = std::stoi(input[0][0]);
	auto marbles = std::stoi(input[0][6]);
	return play(players, marbles);
}

int64_t play100(aoc2018::inputContent input)
{
	auto players = std::stoi(input[0][0]);
	auto marbles = std::stoi(input[0][6])*100;
	return play(players, marbles);
}

int64_t Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day09.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  play(input);
}


int64_t Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day09.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  play100(input);
}


}