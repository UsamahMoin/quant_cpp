#ifndef OPTIONS_PRICING_H
#define OPTIONS_PRICING_H

double normalCDF(double value);
double blackScholesCall(double S, double K, double T, double r, double sigma);
double blackScholesPut(double S, double K, double T, double r, double sigma);

#endif // OPTIONS_PRICING_H
