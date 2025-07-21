# Quantitative Trading Tools

This project contains a collection of quantitative trading tools implemented in C++. These tools are designed to assist with various aspects of quantitative finance, including risk management, market data analysis, options pricing, technical indicators, news sentiment analysis, and trade logging.

## Features

1. **Risk Management Tool**
   - Calculate Value at Risk (VaR) and Maximum Drawdown for a trading portfolio.

2. **Market Data Analyzer**
   - Analyze historical market data to identify patterns and trends.
   - Compute basic statistical measures such as mean, variance, and standard deviation.

3. **Options Pricing Calculator**
   - Calculate the price of options using the Black-Scholes model.
   - Include inputs for the underlying asset price, strike price, volatility, time to expiration, and risk-free rate.

4. **Technical Indicators Library**
   - Implement common technical indicators used in trading such as SMA, EMA, and RSI.

5. **News Sentiment Analyzer**
   - Fetch financial news articles and analyze their sentiment using a simple sentiment analysis approach.

6. **Trade Logger**
   - Log executed trades and provide a summary of trading performance, including metrics like win rate, average return, and profit/loss.

## Building and Running Tests

This project uses CMake and GoogleTest for the test suite located in `tests/`.
To build and run the tests:

```bash
mkdir build && cd build
cmake ..
make
ctest
```
