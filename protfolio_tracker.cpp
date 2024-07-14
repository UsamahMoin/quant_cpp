#include <iostream>
#include <vector>
#include <string>

struct Stock {
    std::string symbol;
    double buyPrice;
    int shares;
};

class Portfolio {
public:
    void addStock(const std::string& symbol, double buyPrice, int shares) {
        stocks.push_back({ symbol, buyPrice, shares });
    }

    void updateStockPrice(const std::string& symbol, double currentPrice) {
        for (auto& stock : stocks) {
            if (stock.symbol == symbol) {
                stock.currentPrice = currentPrice;
            }
        }
    }

    void displayPortfolio() {
        double totalInvestment = 0.0;
        double currentValue = 0.0;

        std::cout << "Portfolio:\n";
        for (const auto& stock : stocks) {
            double investment = stock.buyPrice * stock.shares;
            double value = stock.currentPrice * stock.shares;

            totalInvestment += investment;
            currentValue += value;

            double gainLoss = (value - investment) / investment * 100;

            std::cout << "Stock: " << stock.symbol << ", Shares: " << stock.shares
                      << ", Buy Price: $" << stock.buyPrice << ", Current Price: $" << stock.currentPrice
                      << ", Gain/Loss: " << gainLoss << "%\n";
        }

        std::cout << "Total Investment: $" << totalInvestment << "\n";
        std::cout << "Current Value: $" << currentValue << "\n";
        std::cout << "Overall Gain/Loss: " << (currentValue - totalInvestment) / totalInvestment * 100 << "%\n";
    }

private:
    struct StockDetails {
        std::string symbol;
        double buyPrice;
        double currentPrice;
        int shares;
    };

    std::vector<StockDetails> stocks;
};

int main() {
    Portfolio portfolio;
    portfolio.addStock("AAPL", 150.0, 10);
    portfolio.addStock("GOOGL", 1200.0, 5);

    portfolio.updateStockPrice("AAPL", 155.0);
    portfolio.updateStockPrice("GOOGL", 1220.0);

    portfolio.displayPortfolio();

    return 0;
}
