#include "table.h"
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <stdexcept>

#define PRINT_DEBUG(...) printf(__VA_ARGS__)

static int64_t syms_sum_(std::string_view str) noexcept
{
	int64_t sum{};
	for (char c : str)
		sum += (unsigned)c;
	return sum;
}

static size_t hash_function_(std::size_t key, double A, std::size_t m)
{
	auto frac_part = A * (double)key - floor(A * (double)key); // Дробная часть
	assert(frac_part < 1), assert(frac_part >= 0);
	return (size_t)((double)m * frac_part); // Дробная часть * число элементов
}

void Table::push(std::string_view key)
{
	auto syms_sum = syms_sum_(key);
	if (syms_sum < 0)
		throw std::length_error{"Слишком большая строка!"};

	auto hf_ret = hash_function_((size_t)syms_sum, A, N);
	assert(hf_ret < N);
	srand((uint32_t)hf_ret);	

	size_t id = (size_t)rand() % N;
	PRINT_DEBUG("rand: %lu\n", id);
	data_[id] = key;
	// data_[hash_function_((size_t)syms_sum, A, N)] = key;
}

auto Table::get(std::string_view key) const -> std::optional<std::string_view>
{
	auto syms_sum = syms_sum_(key);
	if (syms_sum < 0)
		return std::nullopt;

	auto hf_ret = hash_function_((size_t)syms_sum, A, N);
	assert(hf_ret < N);
	srand((uint32_t)hf_ret);	

	size_t id = (size_t)rand() % N;
	PRINT_DEBUG("rand: %lu\n", id);
	return data_[id];
	// return data_[hash_function_((size_t)syms_sum, A, N)];
}
