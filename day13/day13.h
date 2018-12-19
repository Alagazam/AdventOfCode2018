#pragma once
#include "..\common\inputReader.h"
#include <Windows.h>

namespace aoc2018_13 {

struct cart
{
	int id{ 0 };
	int x{ 0 };
	int y{ 0 };
	int dx{ 0 };
	int dy{ 0 };
	int turnStep{ 0 };
	void move(char trackType)
	{
		switch (trackType)
		{
		case '|':
		case '-':
			break;
		case '/':
			if (dx == 1) { dx = 0; dy = -1; }
			else if (dx == -1) { dx = 0; dy = 1; }
			else if (dy == 1) { dx = -1; dy = 0; }
			else if (dy == -1) { dx = 1; dy = 0; }
			break;

		case '\\':
			if (dx == 1) { dx = 0; dy = 1; }
			else if (dx == -1) { dx = 0; dy = -1; }
			else if (dy == 1) { dx = 1; dy = 0; }
			else if (dy == -1) { dx = -1; dy = 0; }
			break;
		case '+':
			if (turnStep == 0)	// turn left
			{
				if (dx == 1) { dx = 0; dy = -1; }
				else if (dx == -1) { dx = 0; dy = 1; }
				else if (dy == 1) { dx = 1; dy = 0; }
				else if (dy == -1) { dx = -1; dy = 0; }
				++turnStep;
			}
			else if (turnStep == 1)	// Go strait
			{
				++turnStep;
			}
			else if (turnStep == 2)	// turn right
			{
				if (dx == 1) { dx = 0; dy = 1; }
				else if (dx == -1) { dx = 0; dy = -1; }
				else if (dy == 1) { dx = -1; dy = 0; }
				else if (dy == -1) { dx = 1; dy = 0; }
				turnStep = 0;
			}
			break;
		}
		x += dx;
		y += dy;
	}

	bool	operator<(const cart &rhs) const	// don't compare direction
	{
		if (y < rhs.y)  return true;
		if (y == rhs.y && x < rhs.x) return true;
		return false;
	}
	bool	crash(const cart &cart) const
	{
		return id != cart.id && x == cart.x && y == cart.y;
	}
};

using	carts_t = std::vector<cart>;

carts_t	findCarts(aoc2018::inputLines	&input)
{
	carts_t	carts;
	int	cartNo{ 1 };
	for (int y=0; y != input.size(); ++y)
	{
		for (int x = 0; x != input[y].size(); ++x)
		{
			if (input[y][x] == 'v') {
				input[y][x] = '|';
				carts.push_back({ cartNo++, x, y, 0, 1 });
			}
			else if (input[y][x] == '^') {
				input[y][x] = '|';
				carts.push_back({ cartNo++, x, y, 0, -1 });
			}
			else if (input[y][x] == '<') {
				input[y][x] = '-';
				carts.push_back({ cartNo++, x, y, -1, 0 });
			}
			else if (input[y][x] == '>') {
				input[y][x] = '-';
				carts.push_back({ cartNo++, x, y, 1, 0 });
			}
		}
	}
	return carts;
}

carts_t::const_iterator	hasCrash(const carts_t &carts, const cart &movingCart)
{
	return std::find_if(carts.cbegin(), carts.cend(), [&](const cart& cart) { return cart.crash(movingCart); });
}

// Untested, but simple enough it should at least be close to reality...
void gotoxy(short x, short y) {
	COORD pos = { x, y };
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleCursorPosition(output, pos);
}


void print(aoc2018::inputLines	input, carts_t carts)
{
	gotoxy(0, 0);
	for (int y = 0; y != input.size(); ++y)
	{
		for (int x = 0; x != input[y].size(); ++x)
		{
			bool	hascart = false;
			for (auto cart : carts)
			{
				if (cart.x == x && cart.y == y) {
					if (cart.dx == 1) std::cout << '>';
					else if (cart.dx == -1) std::cout << '<';
					else if (cart.dy == 1) std::cout << 'v';
					else if (cart.dy == -1) std::cout << '^';
					hascart = true;
					break;
				}
			}
			if (!hascart) std::cout << input[y][x];
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

std::string	findFirstCrash(aoc2018::inputLines	input)
{
	auto carts = findCarts(input);

	bool	crash{ false };
	cart	crashCart1;
	cart	crashCart2;

	while (!crash)
	{
		std::sort(carts.begin(), carts.end());
		for (auto &cart : carts)
		{
			cart.move(input[cart.y][cart.x]);
			auto crashCart = hasCrash(carts, cart);
			if (crashCart != carts.end())
			{
				crash = true;
				crashCart1 = cart;
				crashCart2 = *crashCart;
				break;
			}
		}
		//print(input, carts);
	}
	return std::to_string(crashCart1.x) + ',' + std::to_string(crashCart1.y);
}

std::string Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day13.txt");
	auto	input = aoc2018::ReadInputLines(*file);
	return  findFirstCrash(input);
}

std::string Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day13.txt");
	auto	input = aoc2018::ReadInputLines(*file);
	return  findFirstCrash(input);
}

}