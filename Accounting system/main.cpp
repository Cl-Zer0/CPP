#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to represent an individual transaction
struct Transaction {
    string date;
    string description;
    double amount;
};

// Structure to represent a financial account
struct Account {
    string name;
    double balance;
    double income;
    double expenses;
    vector<Transaction> transactions;
};

// Function to add a transaction to an account
void addTransaction(Account& account, string date, string description, double amount) {
    account.transactions.push_back({date, description, amount});
    account.balance += amount;
    if (amount > 0) {
        account.income += amount;
    } else {
        account.expenses += -amount;
    }
}

// Function to generate a detailed financial report
void generateFinancialReport(const Account& account) {
    cout << "Financial Report for Account: " << account.name << endl;
    cout << "Balance: $" << fixed << setprecision(2) << account.balance << endl;
    cout << "Total Income: $" << account.income << endl;
    cout << "Total Expenses: $" << account.expenses << endl;
    cout << "Net Savings: $" << account.income - account.expenses << endl;
    cout << "Transaction History:" << endl;
    cout << "Date\t\tDescription\tAmount" << endl;
    for (const Transaction& transaction : account.transactions) {
        cout << transaction.date << "\t" << transaction.description << "\t\t$" << transaction.amount << endl;
    }
}

// Function to set a budget for a specific category
void setBudget(Account& account, string category, double budget) {
    // Here you could extend the Account structure to include a budget map or create a separate structure for budgeting
    cout << "Budget set for category '" << category << "': $" << budget << endl;
}

// Function to set a financial goal
void setFinancialGoal(Account& account, string goalDescription, double targetAmount) {
    // Here you could extend the Account structure to include financial goals
    cout << "Financial goal set: " << goalDescription << " - Target amount: $" << targetAmount << endl;
}

int main() {
    // Create an example account
    Account myAccount {"My Personal Account", 0.0, 0.0, 0.0};

    // Gather user input for transactions
    char addAnother;
    do {
        string date, description;
        double amount;
        cout << "Enter transaction details:" << endl;
        cout << "Date (YYYY-MM-DD): ";
        cin >> date;
        cout << "Description: ";
        cin.ignore();
        getline(cin, description);
        cout << "Amount: $";
        cin >> amount;
        addTransaction(myAccount, date, description, amount);

        cout << "Do you want to add another transaction? (y/n): ";
        cin >> addAnother;
    } while (addAnother == 'y' || addAnother == 'Y');

    // Gather user input for budget
    string budgetCategory;
    double budgetAmount;
    cout << "Enter a budget category: ";
    cin >> budgetCategory;
    cout << "Enter budget amount: $";
    cin >> budgetAmount;
    setBudget(myAccount, budgetCategory, budgetAmount);

    // Gather user input for financial goal
    string goalDescription;
    double targetAmount;
    cout << "Enter a financial goal description: ";
    cin.ignore();
    getline(cin, goalDescription);
    cout << "Enter target amount for the goal: $";
    cin >> targetAmount;
    setFinancialGoal(myAccount, goalDescription, targetAmount);

    // Generate a financial report
    generateFinancialReport(myAccount);

    return 0;
}
