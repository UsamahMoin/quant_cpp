#ifndef TRADE_LOGGER_H
#define TRADE_LOGGER_H

#include <vector>
#include <string>

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
    std::vector<Trade> trades;
    double buyPrice = 0.0;
};

#endif // TRADE_LOGGER_H
