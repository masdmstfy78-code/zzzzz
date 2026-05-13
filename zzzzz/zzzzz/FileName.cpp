#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} };

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin() {
    // Rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
    // Columns
    for (int j = 0; j < 3; j++)
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) return true;
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

int main() {
    int choice;
    char mark;
    int turn = 0;

    cout << "Welcome to Tic Tac Toe!\n";
    displayBoard();

    while (true) {
        mark = (turn % 2 == 0) ? 'X' : 'O';
        cout << "Player " << mark << ", enter a number (1-9): ";
        cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        board[row][col] = mark;
        displayBoard();

        if (checkWin()) {
            cout << "Player " << mark << " wins!\n";
            break;
        }

        turn++;
        if (turn == 9) {
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}
