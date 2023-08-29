#include "Table.hpp"
#include <random>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

Table::Table(size_t width, size_t height, int val) : width_(width), height_(height)
// PLACE A ':' HERE FOLLOWED BY ANY MEMBER VARIABLE INITIALIZIONS
{
  // ADDITIONAL SETUP FOR THE CONSTRUCTOR
  table_.resize(height_, row_t(width_, val));
}

// WRITE THE DEFINITION FOR Table::PrintTable
void Table::PrintTable(std::ostream & out) const{
  for (size_t i = 0; i < table_.size(); ++i) {
      for (size_t j = 0; j < table_[i].size(); ++j) {
        out << table_[i][j] << ", ";
      }
      out << '\n';
    }
}

// WRITE THE DEFINITION FOR Table::FillRandom
void Table::FillRandom(int low, int high, int seed){
  std::mt19937 generator(seed);
  std::uniform_int_distribution<int> distribution(low, high);
  for (size_t i = 0; i < table_.size(); ++i){
    for (size_t j = 0; j < table_[i].size(); ++j){      
      table_[i][j] = distribution(generator);
    }
  }
}

// WRITE THE DEFINITION FOR Table::SetValue
bool Table::SetValue(size_t col, size_t row, int val){
  if ((row >= table_.size()) || (col >= table_[0].size())){
    return false;
  }
  table_[row][col] = val;
  return true;
}

// WRITE THE DEFINITION FOR Table::GetValue
int Table::GetValue(size_t col, size_t row) const{
  if ((row >= table_.size()) || (col >= table_[0].size())){
    throw std::out_of_range("Index out of range");
  }
  return table_[row][col];
}