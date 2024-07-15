#include "MarketDataAnalyzer.h"
#include <numeric>
#include <cmath>

double calculateMean(const std::vector<double>& data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

double calculateVariance(const std::vector<double>& data, double mean) {
    double variance = 0.0;
    for (double value : data) {
        variance += (value - mean) * (value - mean);
    }
    return variance / data.size();
}

double calculateStandardDeviation(double variance) {
    return std::sqrt(variance);
}
