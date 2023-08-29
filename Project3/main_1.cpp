#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

#include "exchange.cpp"
#include "useraccount.hpp"
#include "utility.cpp"

int main() {
Exchange e;
  std::ostringstream oss;
  e.MakeDeposit("Nahum", "BTC", 1000);
  e.MakeDeposit("Nahum", "USD", 100000);
  e.MakeDeposit("Dolson", "USD", 555555);
  e.MakeDeposit("Ofria", "ETH", 678);
  e.MakeDeposit("Zaabar", "USD", 12121212);
  e.MakeDeposit("Zaabar", "LTC", 4563);
  // BTC rough price 1000
  // ETH rough price 100
  // LTC rough price 500
  e.AddOrder({"Nahum", "Sell", "BTC", 5, 1100});
  e.AddOrder({"Nahum", "Sell", "BTC", 100, 1200});
  e.AddOrder({"Nahum", "Buy", "BTC", 7, 800});
  e.AddOrder({"Dolson", "Buy", "BTC", 1, 950});
  e.AddOrder({"Ofria", "Sell", "ETH", 12, 156});
  e.AddOrder({"Ofria", "Sell", "ETH", 10, 160});
  e.AddOrder({"Zaabar", "Sell", "LTC", 10, 550});
  e.AddOrder({"Zaabar", "Buy", "LTC", 10, 450});
  e.AddOrder({"Nahum", "Buy", "LTC", 55, 600});
  e.AddOrder({"Nahum", "Buy", "ETH", 30, 158});
  e.AddOrder({"Ofria", "Sell", "ETH", 10, 140});
  e.AddOrder({"Zaabar", "Buy", "BTC", 10, 1500});
  e.AddOrder({"Zaabar", "Buy", "ETH", 200, 1200});
  e.AddOrder({"Nahum", "Sell", "BTC", 30, 158});
  e.AddOrder({"Dolson", "Buy", "BTC", 20, 2000});
  e.AddOrder({"Nahum", "Sell", "ETH", 1, 1423});
  e.PrintUserPortfolios(std::cout);
  oss.str("");
  e.PrintUserPortfolios(oss);
  std::cout << (oss.str() == "User Portfolios (in alphabetical order):\nDolson's Portfolio: 21 BTC, 514605 USD, \nNahum's Portfolio: 872 BTC, 21 ETH, 10 LTC, 112924 USD, \nOfria's Portfolio: 646 ETH, 15296 USD, \nZaabar's Portfolio: 10 BTC, 10 ETH, 4553 LTC, 11867712 USD, \n") << std::endl;
  e.PrintUsersOrders(std::cout);
  oss.str("");
  e.PrintUsersOrders(oss);
  std::cout << (oss.str() == "Users Orders (in alphabetical order):\nDolson's Open Orders (in chronological order):\nDolson's Filled Orders (in chronological order):\nBuy 1 BTC at 158 USD by Dolson\nBuy 20 BTC at 2000 USD by Dolson\nNahum's Open Orders (in chronological order):\nSell 95 BTC at 1200 USD by Nahum\nBuy 45 LTC at 600 USD by Nahum\nBuy 8 ETH at 158 USD by Nahum\nSell 2 BTC at 158 USD by Nahum\nSell 1 ETH at 1423 USD by Nahum\nNahum's Filled Orders (in chronological order):\nBuy 10 LTC at 600 USD by Nahum\nBuy 12 ETH at 158 USD by Nahum\nBuy 10 ETH at 140 USD by Nahum\nSell 5 BTC at 1500 USD by Nahum\nSell 5 BTC at 1500 USD by Nahum\nSell 1 BTC at 158 USD by Nahum\nBuy 7 BTC at 158 USD by Nahum\nSell 7 BTC at 158 USD by Nahum\nSell 20 BTC at 2000 USD by Nahum\nOfria's Open Orders (in chronological order):\nOfria's Filled Orders (in chronological order):\nSell 12 ETH at 158 USD by Ofria\nSell 10 ETH at 140 USD by Ofria\nSell 10 ETH at 1200 USD by Ofria\nZaabar's Open Orders (in chronological order):\nBuy 10 LTC at 450 USD by Zaabar\nBuy 190 ETH at 1200 USD by Zaabar\nZaabar's Filled Orders (in chronological order):\nSell 10 LTC at 600 USD by Zaabar\nBuy 5 BTC at 1500 USD by Zaabar\nBuy 5 BTC at 1500 USD by Zaabar\nBuy 10 ETH at 1200 USD by Zaabar\n") << std::endl;
  std::cout << std::endl << std::endl;
  e.PrintBidAskSpread(std::cout);
  oss.str("");
  e.PrintBidAskSpread(oss);
  std::cout << (oss.str() == "Asset Bid Ask Spread (in alphabetical order):\nBTC: Highest Open Buy = NA USD and Lowest Open Sell = 158 USD\nETH: Highest Open Buy = 1200 USD and Lowest Open Sell = 1423 USD\nLTC: Highest Open Buy = 600 USD and Lowest Open Sell = NA USD\n") << std::endl;
}