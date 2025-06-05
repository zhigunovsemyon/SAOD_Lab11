#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

template <std::size_t N = 384> class Table {
private:
	static constexpr auto A = .6180339887; // Золотое сечение (по Кнуту)
	using Container = std::array<std::optional<std::string>, N>;
	Container data_;

	static int64_t syms_sum_(std::string_view str) noexcept
	{
		int64_t sum{};
		for (char c : str)
			sum += (unsigned)c;
		return sum;
	}

public:
	auto get(std::string_view key) const -> std::optional<std::string_view>;

	void push(std::string_view key);

	auto capacity() const noexcept { return data_.size(); }
};

template <std::size_t N> void Table<N>::push(std::string_view key) 
{
	auto syms_sum = syms_sum_(key);
	if (syms_sum < 0)
		throw std::length_error{"Слишком большая строка!"};
}

template <std::size_t N>
auto Table<N>::get([[maybe_unused]] std::string_view key) const -> std::optional<std::string_view>
{
	return data_[0];
}
