#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <string_view>

template <std::size_t N = 384> class Table {
private:
	using Container = std::array<std::optional<std::string>, N>;
	Container data_;

	void push_(std::string_view key, bool replace);

	static int64_t syms_sum(std::string_view str) const noexcept;

public:
	auto get(std::string_view key) const -> std::optional<std::string> const &;

	auto get(std::string_view key) -> std::optional<std::string> &;

	void push_or_replace(std::string_view key) { push_(key, true); }

	void push_no_replace(std::string_view key) { push_(key, false); }

	auto capacity() const noexcept { return data_.size(); }
};

template <std::size_t N> void Table<N>::push_([[maybe_unused]] std::string_view key, [[maybe_unused]] bool replace) {}

template <std::size_t N>
auto Table<N>::get([[maybe_unused]] std::string_view key) const -> std::optional<std::string> const &
{
	return data_[0];
}

template <std::size_t N> auto Table<N>::get([[maybe_unused]] std::string_view key) -> std::optional<std::string> &
{
	return data_[0];
}

template <std::size_t N> static int64_t Table<N>::syms_sum(std::string_view str) const noexcept
{
	int64_t sum{};
	for (char c : str)
		sum += (unsigned)c;
	return sum;
}
