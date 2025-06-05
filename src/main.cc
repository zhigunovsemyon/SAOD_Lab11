#include <print>
#include <iostream>
#include "table.h"

int main()
{
	std::array<const char *, 5> countries {"Russia", "USA", "Germany", "Japan", "UK"};
	Table t;
	for (auto const & c : countries)
		t.push(c);

	std::string guess;
	std::cin >> guess;
	std::println("{}",t.get(guess).value_or("No such country in list!"));
}
