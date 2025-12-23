#ifndef TRADE_LOGGER_H
#define TRADE_LOGGER_H

#include <vector>
#include <string>
#include <unordered_map>

struct Trade {
    std::string symbol;
    std::string type;
    double price;
    int shares;
    std::string date;
};

class TradeLogger {
public:
    void logTrade(const std::string& symbol, const std::string& type, double price, int shares, const std::string& date);
    void displayTrades();
    void displaySummary();

private:
    struct Position {
        double avgPrice = 0.0;
        int shares = 0;
    };

    std::vector<Trade> trades;
    std::unordered_map<std::string, Position> positions;
};

#endif // TRADE_LOGGER_H
