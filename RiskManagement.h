#ifndef RISK_MANAGEMENT_H
#define RISK_MANAGEMENT_H

#include <vector>

double calculateVaR(const std::vector<double>& returns, double confidenceLevel);
double calculateMaxDrawdown(const std::vector<double>& prices);

#endif // RISK_MANAGEMENT_H
