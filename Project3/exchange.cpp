#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "exchange.hpp"

Exchange::Exchange() { portfolio = {}; }

void Exchange::MakeDeposit(const std::string &username,
                           const std::string &asset, int amount) {
  if (portfolio.find(username) == portfolio.end()) {
    portfolio[username] = std::map<std::string, int>();
    portfolio[username][asset] = amount;
  } else {
    portfolio[username][asset] += amount;
  }
}

void Exchange::PrintUserPortfolios(std::ostream &os) const {
  os << "User Portfolios (in alphabetical order):" << std::endl;
  std::set<std::string> sorted_names;
  for (auto value : portfolio) {
    sorted_names.insert(value.first);
  }
  for (auto it = sorted_names.begin(); it != sorted_names.end(); ++it) {
    os << *it << "'s Portfolio: ";
    for (auto val_it = portfolio.find(*it)->second.begin();
         val_it != portfolio.find(*it)->second.end(); ++val_it) {
      if (val_it->second != 0) {
        os << val_it->second << " " << val_it->first << ", ";
      }
    }
    os << std::endl;
  }
}

bool Exchange::MakeWithdrawal(const std::string &username,
                              const std::string &assent, int amount) {
  auto user = portfolio.find(username);
  if (user == portfolio.end()) {
    return false;
  }
  auto &user_portfolio = user->second;
  auto asset = user_portfolio.find(assent);
  if (asset == user_portfolio.end()) {
    return false;
  }
  if (asset->second < amount) {
    return false;
  }
  asset->second = asset->second - amount;
  return true;
}

void Exchange::AddToOpenOrder(const Order &order) {
  open_orders.push_back(order);
}

void Exchange::AddToFilledOrders(const Order &order) {
  filled_orders.push_back(order);
}

bool Exchange::sell_equal_equal(Order &open_order, const Order &order) {
  auto user = portfolio.find(order.username);
  if (user == portfolio.end()) {
    return false;
  }
  auto &user_portfolio = user->second;
  AddToFilledOrders(open_order);
  user_portfolio["USD"] += (order.price * order.amount);
  // buy part
  auto buy_user = portfolio.find(open_order.username);
  auto &buy_user_portfolio = buy_user->second;
  auto asset = buy_user_portfolio.find(open_order.asset);
  if (asset == buy_user_portfolio.end()) {
    buy_user_portfolio[open_order.asset] = open_order.amount;
  } else {
    buy_user_portfolio[open_order.asset] += open_order.amount;
  }
  buy_user_portfolio["USD"] -= (open_order.amount * open_order.price);
  AddToFilledOrders(order);
  open_orders.erase(
      std::remove(open_orders.begin(), open_orders.end(), open_order),
      open_orders.end());
  // trade
  std::string trade = open_order.username + " Bought " +
                      std::to_string(open_order.amount) + " of " +
                      open_order.asset + " From " + order.username + " for " +
                      std::to_string(open_order.price) + " USD" + "\n";
  trade_history.push_back(trade);
  return true;
}

bool Exchange::sell_less_equal(Order &open_order, const Order &order) {
  auto user = portfolio.find(order.username);
  if (user == portfolio.end()) {
    return false;
  }
  auto &user_portfolio = user->second;
  AddToFilledOrders(open_order);
  user_portfolio["USD"] += (open_order.amount * open_order.price);
  // buy part
  auto buy_user = portfolio.find(open_order.username);
  auto &buy_user_portfolio = buy_user->second;
  auto asset = buy_user_portfolio.find(open_order.asset);
  if (asset == buy_user_portfolio.end()) {
    buy_user_portfolio[open_order.asset] = open_order.amount;
  } else {
    buy_user_portfolio[open_order.asset] += open_order.amount;
  }
  open_orders.erase(
      std::remove(open_orders.begin(), open_orders.end(), open_order),
      open_orders.end());
  Order updated_order({order.username, order.side, order.asset,
                       order.amount - open_order.amount, order.price});
  Order completed_order({order.username, order.side, order.asset,
                         open_order.amount, order.price});
  AddToOpenOrder(updated_order);
  AddToFilledOrders(completed_order);
  // trade
  std::string trade = open_order.username + " Bought " +
                      std::to_string(open_order.amount) + " of " +
                      open_order.asset + " From " + order.username + " for " +
                      std::to_string(open_order.price) + " USD" + "\n";
  trade_history.push_back(trade);
  return true;
}

bool Exchange::sell_greater_equal(Order &open_order, const Order &order) {
  auto user = portfolio.find(order.username);
  if (user == portfolio.end()) {
    return false;
  }
  auto &user_portfolio = user->second;
  AddToFilledOrders(order);
  user_portfolio["USD"] += (order.amount * order.price);
  // buy part
  auto buy_user = portfolio.find(open_order.username);
  auto &buy_user_portfolio = buy_user->second;
  auto asset = buy_user_portfolio.find(open_order.asset);
  if (asset == buy_user_portfolio.end()) {
    buy_user_portfolio[open_order.asset] = order.amount;
  } else {
    buy_user_portfolio[open_order.asset] += order.amount;
  }
  buy_user_portfolio["USD"] -= (order.amount * order.price);
  open_order.amount -= order.amount;
  AddToFilledOrders(order);
  // trade
  std::string trade = open_order.username + " Bought " +
                      std::to_string(order.amount) + " of " + open_order.asset +
                      " From " + order.username + " for " +
                      std::to_string(order.price) + " USD" + "\n";
  trade_history.push_back(trade);
  return true;
}

bool Exchange::sell_greater_greater(Order &open_order, const Order &order) {
  auto user = portfolio.find(order.username);
  if (user == portfolio.end()) {
    return false;
  }
  auto &user_portfolio = user->second;
  AddToFilledOrders(order);
  user_portfolio["USD"] += (order.amount * order.price);
  // buy part
  auto buy_user = portfolio.find(open_order.username);
  auto &buy_user_portfolio = buy_user->second;
  auto asset = buy_user_portfolio.find(open_order.asset);
  if (asset == buy_user_portfolio.end()) {
    buy_user_portfolio[open_order.asset] = order.amount;
  } else {
    buy_user_portfolio[open_order.asset] += order.amount;
  }
  // buy_user_portfolio["USD"] -= (order.amount * order.price);
  Order completed_order({open_order.username, open_order.side, open_order.asset,
                         order.amount, order.price});
  AddToFilledOrders(completed_order);
  open_orders.erase(
      std::remove(open_orders.begin(), open_orders.end(), open_order),
      open_orders.end());
  Order updated_order({open_order.username, open_order.side, open_order.asset,
                       open_order.amount - order.amount, open_order.price});
  AddToOpenOrder(updated_order);
  // trade
  std::string trade = open_order.username + " Bought " +
                      std::to_string(order.amount) + " of " + open_order.asset +
                      " From " + order.username + " for " +
                      std::to_string(order.price) + " USD" + "\n";
  trade_history.push_back(trade);
  return true;
}

bool Exchange::sell_less_greater(Order &open_order, const Order &order) {
  auto user = portfolio.find(order.username);
  if (user == portfolio.end()) {
    return false;
  }
  auto &user_portfolio = user->second;
  for (auto open_order2 : open_orders) {
    if ((open_order2.side == open_order.side) &&
        (open_order2.asset == open_order.asset) &&
        (open_order2.price > open_order.price)) {
      open_order = open_order2;
    }
  }
  user_portfolio["USD"] += (open_order.amount * order.price);
  Order updated_order({order.username, order.side, order.asset,
                       order.amount - open_order.amount, order.price});
  // buy part
  auto buy_user = portfolio.find(open_order.username);
  auto &buy_user_portfolio = buy_user->second;
  auto asset = buy_user_portfolio.find(open_order.asset);
  if (asset == buy_user_portfolio.end()) {
    buy_user_portfolio[open_order.asset] = open_order.amount;
  } else {
    buy_user_portfolio[open_order.asset] += open_order.amount;
  }
  open_orders.erase(
      std::remove(open_orders.begin(), open_orders.end(), open_order),
      open_orders.end());
  Order completed_buy_order({open_order.username, open_order.side,
                             open_order.asset, open_order.amount, order.price});
  AddToFilledOrders(completed_buy_order);
  Order completed_sell_order({order.username, order.side, order.asset,
                              open_order.amount, order.price});
  AddToFilledOrders(completed_sell_order);
  // trade
  std::string trade = open_order.username + " Bought " +
                      std::to_string(open_order.amount) + " of " +
                      open_order.asset + " From " + order.username + " for " +
                      std::to_string(order.price) + " USD" + "\n";
  trade_history.push_back(trade);
  for (auto open_order1 : open_orders) {
    if ((open_order1.side == "Buy") &&
        (open_order1.asset == updated_order.asset) &&
        (open_order1.amount < updated_order.amount) &&
        (open_order1.price > updated_order.price)) {
      user_portfolio[updated_order.asset] += (updated_order.amount);
      AddOrder(updated_order);
      return true;
    }
  }
  AddToOpenOrder(updated_order);
  return true;
}

bool Exchange::sell_order_setup(const Order &order) {
  auto user = portfolio.find(order.username);
  if (user == portfolio.end()) {
    return false;
  }
  auto &user_portfolio = user->second;
  auto asset = user_portfolio.find(order.asset);
  if (asset == user_portfolio.end()) {
    return false;
  }
  if (user_portfolio[order.asset] < order.amount) {
    return false;
  }
  asset->second = asset->second - order.amount;
  for (auto open_order : open_orders) {
    //==
    if ((open_order.side == "Buy") && (open_order.asset == order.asset) &&
        (open_order.amount == order.amount) &&
        (open_order.price == order.price)) {
      return sell_equal_equal(open_order, order);
    }
    //<=
    else if ((open_order.side == "Buy") && (open_order.asset == order.asset) &&
             (open_order.amount < order.amount) &&
             (open_order.price == order.price)) {
      return sell_less_equal(open_order, order);
    }
    //>=
    else if ((open_order.side == "Buy") && (open_order.asset == order.asset) &&
             (open_order.amount > order.amount) &&
             (open_order.price == order.price)) {
      return sell_greater_equal(open_order, order);
    }
    //>>
    else if ((open_order.side == "Buy") && (open_order.asset == order.asset) &&
             (open_order.amount > order.amount) &&
             (open_order.price > order.price)) {
      return sell_greater_greater(open_order, order);
    }
    //<>
    else if ((open_order.side == "Buy") && (open_order.asset == order.asset) &&
             (open_order.amount < order.amount) &&
             (open_order.price > order.price)) {
      return sell_less_greater(open_order, order);
    }
  }
  AddToOpenOrder(order);
  return true;
}

bool Exchange::buy_equal_equal(Order &open_order, const Order &order) {
  auto user = portfolio.find(order.username);
  if (user == portfolio.end()) {
    return false;
  }
  auto &user_portfolio = user->second;
  auto asset = user_portfolio.find(order.asset);
  if (asset == user_portfolio.end()) {
    user_portfolio[order.asset] = order.amount;
  } else {
    user_portfolio[order.asset] += order.amount;
  }
  AddToFilledOrders(order);
  auto sell_user = portfolio.find(open_order.username);
  auto &sell_user_portfolio = sell_user->second;
  sell_user_portfolio["USD"] += (open_order.price * open_order.amount);
  AddToFilledOrders(open_order);
  // removing sell_order from open_orders
  open_orders.erase(
      std::remove(open_orders.begin(), open_orders.end(), open_order),
      open_orders.end());
  // trade
  std::string trade = order.username + " Bought " +
                      std::to_string(order.amount) + " of " + order.asset +
                      " From " + open_order.username + " for " +
                      std::to_string(order.price) + " USD" + "\n";
  trade_history.push_back(trade);
  return true;
}

bool Exchange::buy_less_equal(Order &open_order, const Order &order) {
  auto user = portfolio.find(order.username);
  if (user == portfolio.end()) {
    return false;
  }
  auto &user_portfolio = user->second;
  auto asset = user_portfolio.find(order.asset);
  if (asset == user_portfolio.end()) {
    user_portfolio[order.asset] = open_order.amount;
  } else {
    user_portfolio[order.asset] += open_order.amount;
  }
  open_orders.erase(std::remove(open_orders.begin(), open_orders.end(), order),
                    open_orders.end());
  Order updated_order({order.username, order.side, order.asset,
                       open_order.amount, order.price});
  Order new_order({order.username, order.side, order.asset,
                   order.amount - open_order.amount, order.price});
  AddToFilledOrders(updated_order);
  AddToOpenOrder(new_order);
  // sell part
  auto sell_user = portfolio.find(open_order.username);
  auto &sell_user_portfolio = sell_user->second;
  sell_user_portfolio["USD"] += (open_order.price * open_order.amount);
  AddToFilledOrders(open_order);
  // removing sell_order from open_orders
  open_orders.erase(
      std::remove(open_orders.begin(), open_orders.end(), open_order),
      open_orders.end());
  // trade
  std::string trade = order.username + " Bought " +
                      std::to_string(open_order.amount) + " of " + order.asset +
                      " From " + open_order.username + " for " +
                      std::to_string(order.price) + " USD" + "\n";
  trade_history.push_back(trade);
  return true;
}

bool Exchange::buy_greater_equal(Order &open_order, const Order &order) {
  auto user = portfolio.find(order.username);
  if (user == portfolio.end()) {
    return false;
  }
  auto &user_portfolio = user->second;
  auto asset = user_portfolio.find(order.asset);
  if (asset == user_portfolio.end()) {
    user_portfolio[order.asset] = order.amount;
  } else {
    user_portfolio[order.asset] += order.amount;
  }
  open_orders.erase(std::remove(open_orders.begin(), open_orders.end(), order),
                    open_orders.end());
  // sell part
  auto sell_user = portfolio.find(open_order.username);
  auto &sell_user_portfolio = sell_user->second;
  sell_user_portfolio["USD"] += (order.price * order.amount);
  Order completed_order({open_order.username, open_order.side, open_order.asset,
                         order.amount, open_order.price});
  AddToFilledOrders(completed_order);
  open_order.amount -= order.amount;
  // trade
  std::string trade = order.username + " Bought " +
                      std::to_string(order.amount) + " of " + order.asset +
                      " From " + open_order.username + " for " +
                      std::to_string(order.price) + " USD" + "\n";
  trade_history.push_back(trade);
  return true;
}

bool Exchange::buy_greater_less(Order &open_order, const Order &order) {
  auto user = portfolio.find(order.username);
  if (user == portfolio.end()) {
    return false;
  }
  auto &user_portfolio = user->second;
  // sell part
  for (auto open_order2 : open_orders) {
    if ((open_order2.side == open_order.side) &&
        (open_order2.asset == open_order.asset) &&
        (open_order2.amount < open_order.amount) &&
        (open_order2.price < open_order.price)) {
      open_order = open_order2;
      open_orders.erase(
          std::remove(open_orders.begin(), open_orders.end(), open_order),
          open_orders.end());
      AddToOpenOrder(open_order);
    }
  }
  auto sell_user = portfolio.find(open_order.username);
  auto &sell_user_portfolio = sell_user->second;
  sell_user_portfolio["USD"] += (order.price * order.amount);
  Order completed_order({open_order.username, open_order.side, open_order.asset,
                         order.amount, order.price});
  AddToFilledOrders(completed_order);
  // buy part
  auto asset = user_portfolio.find(order.asset);
  if (asset == user_portfolio.end()) {
    user_portfolio[order.asset] = order.amount;
  } else {
    user_portfolio[order.asset] += order.amount;
  }
  Order completed_buy_order(
      {order.username, order.side, order.asset, order.amount, order.price});
  AddToFilledOrders(completed_buy_order);
  Order updated_sell_order(
      {open_order.username, open_order.side, open_order.asset,
       (open_order.amount - order.amount), open_order.price});
  // to add updated order at its current value and not at the end of the vector
  auto iter = std::find(open_orders.begin(), open_orders.end(), open_order);
  open_orders.erase(
      std::remove(open_orders.begin(), open_orders.end(), open_order),
      open_orders.end());
  open_orders.insert(iter, updated_sell_order);
  // trade
  std::string trade = order.username + " Bought " +
                      std::to_string(order.amount) + " of " + order.asset +
                      " From " + open_order.username + " for " +
                      std::to_string(order.price) + " USD" + "\n";
  trade_history.push_back(trade);
  return true;
}

bool Exchange::buy_less_less(Order &open_order, const Order &order) {
  auto user = portfolio.find(order.username);
  if (user == portfolio.end()) {
    return false;
  }
  auto &user_portfolio = user->second;
  // sell part
  auto sell_user = portfolio.find(open_order.username);
  auto &sell_user_portfolio = sell_user->second;
  sell_user_portfolio["USD"] += (order.price * open_order.amount);
  open_orders.erase(
      std::remove(open_orders.begin(), open_orders.end(), open_order),
      open_orders.end());
  Order completed_order({open_order.username, open_order.side, open_order.asset,
                         open_order.amount, order.price});
  AddToFilledOrders(completed_order);
  // buy part
  auto asset = user_portfolio.find(order.asset);
  if (asset == user_portfolio.end()) {
    user_portfolio[order.asset] = open_order.amount;
  } else {
    user_portfolio[order.asset] += open_order.amount;
  }
  Order completed_buy_order({order.username, order.side, order.asset,
                             open_order.amount, order.price});
  AddToFilledOrders(completed_buy_order);
  Order updated_buy_order({order.username, order.side, order.asset,
                           order.amount - open_order.amount, order.price});
  // trade
  std::string trade = order.username + " Bought " +
                      std::to_string(open_order.amount) + " of " + order.asset +
                      " From " + open_order.username + " for " +
                      std::to_string(order.price) + " USD" + "\n";
  trade_history.push_back(trade);
  for (auto open_order1 : open_orders) {
    //<<
    if ((open_order1.side == "Sell") &&
        (open_order1.asset == updated_buy_order.asset) &&
        (open_order1.amount < updated_buy_order.amount) &&
        (open_order1.price < updated_buy_order.price)) {
      AddOrder(updated_buy_order);
      user_portfolio["USD"] +=
          (updated_buy_order.amount) * updated_buy_order.price;
      return true;
    }
  }
  //><
  for (auto open_order1 : open_orders) {
    if ((open_order1.side == "Sell") &&
        (open_order1.asset == updated_buy_order.asset) &&
        (open_order1.amount > updated_buy_order.amount) &&
        (open_order1.price < updated_buy_order.price)) {
      AddOrder(updated_buy_order);
      user_portfolio["USD"] +=
          (updated_buy_order.amount * updated_buy_order.price);
      return true;
    }
  }
  AddToOpenOrder(updated_buy_order);
  return true;
}

bool Exchange::buy_order_setup(const Order &order) {
  auto user = portfolio.find(order.username);
  if (user == portfolio.end()) {
    return false;
  }
  auto &user_portfolio = user->second;
  int balance = user_portfolio["USD"];
  if (balance < (order.price * order.amount)) {
    return false;
  }
  user_portfolio["USD"] -= (order.price * order.amount);
  for (auto open_order : open_orders) {
    //==
    if ((open_order.side == "Sell") && (open_order.asset == order.asset) &&
        (open_order.amount == order.amount) &&
        (open_order.price == order.price)) {
      return buy_equal_equal(open_order, order);
    }

    //<=
    else if ((open_order.side == "Sell") && (open_order.asset == order.asset) &&
             (open_order.amount < order.amount) &&
             (open_order.price == order.price)) {
      return buy_less_equal(open_order, order);
    }

    //>=
    else if ((open_order.side == "Sell") && (open_order.asset == order.asset) &&
             (open_order.amount > order.amount) &&
             (open_order.price == order.price)) {
      return buy_greater_equal(open_order, order);
    }

    //><
    else if ((open_order.side == "Sell") && (open_order.asset == order.asset) &&
             (open_order.amount > order.amount) &&
             (open_order.price < order.price)) {
      return buy_greater_less(open_order, order);
    }

    //<<
    else if ((open_order.side == "Sell") && (open_order.asset == order.asset) &&
             (open_order.amount < order.amount) &&
             (open_order.price < order.price)) {
      return buy_less_less(open_order, order);
    }
  }
  AddToOpenOrder(order);
  return true;
}

bool Exchange::AddOrder(const Order &order) {
  if (order.side == "Sell") {
    return sell_order_setup(order);
  } else if (order.side == "Buy") {
    return buy_order_setup(order);
  }
  return false;
}

void Exchange::PrintUsersOrders(std::ostream &os) const {
  os << "Users Orders (in alphabetical order):" << std::endl;
  std::set<std::string> sorted_names;
  for (auto value : portfolio) {
    sorted_names.insert(value.first);
  }
  for (auto it = sorted_names.begin(); it != sorted_names.end(); ++it) {
    os << *it << "'s Open Orders (in chronological order):" << std::endl;
    for (auto order : open_orders) {
      if ((order.username == *it)) {
        os << order << std::endl;
      }
    }
    os << *it << "'s Filled Orders (in chronological order):" << std::endl;
    for (auto order : filled_orders) {
      if ((order.username == *it)) {
        os << order << std::endl;
      }
    }
  }
}

void Exchange::PrintTradeHistory(std::ostream &os) const {
  os << "Trade History (in chronological order):\n";
  for (auto trade : trade_history) {
    os << trade;
  }
}

bool sortByAsset(const Order &order1, const Order &order2) {
  return order1.asset < order2.asset;
}

std::vector<int> bids_calculator(std::vector<Order> sortedOrders, Order order) {
  std::vector<int> bids;
  int highest_open_buy = 0;
  int lowest_open_sell = 9999;
  for (auto order1 : sortedOrders) {
    if (order1.asset == order.asset) {
      // buy
      if (order1.side == "Buy") {
        if (order1.price > highest_open_buy) {
          highest_open_buy = order1.price;
        }
      }
      // sell
      else if (order1.side == "Sell") {
        if (order1.price < lowest_open_sell) {
          lowest_open_sell = order1.price;
        }
      }
    }
  }
  bids.push_back(highest_open_buy);
  bids.push_back(lowest_open_sell);
  return bids;
}

void Exchange::PrintBidAskSpread(std::ostream &os) const {
  std::vector<std::string> printed_vals;
  std::vector<Order> sortedOrders = open_orders;
  std::sort(sortedOrders.begin(), sortedOrders.end(), sortByAsset);
  os << "Asset Bid Ask Spread (in alphabetical order):\n";

  for (auto order : sortedOrders) {
    std::vector<int> bids = bids_calculator(sortedOrders, order);
    int highest_open_buy = bids[0];
    int lowest_open_sell = bids[1];
    if (std::find(printed_vals.begin(), printed_vals.end(), order.asset) ==
        printed_vals.end()) {
      printed_vals.push_back(order.asset);
    } else {
      continue;
    }
    os << order.asset << ": Highest Open Buy = ";
    if (highest_open_buy == 0) {
      os << "NA USD";
    } else {
      os << highest_open_buy << " USD";
    }
    os << " and Lowest Open Sell = ";
    if (lowest_open_sell == 9999) {
      os << "NA USD";
    } else {
      os << lowest_open_sell << " USD";
    }
    os << "\n";
  }
}