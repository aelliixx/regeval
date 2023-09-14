#include <iostream>
#include <libs/Println.hpp>
#include "Regex.h"

consteval int foo(const char* str)
{
	auto n = 0;
	while (str[n] != '\0')
		++n;
	return n;
}

using namespace alx;

int main()
{
	static constexpr const char* regexp = "world";
	static constexpr auto regex = GenerateFsm<Strlen(regexp)>(regexp);
	for (int i = 0; i < 130; ++i)
	{
		print("{}: '{}' => ", i, (char)i);
		for (const auto& c : regex.Cs)
		{
			print("{} ", c.Ts[i]);
		}
		println();
	}
	println("-----------------------");
	std::string tests[] = {"Hello", "Hello world!", "Small world", "world", ""};
	println("Matching pattern: {}", regexp);
	for (const auto& test : tests)
	{
		println("Test: '{}', matches: {}", test, MatchString(regex, test));
	}


	return 0;
}
