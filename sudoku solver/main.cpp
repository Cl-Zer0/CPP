#include <iostream>
#include <vector>

using namespace std;

const int N = 9;

// Function to check if a number can be placed in the given position
bool isSafe(vector<vector<int>>& board, int row, int col, int num) {
    // Check if the number is not already present in the row, column, or 3x3 grid
    for (int i = 0; i < N; ++i) {
        if (board[row][i] == num || board[i][col] == num || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) {
            return false;
        }
    }
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(vector<vector<int>>& board) {
    int row = -1, col = -1;
    bool isEmpty = true;

    // Find an empty cell
    for (int i = 0; i < N && isEmpty; ++i) {
        for (int j = 0; j < N && isEmpty; ++j) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
            }
        }
    }

    // If no empty cell is found, the puzzle is solved
    if (isEmpty) {
        return true;
    }

    // Try placing numbers from 1 to 9 in the empty cell
    for (int num = 1; num <= 9; ++num) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            // Recursively solve the remaining puzzle
            if (solveSudoku(board)) {
                return true;
            }

            // If the number does not lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    // If no number can be placed in the current cell, backtrack
    return false;
}

// Function to print the Sudoku board
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0 && j < N - 1) {
                cout << "| ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0 && i < N - 1) {
            cout << "---------------------" << endl;
        }
    }
}

int main() {
    // Example Sudoku puzzle
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Original Sudoku board:" << endl;
    printBoard(board);
    cout << endl;

    if (solveSudoku(board)) {
        cout << "Sudoku solved:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists for the Sudoku puzzle." << endl;
    }

    return 0;
}
