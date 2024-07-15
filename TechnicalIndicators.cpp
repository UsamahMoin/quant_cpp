#include "TechnicalIndicators.h"
#include <numeric>
#include <cmath>

std::vector<double> calculateSMA(const std::vector<double>& prices, int period) {
    std::vector<double> sma;
    for (size_t i = 0; i <= prices.size() - period; ++i) {
        double sum = std::accumulate(prices.begin() + i, prices.begin() + i + period, 0.0);
        sma.push_back(sum / period);
    }
    return sma;
}

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

std::vector<double> calculateRSI(const std::vector<double>& prices, int period) {
    std::vector<double> rsi;
    std::vector<double> gains;
    std::vector<double> losses;

    for (size_t i = 1; i < prices.size(); ++i) {
        double change = prices[i] - prices[i - 1];
        if (change > 0) {
            gains.push_back(change);
            losses.push_back(0);
        } else {
            gains.push_back(0);
            losses.push_back(-change);
        }
    }

    double avgGain = std::accumulate(gains.begin(), gains.begin() + period, 0.0) / period;
    double avgLoss = std::accumulate(losses.begin(), losses.begin() + period, 0.0) / period;

    for (size_t i = period; i < gains.size(); ++i) {
        avgGain = (avgGain * (period - 1) + gains[i]) / period;
        avgLoss = (avgLoss * (period - 1) + losses[i]) / period;

        double rs = avgGain / avgLoss;
        rsi.push_back(100 - (100 / (1 + rs)));
    }

    return rsi;
}
