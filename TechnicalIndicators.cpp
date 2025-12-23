#include "TechnicalIndicators.h"
#include <numeric>
#include <cmath>

std::vector<double> calculateSMA(const std::vector<double>& prices, int period) {
    std::vector<double> sma;
    if (period <= 0) {
        return sma;
    }
    size_t window = static_cast<size_t>(period);
    if (prices.size() < window) {
        return sma;
    }
    for (size_t i = 0; i + window <= prices.size(); ++i) {
        double sum = std::accumulate(prices.begin() + i, prices.begin() + i + window, 0.0);
        sma.push_back(sum / static_cast<double>(window));
    }
    return sma;
}

std::vector<double> calculateEMA(const std::vector<double>& prices, int period) {
    std::vector<double> ema;
    if (period <= 0) {
        return ema;
    }
    size_t window = static_cast<size_t>(period);
    if (prices.size() < window) {
        return ema;
    }
    double multiplier = 2.0 / (static_cast<double>(period) + 1.0);
    double prevEMA = std::accumulate(prices.begin(), prices.begin() + window, 0.0) / static_cast<double>(window);
    ema.push_back(prevEMA);

    for (size_t i = window; i < prices.size(); ++i) {
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

    if (period <= 0 || prices.size() <= static_cast<size_t>(period)) {
        return rsi;
    }

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

    double rs = avgLoss == 0 ? 0 : avgGain / avgLoss;
    if (avgLoss == 0) {
        rsi.push_back(100.0);
    } else if (avgGain == 0) {
        rsi.push_back(0.0);
    } else {
        rsi.push_back(100 - (100 / (1 + rs)));
    }

    for (size_t i = period; i < gains.size(); ++i) {
        avgGain = (avgGain * (period - 1) + gains[i]) / period;
        avgLoss = (avgLoss * (period - 1) + losses[i]) / period;

        double rs = avgLoss == 0 ? 0 : avgGain / avgLoss;
        if (avgLoss == 0) {
            rsi.push_back(100.0);
        } else if (avgGain == 0) {
            rsi.push_back(0.0);
        } else {
            rsi.push_back(100 - (100 / (1 + rs)));
        }
    }

    return rsi;
}
