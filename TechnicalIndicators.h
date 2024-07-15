#ifndef TECHNICAL_INDICATORS_H
#define TECHNICAL_INDICATORS_H

#include <vector>

std::vector<double> calculateSMA(const std::vector<double>& prices, int period);
std::vector<double> calculateEMA(const std::vector<double>& prices, int period);
std::vector<double> calculateRSI(const std::vector<double>& prices, int period);

#endif // TECHNICAL_INDICATORS_H
