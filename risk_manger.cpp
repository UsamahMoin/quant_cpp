#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

// Function to calculate Value at Risk (VaR) using historical simulation
double calculateVaR(const std::vector<double>& returns, double confidenceLevel) {
    std::vector<double> sortedReturns = returns;
    std::sort(sortedReturns.begin(), sortedReturns.end());

    int index = static_cast<int>((1 - confidenceLevel) * sortedReturns.size());
    return sortedReturns[index];
}

// Function to calculate Maximum Drawdown
double calculateMaxDrawdown(const std::vector<double>& prices) {
    double maxDrawdown = 0.0;
    double peak = prices[0];

    for (double price : prices) {
        if (price > peak) {
            peak = price;
        }
        double drawdown = (peak - price) / peak;
        if (drawdown > maxDrawdown) {
            maxDrawdown = drawdown;
        }
    }
    return maxDrawdown;
}

int main() {
    std::vector<double> portfolioReturns = { 0.01, -0.02, 0.015, -0.005, 0.02, -0.03, 0.01, 0.005, -0.01 };
    double confidenceLevel = 0.95;
    double VaR = calculateVaR(portfolioReturns, confidenceLevel);
    std::cout << "Value at Risk (VaR) at " << confidenceLevel * 100 << "% confidence level: " << VaR << std::endl;

    std::vector<double> portfolioPrices = { 100, 105, 102, 107, 103, 101, 98, 95, 97, 99 };
    double maxDrawdown = calculateMaxDrawdown(portfolioPrices);
    std::cout << "Maximum Drawdown: " << maxDrawdown * 100 << "%" << std::endl;

    return 0;
}
