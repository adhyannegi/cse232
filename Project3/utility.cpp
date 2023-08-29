#include "utility.hpp"

Order::Order(std::string username1, std::string side1, std::string asset1, int amount1, int price1){
    username = username1;
    side = side1;
    asset = asset1;
    amount = amount1;
    price = price1;
}

Order::Order(const Order & o){
    username = o.username;
    side = o.side;
    asset = o.asset;
    amount = o.amount;
    price = o.price;
}

Order& Order::operator=(const Order & o) {
  if (this != &o) {
    username = o.username;
    side = o.side;
    asset = o.asset;
    amount = o.amount;
    price = o.price;
  }
  return *this;
}

std::ostream& operator<<(std::ostream & oss, const Order & o){
    oss << o.side << " " << o.amount << " " << o.asset << " at " << o.price << " USD by " << o.username;
    return oss;
}

bool operator==(const Order & o1, const Order & o2){
    if ((o1.username == o2.username) && (o1.side == o2.side) && (o1.asset == o2.asset) && (o1.amount == o2.amount) && (o1.price == o2.price)){
        return true;
    }
    return false;
}
