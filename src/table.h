#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <string_view>

template <std::size_t N = 384> class Table {
private:
	static constexpr auto A = .6180339887; // Золотое сечение (по Кнуту)
	using Container = std::array<std::optional<std::string>, N>;
	Container data_;

	static int64_t syms_sum(std::string_view str) noexcept
	{
		int64_t sum{};
		for (char c : str)
			sum += (unsigned)c;
		return sum;
	}

public:
	auto get(std::string_view key) const -> std::optional<std::string> const &;

	auto get(std::string_view key) -> std::optional<std::string> &;

	void push(std::string_view key);

	auto capacity() const noexcept { return data_.size(); }
};

template <std::size_t N> void Table<N>::push([[maybe_unused]] std::string_view key) {}

template <std::size_t N>
auto Table<N>::get([[maybe_unused]] std::string_view key) const -> std::optional<std::string> const &
{
	return data_[0];
}

template <std::size_t N> auto Table<N>::get([[maybe_unused]] std::string_view key) -> std::optional<std::string> &
{
	return data_[0];
}
