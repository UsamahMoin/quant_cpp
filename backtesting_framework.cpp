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

// Backtesting function for moving average crossover strategy
void backtestMovingAverageCrossover(const std::vector<double>& prices, int shortPeriod, int longPeriod) {
    std::vector<double> shortSMA = calculateSMA(prices, shortPeriod);
    std::vector<double> longSMA = calculateSMA(prices, longPeriod);

    bool inPosition = false;
    double entryPrice = 0.0;
    double profit = 0.0;

    for (size_t i = longPeriod - 1; i < prices.size(); ++i) {
        if (shortSMA[i - longPeriod + 1] > longSMA[i - longPeriod + 1]) {
            if (!inPosition) {
                entryPrice = prices[i];
                inPosition = true;
                std::cout << "Buy at: " << entryPrice << std::endl;
            }
        } else if (shortSMA[i - longPeriod + 1] < longSMA[i - longPeriod + 1]) {
            if (inPosition) {
                double exitPrice = prices[i];
                profit += (exitPrice - entryPrice);
                inPosition = false;
                std::cout << "Sell at: " << exitPrice << std::endl;
            }
        }
    }

    std::cout << "Total Profit: " << profit << std::endl;
}

int main() {
    std::vector<double> prices = { 100.0, 102.0, 101.0, 105.0, 110.0, 108.0, 107.0, 112.0, 115.0, 117.0, 120.0 };
    int shortPeriod = 3;
    int longPeriod = 5;

    backtestMovingAverageCrossover(prices, shortPeriod, longPeriod);

    return 0;
}
