#include <iostream>
#include <map>
#include <string>
using namespace std;

class Account {
private:
    string name;
    double balance;

public:
    Account() : name(""), balance(0.0) {}

    Account(const string& name, double balance) : name(name), balance(balance) {}

    const string& getName() const {
        return name;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }
};

class Bank {
private:
    map<string, Account> accounts;

public:
    void createAccount(const string& name, double initialBalance) {
        if (accounts.find(name) == accounts.end()) {
            Account newAccount(name, initialBalance);
            accounts.insert({name, newAccount});
            cout << "Account created successfully for " << name << endl;
        } else {
            cout << "Account already exists for " << name << endl;
        }
    }

    void deposit(const string& name, double amount) {
        if (accounts.find(name) != accounts.end()) {
            accounts[name].deposit(amount);
        } else {
            cout << "Account does not exist for " << name << endl;
        }
    }

    void withdraw(const string& name, double amount) {
        if (accounts.find(name) != accounts.end()) {
            accounts[name].withdraw(amount);
        } else {
            cout << "Account does not exist for " << name << endl;
        }
    }

    void checkBalance(const string& name) {
        if (accounts.find(name) != accounts.end()) {
            cout << "Balance for " << name << ": " << accounts[name].getBalance() << endl;
        } else {
            cout << "Account does not exist for " << name << endl;
        }
    }
};

int main() {
    Bank bank;
    int choice;
    string name;
    double amount;

    do {
        cout << "=== Simple Banking System ===" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit" << endl;
        cout << "=============================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account holder's name: ";
                cin >> name;
                cout << "Enter initial balance: ";
                cin >> amount;
                bank.createAccount(name, amount);
                break;
            case 2:
                cout << "Enter account holder's name: ";
                cin >> name;
                cout << "Enter deposit amount: ";
                cin >> amount;
                bank.deposit(name, amount);
                break;
            case 3:
                cout << "Enter account holder's name: ";
                cin >> name;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                bank.withdraw(name, amount);
                break;
            case 4:
                cout << "Enter account holder's name: ";
                cin >> name;
                bank.checkBalance(name);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
