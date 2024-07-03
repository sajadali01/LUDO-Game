#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 15;
const int PLAYER_COUNT = 2;

// Function to display the Ludo board
void displayBoard(int board[][BOARD_SIZE]) {
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

void initializeBoard(int board[][BOARD_SIZE]) {
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = 0;
        }
    }
}

int rollDice() {
    return rand() % 6 + 1;
}

void movePiece(int board[][BOARD_SIZE], int player, int steps) {
   int currentPosition;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[player][i] == 1) {
            currentPosition = i;
            break;
        }
    }

    board[player][currentPosition] = 0;

    int newPosition = currentPosition + steps;
    if (newPosition >= BOARD_SIZE) {
        cout << "Player " << player + 1 << " has completed the game!" << endl;
    } else {
        board[player][newPosition] = 1;
    }
}

// Function for the computer player's turn (AI)
void computerTurn(int board[][BOARD_SIZE], int computerPlayer) {
    int steps = rollDice();
    cout << "Computer (Player " << computerPlayer + 1 << ") rolled a " << steps << endl;
    movePiece(board, computerPlayer, steps);
}

int main() {
    srand(time(0));

    int board[PLAYER_COUNT][BOARD_SIZE];
    initializeBoard(board);

    while (true) {
        displayBoard(board);

        // Human player's turn
        cout << "Player 1 (Human), press Enter to roll the dice: ";
        cin.ignore(); 
        int steps = rollDice();
        cout << "You rolled a " << steps << endl;
        movePiece(board, 0, steps);

        if (board[0][BOARD_SIZE - 1] == 1) {
            cout << "Congratulations! You won!" << endl;
            break;
        }

        computerTurn(board, 1);

        if (board[1][BOARD_SIZE - 1] == 1) {
            cout << "Computer(AI) player won. Better luck next time!" << endl;
            break;
        }
    }

    return 0;
}
