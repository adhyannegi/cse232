#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "useraccount.hpp"
#include "utility.hpp"

class Exchange {
    private:
    std::map<std::string, std::map<std::string, int > > portfolio;
    std::vector<Order> open_orders;
    std::vector<Order> filled_orders;
    std::vector<std::string> trade_history;
    public:
    Exchange();
    void MakeDeposit(const std::string &username, const std::string &asset,
                    int amount);
    void PrintUserPortfolios(std::ostream &os) const;
    bool MakeWithdrawal(const std::string &username, const std::string &assent,
                        int amount);
    bool AddOrder(const Order &order);
    void PrintUsersOrders(std::ostream &os) const;
    void PrintTradeHistory(std::ostream &os) const;
    void PrintBidAskSpread(std::ostream &os) const;
    void AddToOpenOrder(const Order & order);
    void AddToFilledOrders(const Order & order);
    bool sell_order_setup(const Order &order);
    bool sell_equal_equal(Order & open_order, const Order & order);
    bool sell_less_equal(Order & open_order, const Order & order);
    bool sell_greater_equal(Order & open_order, const Order & order);
    bool sell_greater_greater(Order & open_order, const Order & order);
    bool sell_less_greater(Order & open_order, const Order & order);
    bool buy_order_setup(const Order &order);
    bool buy_equal_equal(Order & open_order, const Order & order);
    bool buy_less_equal(Order & open_order, const Order & order);
    bool buy_greater_equal(Order & open_order, const Order & order);
    bool buy_greater_less(Order & open_order, const Order & order);
    bool buy_less_less(Order & open_order, const Order & order);
};