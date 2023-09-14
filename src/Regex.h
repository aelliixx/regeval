//
// Created by aelliixx on 2023-09-14.
//

#pragma once
#include <array>
#include <cinttypes>
#include <vector>
namespace alx {

#define REGEXP_EOL 128
#define COLUMN_SIZE 130

constexpr int Strlen(const char* str)
{
	auto n = 0;
	while (str[n] != '\0')
		++n;
	return n;
}

struct FsmColumn
{
	uint8_t Ts[COLUMN_SIZE];
};

template<int size>
struct Fsm
{
	FsmColumn Cs[size];
};

template<int size>
consteval Fsm<size + 1> GenerateFsm(const char* regexp)
{
	Fsm<size + 1> fsm{};
	for (auto i = 0; i < size; ++i)
	{
		FsmColumn column{};
		switch (regexp[i])
		{
		case '^':
			continue;
		case '$':
			column.Ts[REGEXP_EOL] = i + 2;
			break;
		case '.':
			for (int j = 32; j <= 126; ++j)
				column.Ts[j] = i + 2;
			break;
		default:
			column.Ts[regexp[i]] = i + 2;
		}
		fsm.Cs[i + 1] = column;
	}
	return fsm;
}

template<int size>
bool MatchString(const Fsm<size>& regexp, const std::string& input)
{
	int state = 1;
	for (char i : input)
	{
		if (state == 0 || state >= size)
			break;
		state = regexp.Cs[state].Ts[i];
	}

	if (state == 0)
		return false;

	if (state < size)
		state = regexp.Cs[state].Ts[REGEXP_EOL];
	
	return state >= size;
}

} // alx

