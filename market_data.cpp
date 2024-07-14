#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

// Function to calculate mean
double calculateMean(const std::vector<double>& data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

// Function to calculate variance
double calculateVariance(const std::vector<double>& data, double mean) {
    double variance = 0.0;
    for (double value : data) {
        variance += (value - mean) * (value - mean);
    }
    return variance / data.size();
}

// Function to calculate standard deviation
double calculateStandardDeviation(double variance) {
    return std::sqrt(variance);
}

int main() {
    std::vector<double> prices = { 100, 102, 101, 105, 110, 108, 107, 112, 115, 117, 120 };
    
    double mean = calculateMean(prices);
    double variance = calculateVariance(prices, mean);
    double stdDev = calculateStandardDeviation(variance);

    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Variance: " << variance << std::endl;
    std::cout << "Standard Deviation: " << stdDev << std::endl;

    return 0;
}
