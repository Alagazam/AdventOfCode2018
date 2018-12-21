#pragma once
#include "..\common\inputReader.h"
#include <array>
#include <set>
#include <map>

namespace aoc2018_16 {

using	state_t = std::array<int, 4>;

state_t	parseState(const aoc2018::rowContent &row)
{
	state_t	state;
	state[0] = std::stoi(row[1].substr(1));
	state[1] = std::stoi(row[2]);
	state[2] = std::stoi(row[3]);
	state[3] = std::stoi(row[4]);
	return state;
}

struct	instruction_t
{
	int operation{ 0 };
	int	opA{ 0 };
	int opB{ 0 };
	int opC{ 0 };
};

instruction_t	parseInstruction(const aoc2018::rowContent &row)
{
	instruction_t	instruction;
	instruction.operation = std::stoi(row[0]);
	instruction.opA = std::stoi(row[1]);
	instruction.opB = std::stoi(row[2]);
	instruction.opC = std::stoi(row[3]);
	return instruction;
}

enum class opCode { addr, addi, mulr, muli, banr, bani, borr, bori, setr, seti, gtir, gtri, gtrr, eqir, eqri, eqrr };
std::array<opCode, 16>	opCodeMapping{ opCode::addr, opCode::addi, opCode::mulr, opCode::muli, opCode::banr, opCode::bani, opCode::borr, opCode::bori, 
										opCode::setr, opCode::seti, opCode::gtir, opCode::gtri, opCode::gtrr, opCode::eqir, opCode::eqri, opCode::eqrr };

opCode	translateToOp(int operation)
{
	return opCodeMapping[operation];
}

state_t	execute(const instruction_t &instruction, state_t state)
{
	switch (translateToOp(instruction.operation))
	{
	//Addition:
	//addr (add register) stores into register C the result of adding register A and register B.
	case opCode::addr:	state[instruction.opC] = state[instruction.opA] + state[instruction.opB]; break;
	//addi (add immediate) stores into register C the result of adding register A and value B.
	case opCode::addi:	state[instruction.opC] = state[instruction.opA] + instruction.opB; break;

	//Multiplication:
	//mulr (multiply register) stores into register C the result of multiplying register A and register B.
	case opCode::mulr:	state[instruction.opC] = state[instruction.opA] * state[instruction.opB]; break;
	//muli (multiply immediate) stores into register C the result of multiplying register A and value B.
	case opCode::muli:	state[instruction.opC] = state[instruction.opA] * instruction.opB; break;

	//Bitwise AND:
	//banr (bitwise AND register) stores into register C the result of the bitwise AND of register A and register B.
	case opCode::banr:	state[instruction.opC] = state[instruction.opA] & state[instruction.opB]; break;
	//bani (bitwise AND immediate) stores into register C the result of the bitwise AND of register A and value B.
	case opCode::bani:	state[instruction.opC] = state[instruction.opA] & instruction.opB; break;

	//Bitwise OR:
	//borr (bitwise OR register) stores into register C the result of the bitwise OR of register A and register B.
	case opCode::borr:	state[instruction.opC] = state[instruction.opA] | state[instruction.opB]; break;
	//bori (bitwise OR immediate) stores into register C the result of the bitwise OR of register A and value B.
	case opCode::bori:	state[instruction.opC] = state[instruction.opA] | instruction.opB; break;

	//Assignment:
	//setr (set register) copies the contents of register A into register C. (Input B is ignored.)
	case opCode::setr:	state[instruction.opC] = state[instruction.opA]; break;
	//seti (set immediate) stores value A into register C. (Input B is ignored.)
	case opCode::seti:	state[instruction.opC] = instruction.opA; break;

	//Greater-than testing:
	//gtir (greater-than immediate/register) sets register C to 1 if value A is greater than register B. Otherwise, register C is set to 0.
	case opCode::gtir:	state[instruction.opC] = instruction.opA > state[instruction.opB] ? 1 : 0; break;
	//gtri (greater-than register/immediate) sets register C to 1 if register A is greater than value B. Otherwise, register C is set to 0.
	case opCode::gtri:	state[instruction.opC] = state[instruction.opA] > instruction.opB ? 1 : 0; break;
	//gtrr (greater-than register/register) sets register C to 1 if register A is greater than register B. Otherwise, register C is set to 0.
	case opCode::gtrr:	state[instruction.opC] = state[instruction.opA] > state[instruction.opB] ? 1 : 0; break;

	//Equality testing:
	//eqir (equal immediate/register) sets register C to 1 if value A is equal to register B. Otherwise, register C is set to 0.
	case opCode::eqir:	state[instruction.opC] = instruction.opA == state[instruction.opB] ? 1 : 0; break;
	//eqri (equal register/immediate) sets register C to 1 if register A is equal to value B. Otherwise, register C is set to 0.
	case opCode::eqri:	state[instruction.opC] = state[instruction.opA] == instruction.opB ? 1 : 0; break;
	//eqrr (equal register/register) sets register C to 1 if register A is equal to register B. Otherwise, register C is set to 0.
	case opCode::eqrr:	state[instruction.opC] = state[instruction.opA] == state[instruction.opB] ? 1 : 0; break;
	}
	return state;
}

int	opCodesBeahveLikeThreeOrMore(const aoc2018::inputContent &input)
{
	int	moreThanTreeMatcher{ 0 };
	for (auto rowIt = input.cbegin(); rowIt != input.cend(); )
	{
		if (rowIt->size() == 0) break;
		// read initial state
		auto initState = parseState(*rowIt);
		++rowIt;

		if (rowIt->size() == 0) break;
		// read instruction
		auto instruction = parseInstruction(*rowIt);
		++rowIt;

		if (rowIt->size() == 0) break;
		// read expected state
		auto expectedState = parseState(*rowIt);
		++rowIt;

		// Test all instructions
		int matches{ 0 };
		for (int i = 0; i != 16; ++i)
		{
			instruction.operation = i;
			auto resultState = execute(instruction, initState);
			if (resultState == expectedState)	++matches;
			if (matches >= 3) break;
		}
		if (matches >= 3) ++moreThanTreeMatcher;

		if (rowIt != input.cend()) ++rowIt;
	}
	return moreThanTreeMatcher;
}

aoc2018::inputContent::const_iterator	workOutOpCodeMapping(const aoc2018::inputContent &input)
{
	std::map<int, std::set<int>>	candidates;

	auto rowIt = input.cbegin();
	for (; rowIt != input.cend(); )
	{
		if (rowIt->size() == 0) break;
		// read initial state
		auto initState = parseState(*rowIt);
		++rowIt;

		if (rowIt->size() == 0) break;
		// read instruction
		auto instruction = parseInstruction(*rowIt);
		++rowIt;

		if (rowIt->size() == 0) break;
		// read expected state
		auto expectedState = parseState(*rowIt);
		++rowIt;

		// Test all instructions
		int	originalOperation = instruction.operation;
		for (int i = 0; i != 16; ++i)
		{
			instruction.operation = i;
			auto resultState = execute(instruction, initState);
			if (resultState == expectedState)
			{
				candidates[originalOperation].insert(i);
			}
		}
		if (rowIt != input.cend()) ++rowIt;
	}
	std::array<opCode, 16>	resolvedMapping{ opCode::addr };
	while (candidates.size() != 0)
	{
		auto	singleCandidate = std::find_if(candidates.begin(), candidates.end(), [](auto &cand) {return cand.second.size() == 1; });
		if (singleCandidate == candidates.end()) break;
		auto	operation = *singleCandidate->second.begin();
		resolvedMapping[singleCandidate->first] = opCodeMapping[operation];
		for (auto &cand : candidates)
		{
			cand.second.erase(operation);
		}
		for (auto cand = candidates.begin(); cand != candidates.end(); ++cand)
		{
			if (cand->second.size() == 0)
			{
				candidates.erase(cand);
				cand = candidates.begin();
				if (cand == candidates.end()) break;
			}
		}
	}
	opCodeMapping = resolvedMapping;
	return rowIt;
}

state_t	executeProgram(const aoc2018::inputContent &input, aoc2018::inputContent::const_iterator	rowIt)
{
	state_t	state{ 0,0,0,0 };
	for ( ; rowIt != input.end(); ++rowIt)
	{
		if (rowIt->size() == 0) continue;

		auto	instruction{ parseInstruction(*rowIt) };
		state = execute(instruction, state);
	}
	return state;
}

int Solve_A()
{
	auto	file = aoc2018::OpenInputFile("day16.txt");
	auto	input = aoc2018::ReadInput(*file);
	return  opCodesBeahveLikeThreeOrMore(input);
}

int Solve_B()
{
	auto	file = aoc2018::OpenInputFile("day16.txt");
	auto	input = aoc2018::ReadInput(*file);
	auto	parsePoint = workOutOpCodeMapping(input);
	return  executeProgram(input, parsePoint)[0];
}

}