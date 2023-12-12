module;

#include <algorithm>
#include <cctype>
#include <ranges>
#include <string_view>

export module part_one;

export namespace part_one {
int64_t solve(std::string_view input) {
  // For the first part, I needed some inspiration from other people to write it
  // in a modern way.
  constexpr auto lambda_digit = [](char c) { return !isdigit(c); };
  constexpr auto first_digit = std::views::drop_while(lambda_digit);
  constexpr auto last_digit = std::views::reverse | first_digit;

  return std::ranges::fold_left(
      input | std::views::split('\n'), 0z, [&](int64_t sum, auto &&line) {
        auto first_digit_ = line | first_digit;
        auto last_digit_ = line | last_digit;
        return sum + (*first_digit_.begin() - '0') * 10 +
               (*last_digit_.begin() - '0');
      });
}
} // namespace part_one