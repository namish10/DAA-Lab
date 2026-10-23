#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> board;

bool isSafe(int row, int col) {
    // Check upper diagonal on the left
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check same column
    for (int i = row - 1; i >= 0; i--) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper diagonal on the right
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solve(int row) {
    // All queens are placed
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            if (solve(row + 1))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    cin >> n;
    board.assign(n, vector<int>(n, 0));

    if (solve(0)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists";
    }

    return 0;
}