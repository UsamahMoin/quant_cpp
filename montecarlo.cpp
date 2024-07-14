#include <iostream>
#include <vector>
#include <random>
#include <cmath>

// Function to perform Monte Carlo simulation for stock prices
void monteCarloSimulation(int numSimulations, int numDays, double initialPrice, double drift, double volatility, std::vector<double>& finalPrices) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::normal_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < numSimulations; ++i) {
        double price = initialPrice;
        for (int j = 0; j < numDays; ++j) {
            double randomShock = distribution(generator);
            price *= exp(drift + volatility * randomShock);
        }
        finalPrices.push_back(price);
    }
}

int main() {
    int numSimulations = 10000; // Number of simulations
    int numDays = 252; // Number of trading days in a year
    double initialPrice = 100.0; // Initial stock price
    double drift = 0.0002; // Expected return (drift)
    double volatility = 0.01; // Volatility of the stock

    std::vector<double> finalPrices;
    monteCarloSimulation(numSimulations, numDays, initialPrice, drift, volatility, finalPrices);

    // Calculate and print the probability of different price levels
    double lowerBound = 90.0;
    double upperBound = 110.0;
    int countInRange = 0;

    for (double price : finalPrices) {
        if (price >= lowerBound && price <= upperBound) {
            countInRange++;
        }
    }

    double probabilityInRange = static_cast<double>(countInRange) / numSimulations;
    std::cout << "Probability of the stock price being between $" << lowerBound << " and $" << upperBound << " after " << numDays << " days: " << probabilityInRange * 100 << "%" << std::endl;

    return 0;
}
