#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "=== To-Do List Application ===" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Exit" << endl;
    cout << "=============================" << endl;
}

// Function to add a task to the list
void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter task: ";
    getline(cin >> ws, task); // Read the task including spaces
    tasks.push_back(task);
    cout << "Task added successfully!" << endl;
}

// Function to view all tasks in the list
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks added yet!" << endl;
        return;
    }
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<string>& tasks) {
    int index;
    cout << "Enter the task number to mark as completed: ";
    cin >> index;
    if (index <= 0 || index > tasks.size()) {
        cout << "Invalid task number!" << endl;
        return;
    }
    tasks.erase(tasks.begin() + index - 1);
    cout << "Task marked as completed!" << endl;
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                cout << "Exiting application..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
