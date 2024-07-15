#include <iostream>
#include "RiskManagement.h"
#include "MarketDataAnalyzer.h"
#include "OptionsPricing.h"
#include "TechnicalIndicators.h"
#include "NewsSentimentAnalyzer.h"
#include "TradeLogger.h"

int main() {
    // Example usage of Risk Management Tool
    std::vector<double> portfolioReturns = { 0.01, -0.02, 0.015, -0.005, 0.02, -0.03, 0.01, 0.005, -0.01 };
    double confidenceLevel = 0.95;
    double VaR = calculateVaR(portfolioReturns, confidenceLevel);
    std::cout << "Value at Risk (VaR) at " << confidenceLevel * 100 << "% confidence level: " << VaR << std::endl;

    std::vector<double> portfolioPrices = { 100, 105, 102, 107, 103, 101, 98, 95, 97, 99 };
    double maxDrawdown = calculateMaxDrawdown(portfolioPrices);
    std::cout << "Maximum Drawdown: " << maxDrawdown * 100 << "%" << std::endl;

    // Example usage of Market Data Analyzer
    std::vector<double> prices = { 100, 102, 101, 105, 110, 108, 107, 112, 115, 117, 120 };
    double mean = calculateMean(prices);
    double variance = calculateVariance(prices, mean);
    double stdDev = calculateStandardDeviation(variance);
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Variance: " << variance << std::endl;
    std::cout << "Standard Deviation: " << stdDev << std::endl;

    // Example usage of Options Pricing Calculator
    double S = 100.0;
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;
    double callPrice = blackScholesCall(S, K, T, r, sigma);
    double putPrice = blackScholesPut(S, K, T, r, sigma);
    std::cout << "Call Option Price: " << callPrice << std::endl;
    std::cout << "Put Option Price: " << putPrice << std::endl;

    // Example usage of Technical Indicators Library
    int period = 3;
    std::vector<double> sma = calculateSMA(prices, period);
    std::vector<double> ema = calculateEMA(prices, period);
    std::vector<double> rsi = calculateRSI(prices, period);
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
    std::cout << "Relative Strength Index (RSI): ";
    for (double value : rsi) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Example usage of News Sentiment Analyzer
    std::string apiKey = "YOUR_NEWS_API_KEY";
    std::string query = "stock market";
    fetchNews(apiKey, query);

    // Example usage of Trade Logger
    TradeLogger logger;
    logger.logTrade("AAPL", "buy", 150.0, 10, "2023-07-10");
    logger.logTrade("AAPL", "sell", 155.0, 10, "2023-07-12");
    logger.logTrade("GOOGL", "buy", 1200.0, 5, "2023-07-11");
    logger.logTrade("GOOGL", "sell", 1220.0, 5, "2023-07-13");
    logger.displayTrades();
    logger.displaySummary();

    return 0;
}
