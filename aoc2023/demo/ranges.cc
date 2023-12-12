module;

#include <algorithm>
#include <iostream>
#include <ranges>
#include <string_view>
#include <vector>

export module test_ranges;

export namespace test_ranges {
using namespace std::literals;

void example(void) {
  static auto const ints = {0, 1, 2, 3, 4, 5};
  auto even = [](int i) { return 0 == i % 2; };
  auto square = [](int i) { return i * i; };

  // the "pipe" syntax of composing the views:
  for (int i : ints | std::views::filter(even) | std::views::transform(square))
    std::cout << i << ' ';

  std::cout << '\n';

  // a traditional "functional" composing syntax:
  // Views are build on top of ranges
  for (int i : std::views::transform(std::views::filter(ints, even), square))
    std::cout << i << ' ';

  // std::copy_if
  // std::vector<int> numbers = {1, 2, 3, 4, 5};
  // std::copy_if(begin(numbers), end(numbers), std::back_inserter(numbers),
  //              [](int n) { return n % 2 == 0; });

  // for (auto n : numbers)
  //   std::cout << n << "\n";

  for (int year : std::views::iota(2020) |
                      std::views::take_while([](int y) { return y <= 2023; }))
    std::cout << year << ' ';
  std::cout << '\n';

  const auto bits = {"https"sv, "//"sv, "cppreference"sv, "."sv, "com"sv};
  // Initializer list
}
} // namespace test_ranges