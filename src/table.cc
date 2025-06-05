#include "table.h"
#include <cstdint>
#include <stdexcept>

static int64_t syms_sum_(std::string_view str) noexcept
{
	int64_t sum{};
	for (char c : str)
		sum += (unsigned)c;
	return sum;
}

void Table::push(std::string_view key)
{
	auto syms_sum = syms_sum_(key);
	if (syms_sum < 0)
		throw std::length_error{"Слишком большая строка!"};

	data_[(size_t)syms_sum % N] = key;
}

auto Table::get(std::string_view key) const -> std::optional<std::string_view>
{
	auto syms_sum = syms_sum_(key);
	if (syms_sum < 0)
		return std::nullopt;

	return data_[(size_t)syms_sum % N];
}
