#include <iostream>
#include <vector>
using namespace std;

// Function to draw the Tic Tac Toe board
void drawBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

// Function to check if there is a winner
char checkWinner(const vector<vector<char>>& board) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    // No winner
    return ' ';
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    char winner = ' ';

    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "Player 1 (X) - Player 2 (O)" << endl;
    cout << "The board is numbered from 1 to 9 as follows:" << endl;
    cout << "1 | 2 | 3" << endl;
    cout << "---------" << endl;
    cout << "4 | 5 | 6" << endl;
    cout << "---------" << endl;
    cout << "7 | 8 | 9" << endl;

    while (winner == ' ' && !isBoardFull(board)) {
        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (move < 1 || move > 9 || board[row][col] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        board[row][col] = currentPlayer;
        drawBoard(board);
        winner = checkWinner(board);

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    if (winner != ' ')
        cout << "Player " << winner << " wins!" << endl;
    else
        cout << "It's a draw!" << endl;

    return 0;
}
