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
    double totalReturn = 0.0;
    int sellCount = 0;

    for (const auto& trade : trades) {
        Position& position = positions[trade.symbol];
        if (trade.type == "sell") {
            int soldShares = trade.shares;
            if (position.shares > 0) {
                if (soldShares > position.shares) {
                    soldShares = position.shares;
                }
                double profit = (trade.price - position.avgPrice) * soldShares;
                totalProfit += profit;
                if (position.avgPrice > 0.0) {
                    double ret = (trade.price - position.avgPrice) / position.avgPrice * 100.0;
                    totalReturn += ret;
                    sellCount++;
                }
                if (profit > 0) {
                    winTrades++;
                } else {
                    lossTrades++;
                }
                position.shares -= soldShares;
                if (position.shares == 0) {
                    position.avgPrice = 0.0;
                }
            }
        } else {
            int newShares = position.shares + trade.shares;
            if (newShares > 0) {
                position.avgPrice = (position.avgPrice * position.shares + trade.price * trade.shares) / newShares;
                position.shares = newShares;
            }
        }
    }

    std::cout << "Total Trades: " << trades.size() << "\n";
    std::cout << "Winning Trades: " << winTrades << "\n";
    std::cout << "Losing Trades: " << lossTrades << "\n";
    std::cout << "Total Profit: " << totalProfit << "\n";
    double avgReturn = sellCount ? totalReturn / sellCount : 0.0;
    std::cout << "Average Return: " << avgReturn << "%\n";
    double winRate = sellCount ? (static_cast<double>(winTrades) / sellCount) * 100.0 : 0.0;
    std::cout << "Win Rate: " << winRate << "%\n";
}
