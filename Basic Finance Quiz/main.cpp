#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to shuffle the answer options
void shuffleOptions(vector<string>& options) {
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(options.begin(), options.end());
}

// Function to display a multiple-choice question and get user's answer
bool askQuestion(const string& question, const vector<string>& options, const string& correctAnswer) {
    vector<string> shuffledOptions = options;
    shuffleOptions(shuffledOptions);

    cout << question << endl;
    for (size_t i = 0; i < shuffledOptions.size(); ++i) {
        cout << i + 1 << ". " << shuffledOptions[i] << endl;
    }

    cout << "Your choice: ";
    int userChoice;
    cin >> userChoice;
    cin.ignore(); // Clear input buffer

    if (shuffledOptions[userChoice - 1] == correctAnswer) {
        cout << "Correct!" << endl;
        return true;
    } else {
        cout << "Incorrect." << endl;
        return false;
    }
}

int main() {
    int score = 0;

    cout << "Welcome to the Financial Concepts Quiz!" << endl;
    cout << "Let's see how much you know about budgeting, investing, and managing debt." << endl;

    // Questions, options, and correct answers
    vector<string> questions = {
        "What is the purpose of budgeting?",
        "What is the recommended percentage of income to save for emergencies?",
        "What is the concept of compound interest?",
        "What is a stock?",
        "What does APR stand for?"
    };
    vector<vector<string>> options = {
        {"To track and control spending", "To invest in the stock market", "To buy luxury items", "To travel around the world"},
        {"5-10%", "10-20%", "20-30%", "30-40%"},
        {"Interest calculated on the initial principal and also on the accumulated interest", "Interest calculated only on the initial principal", "Interest calculated only on the accumulated interest", "Interest calculated annually"},
        {"A type of investment representing ownership in a company", "A type of debt investment", "A type of investment representing ownership in real estate", "A type of investment representing ownership in a government"},
        {"Annual Percentage Rate", "Average Payment Ratio", "Annual Percentage Revenue", "Average Principal Return"}
    };
    vector<string> correctAnswers = {
        "To track and control spending",
        "10-20%",
        "Interest calculated on the initial principal and also on the accumulated interest",
        "A type of investment representing ownership in a company",
        "Annual Percentage Rate"
    };

    // Ask each question and check answers
    for (size_t i = 0; i < questions.size(); ++i) {
        if (askQuestion(questions[i], options[i], correctAnswers[i])) {
            score++;
        }
        cout << endl;
    }

    cout << "Quiz complete!" << endl;
    cout << "You scored " << score << " out of " << questions.size() << "." << endl;

    return 0;
}
