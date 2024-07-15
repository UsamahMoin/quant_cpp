#include "RiskManagement.h"
#include <algorithm>
#include <cmath>

double calculateVaR(const std::vector<double>& returns, double confidenceLevel) {
    std::vector<double> sortedReturns = returns;
    std::sort(sortedReturns.begin(), sortedReturns.end());

    int index = static_cast<int>((1 - confidenceLevel) * sortedReturns.size());
    return sortedReturns[index];
}

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
