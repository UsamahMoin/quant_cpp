#include <iostream>
#include <vector>
#include <numeric>

// Function to calculate Simple Moving Average (SMA)
std::vector<double> calculateSMA(const std::vector<double>& prices, int period) {
    std::vector<double> sma;
    for (size_t i = 0; i <= prices.size() - period; ++i) {
        double sum = std::accumulate(prices.begin() + i, prices.begin() + i + period, 0.0);
        sma.push_back(sum / period);
    }
    return sma;
}

// Trading bot function
void tradingBot(const std::vector<double>& prices, int period) {
    std::vector<double> sma = calculateSMA(prices, period);
    bool inPosition = false;
    double entryPrice = 0.0;

    for (size_t i = period - 1; i < prices.size(); ++i) {
        if (prices[i] > sma[i - period + 1]) {
            if (!inPosition) {
                entryPrice = prices[i];
                inPosition = true;
                std::cout << "Buy at: " << entryPrice << std::endl;
            }
        } else if (prices[i] < sma[i - period + 1]) {
            if (inPosition) {
                double exitPrice = prices[i];
                inPosition = false;
                std::cout << "Sell at: " << exitPrice << std::endl;
            }
        }
    }
}

int main() {
    std::vector<double> prices = { 100.0, 102.0, 101.0, 105.0, 110.0, 108.0, 107.0, 112.0, 115.0, 117.0, 120.0 };
    int period = 3;

    tradingBot(prices, period);

    return 0;
}
