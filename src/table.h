#pragma once
#include <array>
#include <cstddef>
#include <optional>
#include <string>
#include <string_view>

class Table {
private:
	static constexpr std::size_t N = 256;
	static constexpr auto A = .6180339887; // Золотое сечение (по Кнуту)
	using Container = std::array<std::optional<std::string>, N>;
	Container data_;

public:
	auto get(std::string_view key) const noexcept-> std::optional<std::string_view> ;

	void push(std::string_view key);

	auto capacity() const noexcept { return data_.size(); }
};

