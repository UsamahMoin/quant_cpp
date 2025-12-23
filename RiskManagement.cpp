#include "RiskManagement.h"
#include <algorithm>
#include <cmath>

double calculateVaR(const std::vector<double>& returns, double confidenceLevel) {
    if (returns.empty()) {
        return 0.0;
    }
    std::vector<double> sortedReturns = returns;
    std::sort(sortedReturns.begin(), sortedReturns.end());

    double alpha = 1.0 - confidenceLevel;
    if (alpha < 0.0) {
        alpha = 0.0;
    } else if (alpha > 1.0) {
        alpha = 1.0;
    }
    size_t index = static_cast<size_t>(alpha * (sortedReturns.size() - 1));
    return sortedReturns[index];
}

double calculateMaxDrawdown(const std::vector<double>& prices) {
    if (prices.empty()) {
        return 0.0;
    }
    double maxDrawdown = 0.0;
    double peak = prices[0];

    for (double price : prices) {
        if (price > peak) {
            peak = price;
        }
        if (peak == 0.0) {
            continue;
        }
        double drawdown = (peak - price) / peak;
        if (drawdown > maxDrawdown) {
            maxDrawdown = drawdown;
        }
    }
    return maxDrawdown;
}
