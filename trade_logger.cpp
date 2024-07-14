#include <iostream>
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
    void logTrade(const std::string& symbol, const std::string& type, double price, int shares, const std::string& date) {
        trades.push_back({ symbol, type, price, shares, date });
    }

    void displayTrades() {
        std::cout << "Logged Trades:\n";
        for (const auto& trade : trades) {
            std::cout << "Symbol: " << trade.symbol << ", Type: " << trade.type
                      << ", Price: " << trade.price << ", Shares: " << trade.shares
                      << ", Date: " << trade.date << std::endl;
        }
    }

    void displaySummary() {
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

private:
    std::vector<Trade> trades;
    double buyPrice = 0.0;
};

int main() {
    TradeLogger logger;
    logger.logTrade("AAPL", "buy", 150.0, 10, "2023-07-10");
    logger.logTrade("AAPL", "sell", 155.0, 10, "2023-07-12");
    logger.logTrade("GOOGL", "buy", 1200.0, 5, "2023-07-11");
    logger.logTrade("GOOGL", "sell", 1220.0, 5, "2023-07-13");

    logger.displayTrades();
    logger.displaySummary();

    return 0;
}
