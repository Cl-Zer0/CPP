#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate simple interest for each year and total interest
double calculateSimpleInterest(double principal, double rate, int time, bool showProgression) {
    double totalInterest = 0;
    for (int i = 1; i <= time; ++i) {
        double interest = (principal * rate * i) / 100;
        totalInterest += interest;
        if (showProgression)
            cout << "Year " << i << ": " << interest << endl;
    }
    return totalInterest;
}

// Function to calculate compound interest for each year and total interest
double calculateCompoundInterest(double principal, double rate, int time, bool showProgression) {
    double totalInterest = 0;
    for (int i = 1; i <= time; ++i) {
        double interest = principal * (pow((1 + rate / 100), i) - 1);
        if (showProgression)
            cout << "Year " << i << ": " << interest << endl;
        totalInterest += interest;
    }
    return totalInterest;
}

int main() {
    double principal, rate;
    int time;
    char choice;

    cout << "Enter the principal amount: ";
    cin >> principal;

    cout << "Enter the interest rate (in percentage): ";
    cin >> rate;

    cout << "Enter the time period (in years): ";
    cin >> time;

    cout << "Enter 's' for simple interest or 'c' for compound interest: ";
    cin >> choice;

    if (choice == 's' || choice == 'S') {
        cout << "Yearly Progression of Simple Interest: " << endl;
        double simpleInterest = calculateSimpleInterest(principal, rate, time, true);
        cout << "Total Simple Interest: " << simpleInterest << endl;
    } else if (choice == 'c' || choice == 'C') {
        cout << "Yearly Progression of Compound Interest: " << endl;
        double compoundInterest = calculateCompoundInterest(principal, rate, time, true);
        cout << "Total Compound Interest: " << compoundInterest << endl;
    } else {
        cout << "Invalid choice. Please enter 's' for simple interest or 'c' for compound interest." << endl;
    }

    return 0;
}
