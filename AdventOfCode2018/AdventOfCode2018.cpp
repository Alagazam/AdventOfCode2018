#include <iostream>
#include "../day01/day01.h"
#include "../day02/day02.h"
#include "../day03/day03.h"
#include "../day04/day04.h"
#include "../day05/day05.h"
#include "../day06/day06.h"
#include "../day07/day07.h"
#include "../day08/day08.h"
#include "../day09/day09.h"
#include "../day10/day10.h"
#include "../day11/day11.h"

int main(int argc, char *argv[])
{
	try {
		int day = 0;
		if (argc == 2) day = std::stoi(argv[1]);

		if (day == 0 || day == 1)	std::cout << "Day 01 A=" << aoc2018_01::Solve_A() << " B=" << aoc2018_01::Solve_B() << "\n";
		if (day == 0 || day == 2)	std::cout << "Day 02 A=" << aoc2018_02::Solve_A() << " B=" << aoc2018_02::Solve_B() << "\n";
		if (day == 0 || day == 3)	std::cout << "Day 03 " << aoc2018_03::Solve_AB() << "\n";
		if (day == 0 || day == 4)	std::cout << "Day 04 " << aoc2018_04::Solve_AB() << "\n";
		if (day == 0 || day == 5)	std::cout << "Day 05 A=" << aoc2018_05::Solve_A() << " B=" << aoc2018_05::Solve_B() << "\n";
		if (day == 0 || day == 6)	std::cout << "Day 06 A=" << aoc2018_06::Solve_A() << " B=" << aoc2018_06::Solve_B() << "\n";
		if (day == 0 || day == 7)	std::cout << "Day 07 A=" << aoc2018_07::Solve_A() << " B=" << aoc2018_07::Solve_B() << "\n";
		if (day == 0 || day == 8)	std::cout << "Day 08 A=" << aoc2018_08::Solve_A() << " B=" << aoc2018_08::Solve_B() << "\n";
		if (day == 0 || day == 9)	std::cout << "Day 09 A=" << aoc2018_09::Solve_A() << " B=" << aoc2018_09::Solve_B() << "\n";
		if (day == 0 || day == 10)	std::cout << "Day 10 AB=" << aoc2018_10::Solve_AB() << "\n";
		if (day == 0 || day == 11)	std::cout << "Day 11 A=" << aoc2018_11::Solve_A() << " B=" << aoc2018_11::Solve_B() << "\n";
	}
	catch (std::runtime_error e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
}
