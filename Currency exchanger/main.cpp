#include <iostream>
#include <map>
#include <string>
#include <iomanip>

// Function to convert currency
double convertCurrency(double amount, const std::string& fromCurrency, const std::string& toCurrency, const std::map<std::string, double>& exchangeRates) {
    if (exchangeRates.find(fromCurrency) == exchangeRates.end() || exchangeRates.find(toCurrency) == exchangeRates.end()) {
        std::cout << "Invalid currency code!" << std::endl;
        return -1;
    }

    double fromRate = exchangeRates.at(fromCurrency);
    double toRate = exchangeRates.at(toCurrency);

    return amount * (toRate / fromRate);
}

int main() {
    // Exchange rates (example rates)
    std::map<std::string, double> exchangeRates = {
        {"USD", 1.0},   // US Dollar
        {"EUR", 0.85},  // Euro
        {"GBP", 0.73},  // British Pound
        {"JPY", 109.54} // Japanese Yen
        // Add more currencies and exchange rates as needed
    };

    // User input
    double amount;
    std::string fromCurrency, toCurrency;

    std::cout << "Enter amount: ";
    std::cin >> amount;

    std::cout << "Enter currency to convert from (e.g., USD, EUR, GBP, JPY): ";
    std::cin >> fromCurrency;

    std::cout << "Enter currency to convert to (e.g., USD, EUR, GBP, JPY): ";
    std::cin >> toCurrency;

    // Convert currency
    double convertedAmount = convertCurrency(amount, fromCurrency, toCurrency, exchangeRates);

    // Display result
    if (convertedAmount >= 0) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << amount << " " << fromCurrency << " = " << convertedAmount << " " << toCurrency << std::endl;
    }

    return 0;
}
