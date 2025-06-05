#include "table.h"
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <stdexcept>

static int64_t syms_sum_(std::string_view str) noexcept
{
	int64_t sum{};
	for (char c : str)
		sum += (unsigned)c;
	return sum;
}

static size_t hash_function_(std::size_t key, [[maybe_unused]] double A, std::size_t m)
{
	return key % m;
}

void Table::push(std::string_view key)
{
	auto syms_sum = syms_sum_(key);
	if (syms_sum < 0)
		throw std::length_error{"Слишком большая строка!"};

	data_[hash_function_((size_t)syms_sum, A, N)] = key;
}

auto Table::get(std::string_view key) const -> std::optional<std::string_view>
{
	auto syms_sum = syms_sum_(key);
	if (syms_sum < 0)
		return std::nullopt;

	return data_[hash_function_((size_t)syms_sum, A, N)];
}
