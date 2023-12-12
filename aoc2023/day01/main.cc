#include <iostream>

import input;
import part_one;
import part_two;

int main() {
  std::cout << "Result (Part-1): "
            << part_one::get_callibration_value(input::day01) << "\n";
  std::cout << "Result (Part-2): "
            << part_two::first_time_basement(input::day01) << "\n";
}