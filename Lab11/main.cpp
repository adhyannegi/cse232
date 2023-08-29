#include <exception>
#include <iostream>
#include "Table.cpp"

int main() {
  std::cout << std::boolalpha;

  Table my_table(5, 5);
  std::cout << "Initial Table:\n";
  my_table.PrintTable(std::cout);
  std::cout << std::endl;

  my_table.FillRandom(1, 10);
  std::cout << "Random Table:\n";
  my_table.PrintTable(std::cout);
  std::cout << std::endl;

  bool result_bool = my_table.SetValue(100, 100, 100);
  std::cout << "Set illegal value (should return false). Result: " << result_bool << std::endl;
  std::cout << std::endl;

  int result_int = my_table.GetValue(3, 2);
  std::cout << "Value at 3,2: " << result_int << std::endl;
  try {
    result_int = my_table.GetValue(100, 100);
  } catch (std::out_of_range& e) {
    std::cout << "Correct - threw out-of-range exception!" << std::endl;
  }
  std::cout << std::endl;

  for (int i = 0; i < 5; i++) {
    result_bool = my_table.SetValue(i, i + 1, i * i);
    std::cout << "Set " << i << "," << (i+1) << " to " << (i*i);
    if (!result_bool) std::cout << " (failed)";
    std::cout << "\n";
  }

  std::cout << "\nFinal Table:\n";
  my_table.PrintTable(std::cout);
  std::cout << std::endl;
}
