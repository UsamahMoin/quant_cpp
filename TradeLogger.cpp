#include "TradeLogger.h"
#include <iostream>

void TradeLogger::logTrade(const std::string& symbol, const std::string& type, double price, int shares, const std::string& date) {
    trades.push_back({ symbol, type, price, shares, date });
}

void TradeLogger::displayTrades() {
    std::cout << "Logged Trades:\n";
    for (const auto& trade : trades) {
        std::cout << "Symbol: " << trade.symbol << ", Type: " << trade.type
                  << ", Price: " << trade.price << ", Shares: " << trade.shares
                  << ", Date: " << trade.date << std::endl;
    }
}

void TradeLogger::displaySummary() {
    int winTrades = 0;
    int lossTrades = 0;
    double totalProfit = 0.0;

    for (const auto& trade : trades) {
        if (trade.type == "sell") {
            double profit = (trade.price - buyPrice) * trade.shares;
            totalProfit += profit;
            if (profit > 0) {
                winTrades++;
            } else {
                lossTrades++;
            }
        } else {
            buyPrice = trade.price;
        }
    }

    std::cout << "Total Trades: " << trades.size() << "\n";
    std::cout << "Winning Trades: " << winTrades << "\n";
    std::cout << "Losing Trades: " << lossTrades << "\n";
    std::cout << "Total Profit: " << totalProfit << "\n";
    std::cout << "Win Rate: " << (static_cast<double>(winTrades) / trades.size()) * 100 << "%\n";
}
