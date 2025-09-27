#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} };

int choice;
char player = 'X';

void printBoard() {
    cout << "\n";
    for(int i=0; i<3; i++) {
        cout << " ";
        for(int j=0; j<3; j++) {
            cout << board[i][j];
            if(j < 2) cout << " | ";
        }
        cout << "\n";
        if(i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin() {
    // Check rows
    for(int i=0; i<3; i++)
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    // Check columns
    for(int j=0; j<3; j++)
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;

    return false;
}

bool checkDraw() {
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void playerMove() {
    cout << "Player " << player << ", choose a position (1-9): ";
    cin >> choice;

    int row = (choice-1) / 3;
    int col = (choice-1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
    } else {
        cout << "That spot is already taken! Try again.\n";
        playerMove();
    }
}

void switchPlayer() {
    player = (player == 'X') ? 'O' : 'X';
}

int main() {
    cout << "=== Tic Tac Toe ===\n";
    printBoard();

    while(true) {
        playerMove();
        printBoard();

        if(checkWin()) {
            cout << "Player " << player << " wins!\n";
            break;
        }

        if(checkDraw()) {
            cout << "It's a draw!\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}