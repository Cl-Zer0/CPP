#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a financial goal
struct FinancialGoal {
    string name;
    double targetAmount;
};

// Function to gather user input for financial goals
vector<string> gatherFinancialGoals() {
    vector<string> goals;
    string goal;
    char addMore;

    do {
        cout << "Enter a financial goal: ";
        getline(cin, goal);
        goals.push_back(goal);

        cout << "Do you want to add another financial goal? (y/n): ";
        cin >> addMore;
        cin.ignore(); // Clear input buffer
    } while (addMore == 'y' || addMore == 'Y');

    return goals;
}

// Function to analyze the user's current financial situation
void analyzeFinancialSituation(double income, double expenses, double savings) {
    cout << "Your income: $" << income << endl;
    cout << "Your expenses: $" << expenses << endl;
    cout << "Your savings: $" << savings << endl;

    double netIncome = income - expenses;
    cout << "Your net income: $" << netIncome << endl;

    double savingsRate = (savings / income) * 100.0;
    cout << "Your savings rate: " << savingsRate << "%" << endl;
}

// Function to suggest adjustments to the user's budget based on financial goals
void suggestBudgetAdjustments(const vector<string>& goals) {
    cout << "Based on your financial goals, here are some adjustments to consider:" << endl;
    for (const string& goal : goals) {
        cout << "- Allocate more funds towards: " << goal << endl;
    }
}

int main() {
    double income, expenses, savings;

    // Gather user input for income, expenses, and savings
    cout << "Enter your monthly income: $";
    cin >> income;

    cout << "Enter your monthly expenses: $";
    cin >> expenses;

    cout << "Enter your monthly savings: $";
    cin >> savings;

    cin.ignore(); // Clear input buffer

    // Gather user input for financial goals
    vector<string> goals = gatherFinancialGoals();

    // Analyze the user's current financial situation
    analyzeFinancialSituation(income, expenses, savings);

    // Suggest budget adjustments based on financial goals
    suggestBudgetAdjustments(goals);

    return 0;
}
