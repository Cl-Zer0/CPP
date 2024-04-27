#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

// Define Transaction structure
struct Transaction {
    double amount;
    string category;
    string description;
    bool isExpense;
};

// Function to input a transaction
Transaction inputTransaction(bool isExpense) {
    Transaction transaction;
    if (isExpense)
        cout << "Enter expense amount: ";
    else
        cout << "Enter income amount: ";
    cin >> transaction.amount;
    if (isExpense) {
        cout << "Enter expense category: ";
        cin >> transaction.category;
    }
    else
        transaction.category = "Income";
    cout << "Enter transaction description: ";
    cin.ignore(); // Clear input buffer
    getline(cin, transaction.description);
    transaction.isExpense = isExpense;
    return transaction;
}

// Function to generate a report
void generateReport(const vector<Transaction>& transactions) {
    double totalIncome = 0.0;
    double totalExpenses = 0.0;
    map<string, double> expensesByCategory;

    cout << "------------------------- REPORT -------------------------" << endl;
    cout << setw(20) << left << "Category" << setw(10) << right << "Amount" << endl;
    cout << "----------------------------------------------------------" << endl;

    for (const Transaction& transaction : transactions) {
        if (transaction.isExpense) {
            totalExpenses += transaction.amount;
            expensesByCategory[transaction.category] += transaction.amount;
        } else {
            totalIncome += transaction.amount;
        }
    }

    for (const auto& pair : expensesByCategory) {
        cout << setw(20) << left << pair.first << setw(10) << right << fixed << setprecision(2) << pair.second << endl;
    }

    cout << "----------------------------------------------------------" << endl;
    cout << "Total Income: $" << fixed << setprecision(2) << totalIncome << endl;
    cout << "Total Expenses: $" << fixed << setprecision(2) << totalExpenses << endl;
    cout << "----------------------------------------------------------" << endl;

    cout << "Net Income: $" << fixed << setprecision(2) << totalIncome - totalExpenses << endl;
    cout << "----------------------------------------------------------" << endl;
}

int main() {
    vector<Transaction> transactions;

    char choice;
    do {
        // Menu for user interaction
        cout << "1. Add Expense" << endl;
        cout << "2. Add Income" << endl;
        cout << "3. Generate Report" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                Transaction newTransaction = inputTransaction(true);
                transactions.push_back(newTransaction);
                break;
            }
            case '2': {
                Transaction newTransaction = inputTransaction(false);
                transactions.push_back(newTransaction);
                break;
            }
            case '3': {
                generateReport(transactions);
                break;
            }
            case '4':
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '4');

    return 0;
}
