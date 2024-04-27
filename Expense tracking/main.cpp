#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to represent an expense item
struct Expense {
    string category;
    double amount;
};

// Function to add an expense item
void addExpense(map<string, vector<string>>& expenses) {
    string category;
    double amount;

    cout << "Enter expense category: ";
    cin >> category;
    cout << "Enter expense amount: ";
    cin >> amount;

    // Add expense to the map
    expenses[category].push_back(to_string(amount));
}

// Function to generate a report of expenses
void generateReport(const map<string, vector<string>>& expenses) {
    cout << "Expense Report" << endl;
    cout << "--------------" << endl;
    cout << setw(15) << "Category" << setw(15) << "Amount" << endl;
    cout << "--------------" << endl;
    for (const auto& pair : expenses) {
        string category = pair.first;
        double totalAmount = 0.0;
        for (const string& amount : pair.second) {
            totalAmount += stod(amount);
        }
        cout << setw(15) << category << setw(15) << totalAmount << endl;
    }
}

int main() {
    map<string, vector<string>> expenses;
    int choice;

    do {
        cout << "1. Add Expense" << endl;
        cout << "2. Generate Report" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addExpense(expenses);
                break;
            case 2:
                generateReport(expenses);
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
