#include <print>
#include "table.h"

int main()
{
	Table t;
	std::println("{}",t.capacity());
	std::println("{}",t.get("").value_or("Empty"));
	std::println("Hello World!");
}
