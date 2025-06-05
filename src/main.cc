#include <print>
#include "table.h"

int main()
{
	Table t;
	t.push("Sample Text");
	std::println("{}",t.get("Hello World").value_or("Empty"));
	std::println("{}",t.get("Sample Text").value_or("Empty"));
}
