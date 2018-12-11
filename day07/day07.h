#pragma once
#include "..\common\inputReader.h"

namespace aoc2018_07 {

std::string	buildOrder(const aoc2018::inputContent &input)
{
	std::map<char, std::set<char>> dependencies;
	std::string		order;

	// set up all dependencies
	for (auto row : input)
	{
		if (dependencies.find(row[1][0]) == dependencies.end())	// dont miss "root" steps
			dependencies[row[1][0]] = {};
		dependencies[row[7][0]].insert(row[1][0]);
	}

	while (!dependencies.empty())
	{
		auto nextStep = std::find_if(dependencies.begin(), dependencies.end(), 
			[](const decltype(*dependencies.begin()) & dep) ->bool { return dep.second.empty(); }
		);
		auto step = nextStep->first;
		order += step;
		dependencies.erase(step);
		for (auto &dep : dependencies)
		{
			dep.second.erase(step);
		}
	}

	return order;
}

std::string Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day07.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  buildOrder(input);
}

int	build(const aoc2018::inputContent &input, int noWorkers, int workOvertime)
{
	std::map<char, std::set<char>> dependencies;
	std::string		order;
	int		time{ 0 };

	// set up all dependencies
	for (auto row : input)
	{
		if (dependencies.find(row[1][0]) == dependencies.end())	// dont miss "root" steps
			dependencies[row[1][0]] = {};
		dependencies[row[7][0]].insert(row[1][0]);
	}

	struct Worker
	{
		char	step{ 0 };
		int		workLeft{ 0 };
	};
	std::vector<Worker> workers(noWorkers);

	while (!dependencies.empty() || std::any_of(workers.begin(),workers.end(), [](const Worker& worker) ->bool { return worker.step != 0; }))
	{
		bool loop = true;
		while (loop)
		{
			loop = false;
			// check if some worker is ready for next step
			auto workerReady = std::find_if(workers.begin(), workers.end(), [](const Worker& worker) ->bool { return worker.step == 0; });
			if (workerReady != workers.end())
			{
				auto nextStep = std::find_if(dependencies.begin(), dependencies.end(),
					[](const decltype(*dependencies.begin()) & dep) ->bool { return dep.second.empty(); }
				);
				// There are a next step available
				if (nextStep != dependencies.end())
				{
					loop = true;
					auto step = nextStep->first;
					order += step;
					workerReady->step = step;
					workerReady->workLeft = (step - 'A' + 1) + workOvertime;
					dependencies.erase(nextStep);
				}
			}
		}
		// execute work
		for (auto &worker : workers)
		{
			--worker.workLeft;
			if (worker.workLeft == 0)
			{
				auto step = worker.step;
				for (auto &dep : dependencies)
				{
					dep.second.erase(step);
				}
				worker.step = 0;
			}
		}
		++time;
	}

	return time;
}

int Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day07.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  build(input, 5, 60);
}


}