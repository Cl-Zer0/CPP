#include <iostream>
#include <iomanip>
#include <cmath> // Include cmath header for pow function

using namespace std;

void calculateAmortization(double loanAmount, double interestRate, int loanTermMonths) {
    double monthlyInterestRate = interestRate / 100.0 / 12.0;
    double monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -loanTermMonths));

    cout << "Monthly Payment: $" << fixed << setprecision(2) << monthlyPayment << endl;

    double remainingBalance = loanAmount;
    cout << "Month\t\tPayment\t\tInterest\tPrincipal\tRemaining Balance" << endl;
    for (int month = 1; month <= loanTermMonths; ++month) {
        double interest = remainingBalance * monthlyInterestRate;
        double principal = monthlyPayment - interest;
        remainingBalance -= principal;

        cout << month << "\t\t$" << fixed << setprecision(2) << monthlyPayment << "\t\t$"
             << interest << "\t\t$" << principal << "\t\t$" << remainingBalance << endl;
    }
}

int main() {
    double loanAmount, interestRate;
    int loanTermYears;

    cout << "Enter the loan amount: $";
    cin >> loanAmount;

    cout << "Enter the annual interest rate (in percentage): ";
    cin >> interestRate;

    cout << "Enter the loan term in years: ";
    cin >> loanTermYears;

    int loanTermMonths = loanTermYears * 12;

    calculateAmortization(loanAmount, interestRate, loanTermMonths);

    return 0;
}
