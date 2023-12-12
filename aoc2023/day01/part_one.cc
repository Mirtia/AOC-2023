module;

#include <algorithm>
#include <cctype>
#include <ranges>
#include <string_view>

export module part_one;

export namespace part_one {
int64_t get_callibration_value(std::string_view input) {
  constexpr auto lambda_digit = [](char c) { return !isdigit(c); };
  constexpr auto first_digit = std::views::drop_while(lambda_digit);
  constexpr auto last_digit = std::views::reverse | first_digit;

  // constexpr auto decimal = [](auto &&rng) -> int64_t {
  //   return *rng.begin() - '0';
  // };

  // return std::ranges::fold_left(
  //     input | std::views::split('\n'), 0z, [&](int64_t acc, auto &&line) {
  //       return acc + decimal(line | first_digit) * 10 +
  //              decimal(line | last_digit);
  //     });
}
} // namespace part_one