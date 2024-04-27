#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

// Function to print the array with ASCII art bars
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
        for (int j = 0; j < arr[i]; ++j) {
            cout << "|";
        }
        cout << endl;
    }
    cout << endl;
}

// Bubble Sort algorithm
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                printArray(arr);
                this_thread::sleep_for(chrono::milliseconds(100)); // Pause for visualization
                system("clear"); // Clear the console (for Unix-like systems)
                // system("cls"); // For Windows
            }
        }
    }
}

// Merge function for Merge Sort
void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Merge Sort algorithm
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
        printArray(arr);
        this_thread::sleep_for(chrono::milliseconds(100)); // Pause for visualization
        system("clear"); // Clear the console (for Unix-like systems)
        // system("cls"); // For Windows
    }
}

// Partition function for Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort algorithm
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        printArray(arr);
        this_thread::sleep_for(chrono::milliseconds(100)); // Pause for visualization
        system("clear"); // Clear the console (for Unix-like systems)
        // system("cls"); // For Windows
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {5, 3, 8, 1, 2, 7, 4, 6};

    cout << "Original array:" << endl;
    printArray(arr);
    cout << "Sorting using Bubble Sort:" << endl;
    bubbleSort(arr);
    cout << "Sorted array:" << endl;
    printArray(arr);

    arr = {5, 3, 8, 1, 2, 7, 4, 6}; // Reset the array

    cout << "Original array:" << endl;
    printArray(arr);
    cout << "Sorting using Merge Sort:" << endl;
    mergeSort(arr, 0, arr.size() - 1);
    cout << "Sorted array:" << endl;
    printArray(arr);

    arr = {5, 3, 8, 1, 2, 7, 4, 6}; // Reset the array

    cout << "Original array:" << endl;
    printArray(arr);
    cout << "Sorting using Quick Sort:" << endl;
    quickSort(arr, 0, arr.size() - 1);
    cout << "Sorted array:" << endl;
    printArray(arr);

    return 0;
}
