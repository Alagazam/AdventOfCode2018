#include <iostream>
#include "../day01/day01.h"
#include "../day02/day02.h"
#include "../day03/day03.h"
#include "../day04/day04.h"

int main(int argc, char *argv[])
{
	try {
		int day = 0;
		if (argc == 2) day = std::stoi(argv[1]);

		if (day == 0 || day == 1)	std::cout << "Day 01 A=" << aoc2018_01::Solve_A() << " B=" << aoc2018_01::Solve_B() << "\n";
		if (day == 0 || day == 2)	std::cout << "Day 02 A=" << aoc2018_02::Solve_A() << " B=" << aoc2018_02::Solve_B() << "\n";
		if (day == 0 || day == 3)	std::cout << "Day 03 " << aoc2018_03::Solve_AB() << "\n";
		if (day == 0 || day == 4)	std::cout << "Day 04 " << aoc2018_04::Solve_AB() << "\n";
	}
	catch (std::runtime_error e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
}
