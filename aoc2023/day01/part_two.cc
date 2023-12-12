module;

#include <algorithm>
#include <iostream>
#include <ranges>
#include <string_view>
#include <unordered_map>

export module part_two;

export namespace part_two {
std::unordered_map<std::string_view, int64_t> digit_map = {
    {"1", 1},     {"2", 2},     {"3", 3},    {"4", 4},    {"5", 5},
    {"6", 6},     {"7", 7},     {"8", 8},    {"9", 9},    {"one", 1},
    {"two", 2},   {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6},
    {"seven", 7}, {"eight", 8}, {"nine", 9}};

int64_t solve(std::string_view input) {
  // The less inspiration from other people, the uglier it looks ...
  // But it will get better.
  return std::ranges::fold_left(
      input | std::views::split('\n'), 0z, [&](int64_t sum, auto &&line) {
        int64_t first_digit = -1;
        int64_t last_digit = -1;
        for (auto pos : std::views::iota(line.begin(), line.end())) {
          auto sub_str = std::string_view(pos, line.end() - pos);
          for (const auto &digit_ : digit_map) {
            if (sub_str.starts_with(digit_.first)) {
              int64_t digit = digit_.second;
              if (first_digit == -1)
                first_digit = digit;
              last_digit = digit;
            }
          }
        }
        return sum + first_digit * 10 + last_digit;
      });
}
} // namespace part_two