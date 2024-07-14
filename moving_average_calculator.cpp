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

// Function to calculate Exponential Moving Average (EMA)
std::vector<double> calculateEMA(const std::vector<double>& prices, int period) {
    std::vector<double> ema;
    double multiplier = 2.0 / (period + 1);
    double prevEMA = std::accumulate(prices.begin(), prices.begin() + period, 0.0) / period;
    ema.push_back(prevEMA);

    for (size_t i = period; i < prices.size(); ++i) {
        double currentEMA = (prices[i] - prevEMA) * multiplier + prevEMA;
        ema.push_back(currentEMA);
        prevEMA = currentEMA;
    }
    return ema;
}

int main() {
    std::vector<double> prices = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
    int period = 3;

    std::vector<double> sma = calculateSMA(prices, period);
    std::vector<double> ema = calculateEMA(prices, period);

    std::cout << "Simple Moving Average (SMA): ";
    for (double value : sma) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "Exponential Moving Average (EMA): ";
    for (double value : ema) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
