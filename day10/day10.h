#pragma once
#include "..\common\inputReader.h"
#include <limits>
#define NOMINMAX
#include <Windows.h>

namespace aoc2018_10 {


struct Star
{
	int	x{ 0 };
	int y{ 0 };
	int dx{ 0 };
	int dy{ 0 };
	void move() { x += dx; y += dy; };

	// "position=<-6, 10> velocity=< 2, -2>"
	//            11111111112222222222333333
	//  012345678901234567890123456789012345
	Star(std::string s)
	{
		auto startX = s.find('<') + 1;
		auto endX = s.find(',');
		auto subs = s.substr(startX, endX - startX);
		x = stoi(subs);
		auto startY = endX + 1;
		auto endY = s.find('>');
		subs = s.substr(startY, endY - startY);
		y = stoi(subs);

		auto startDX = s.rfind('<') + 1;
		auto endDX = s.rfind(',');
		subs = s.substr(startDX, endDX - startDX);
		dx = stoi(subs);
		auto startDY = endDX + 1;
		auto endDY = s.rfind('>');
		subs = s.substr(startDY, endDY - startDY);
		dy = stoi(subs);
	};
};

// Untested, but simple enough it should at least be close to reality...
void gotoxy(short x, short y) {
	COORD pos = { x, y };
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleCursorPosition(output, pos);
}

int alignStars(aoc2018::inputLines &input, int ylimit)
{
	std::vector<Star> stars;
	for (auto row : input)
	{
		stars.emplace_back(Star(row));
	}
	int xmax{ std::numeric_limits<int>::min() };
	int xmin{ std::numeric_limits<int>::max() };
	int ymax{ std::numeric_limits<int>::min() };
	int ymin{ std::numeric_limits<int>::max() };

	bool loop = true;
	int seconds{ 0 };
	while (loop)
	{
		xmax = std::numeric_limits<int>::min();
		xmin = std::numeric_limits<int>::max();
		ymax = std::numeric_limits<int>::min();
		ymin = std::numeric_limits<int>::max();
		for (auto &s : stars)
		{
			s.move();
			if (s.x > xmax) xmax = s.x;
			if (s.x < xmin) xmin = s.x;
			if (s.y > ymax) ymax = s.y;
			if (s.y < ymin) ymin = s.y;
		}
		loop = (ymax - ymin > ylimit);

		++seconds;

		gotoxy(0, 0);
		if (ymax - ymin > 25) continue;

		for (int y = ymin-2; y != ymax + 3; ++y)
		{
			for (int x = xmin-2; x != xmax + 3; ++x)
			{
				if (std::any_of(stars.begin(), stars.end(), [x, y](const Star& s) { return s.x == x && s.y == y; }))
					std::cout << '*';
				else
					std::cout << '.';
			}
			std::cout << "  \n";
		}
		std::cout << "                                                                                    \n";

	}

	return seconds;
}

int Solve_AB()
{
	auto	file = aoc2018::OpenInputFile("day10.txt");
	auto	input = aoc2018::ReadInputLines(*file);
	return  alignStars(input,17);
}

}