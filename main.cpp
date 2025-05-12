#include <iostream>

using namespace std;

const int SIZE = 3;

char board[SIZE][SIZE];

char currentPlayer = 'X';

// Speles laukums

void initializeBoard() {

for (int i = 0; i < SIZE; ++i)

for (int j = 0; j < SIZE; ++j)

board[i][j] = ' ';

}

// Izvada laukumu uz ekrana

void printBoard() {

cout << "   0   1   2\n";

for (int i = 0; i < SIZE; ++i) {

cout << i << " ";

for (int j = 0; j < SIZE; ++j) {

cout << " " << board[i][j];

if (j < SIZE - 1) cout << " |";

}

cout << endl;

if (i < SIZE - 1)

cout << " ----+---+---\n";

}

}

// Parbauda, vai ievaditas koordinates ir derigas

bool isValidMove(int row, int col) {

return row >= 0 && row < SIZE &&

col >= 0 && col < SIZE &&

board[row][col] == ' ';

}

// Veic gajienu

void makeMove(int row, int col) {

board[row][col] = currentPlayer;

}

// Parbauda, vai kads uzvarejis

bool checkWin() {

// Rindas un kolonnas

for (int i = 0; i < SIZE; ++i) {

if (board[i][0] == currentPlayer &&

board[i][1] == currentPlayer &&

board[i][2] == currentPlayer)

return true;

if (board[0][i] == currentPlayer &&

board[1][i] == currentPlayer &&

board[2][i] == currentPlayer)

return true;

}

// Diagonales

if (board[0][0] == currentPlayer &&

board[1][1] == currentPlayer &&

board[2][2] == currentPlayer)

return true;

if (board[0][2] == currentPlayer &&

board[1][1] == currentPlayer &&

board[2][0] == currentPlayer)

return true;

return false;

}

// Parbauda, vai laukums ir pilns (neizskirts)

bool isDraw() {

for (int i = 0; i < SIZE; ++i)

for (int j = 0; j < SIZE; ++j)

if (board[i][j] == ' ')

return false;

return true;

}

// speletaju maina

void switchPlayer() {

currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

}

// Speles uzsaksana

void playGame() {

initializeBoard();

bool gameEnded = false;

while (!gameEnded) {

printBoard();

int row, col;

cout << "Speletajs " << currentPlayer << ", ievadi rindu un kolonnu (piemeram 1 2): ";

cin >> row >> col;

if (!isValidMove(row, col)) {

cout << "Nederigs gajiens. Megini velreiz.\n";

continue;

}

makeMove(row, col);

if (checkWin()) {

printBoard();

cout << "Speletajs " << currentPlayer << " uzvareja!\n";

gameEnded = true;

} else if (isDraw()) {

printBoard();

cout << "Neizskirts!\n";

gameEnded = true;

} else {

switchPlayer();

}

}

}

int main() {

char choice;

do {

playGame();

cout << "Vai velies spelet velreiz? (y/n): ";

cin >> choice;

} while (choice == 'y' || choice == 'Y');

cout << "Paldies par speli!\n";

return 0;

}
