#include <iostream>
using namespace std;

int main() {
    char op;
    float num1, num2;

    do {
        cout << "Enter operator (+, -, *, /) or 'q' to quit: ";
        cin >> op;

        // Check if user wants to quit
        if (op == 'q') {
            cout << "Exiting calculator..." << endl;
            break;
        }

        // Input validation
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            cout << "Invalid operator! Please try again." << endl;
            continue;
        }

        cout << "Enter two operands: ";
        cin >> num1 >> num2;

        // Perform calculation
        switch (op) {
            case '+':
                cout << "Result: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Result: " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Result: " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 != 0)
                    cout << "Result: " << num1 / num2 << endl;
                else
                    cout << "Error! Division by zero." << endl;
                break;
        }

    } while (true);

    return 0;
}
