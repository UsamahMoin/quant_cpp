#ifndef MARKET_DATA_ANALYZER_H
#define MARKET_DATA_ANALYZER_H

#include <vector>

double calculateMean(const std::vector<double>& data);
double calculateVariance(const std::vector<double>& data, double mean);
double calculateStandardDeviation(double variance);

#endif // MARKET_DATA_ANALYZER_H
