#pragma once
#include <sstream>
#include <iostream>
#include <vector>

// A Table of integer values.
class Table {
 private:
  using row_t = std::vector<int>;  // Each row is a regular vector of int.
  std::vector<row_t> table_;       // Table is a vector of rows.
  size_t width_;                   // How wide is table_ (how many columns)?
  size_t height_;                  // How high is table_ (how many rows)?

 public:
  // table will be width x height, default val is 0
  Table(size_t width, size_t height, int val = 0);

  // Pre-made member functions to access the width and height variables.
  size_t GetWidth() const { return width_; }
  size_t GetHeight() const { return height_; }

  // Function to print the tables's contents to a provided output stream.
  void PrintTable(std::ostream &) const;

  // range from low to high, seed has default of 0
  void FillRandom(int low, int high, int seed = 0);

  // Accessors to get and set values.
  bool SetValue(size_t col, size_t row, int val);
  int GetValue(size_t col, size_t row) const;
};
