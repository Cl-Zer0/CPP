#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void calculateInvestmentEvolution(double futureValue, double interestRate, int years) {
    interestRate /= 100.0;
    int months = years * 12;
    double monthlyInvestment = futureValue * (interestRate / 12.0) /
                               (pow(1 + (interestRate / 12.0), months) - 1);
    cout << "Monthly Investment: $" << monthlyInvestment << endl;
    double totalInvestment = 0;
    cout << "Year\tTotal Investment" << endl;
    cout << "----\t----------------" << endl;
    for (int year = 1; year <= years; ++year) {
        double yearlyProgress = 0;
        for (int month = 1; month <= 12; ++month) {
            double monthlyInterest = totalInvestment * (interestRate / 12.0);
            totalInvestment += monthlyInvestment;
            totalInvestment += monthlyInterest;
            yearlyProgress += monthlyInvestment;
        }
        cout << year << "\t$" << totalInvestment << endl;
    }
}

int main() {
    double futureValue, interestRate;
    int years;

    cout << "Future Value: ";
    cin >> futureValue;

    cout << "Interest Rate (%): ";
    cin >> interestRate;

    cout << "Years: ";
    cin >> years;

    calculateInvestmentEvolution(futureValue, interestRate, years);

    return 0;
}
