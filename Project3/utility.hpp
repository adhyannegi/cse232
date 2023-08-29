#pragma once
#include <iostream>
#include <string>

struct Order {
  std::string username;
  std::string side;  // Can be "Buy" or "Sell"
  std::string asset;
  int amount;
  int price;
  public:
    Order(std::string username1, std::string side1, std::string asset1, int amount1, int price1);
    Order(const Order & o);
    Order& operator=(const Order & o);
    friend std::ostream& operator<<(std::ostream & oss, const Order & o);
    friend bool operator==(const Order & o1, const Order & o2);
};
