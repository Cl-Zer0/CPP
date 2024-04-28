#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    try {
        while (true) {
            // Dynamically allocate memory
            int* ptr = new int[1000000]; // Allocating an array of integers
            // Ensure the memory is accessed so it's not optimized away
            for (int i = 0; i < 1000000; ++i) {
                ptr[i] = i;
            }
        }
    } catch (bad_alloc& e) {
        // Catching the exception thrown when memory allocation fails
        cout << "Memory allocation failed: " << e.what() << endl;
    }

    return 0;
}
