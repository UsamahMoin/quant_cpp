#include <iostream>
#include <cmath>

double normalCDF(double value) {
    return 0.5 * erfc(-value * M_SQRT1_2);
}

double blackScholesCall(double S, double K, double T, double r, double sigma) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    return S * normalCDF(d1) - K * std::exp(-r * T) * normalCDF(d2);
}

double blackScholesPut(double S, double K, double T, double r, double sigma) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    return K * std::exp(-r * T) * normalCDF(-d2) - S * normalCDF(-d1);
}

int main() {
    double S = 100.0; // Underlying asset price
    double K = 100.0; // Strike price
    double T = 1.0; // Time to expiration (in years)
    double r = 0.05; // Risk-free rate
    double sigma = 0.2; // Volatility

    double callPrice = blackScholesCall(S, K, T, r, sigma);
    double putPrice = blackScholesPut(S, K, T, r, sigma);

    std::cout << "Call Option Price: " << callPrice << std::endl;
    std::cout << "Put Option Price: " << putPrice << std::endl;

    return 0;
}
