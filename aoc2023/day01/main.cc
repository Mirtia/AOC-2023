#include <iostream>

import input;
import part_one;
import part_two;

int main() {
  std::cout << "Result (Part-1): " << part_one::solve(input::day01) << "\n";
  std::cout << "Result (Part-2): " << part_two::solve(input::day01) << "\n";
}