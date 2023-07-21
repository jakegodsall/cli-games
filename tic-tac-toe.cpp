#include <iostream>
#include <string>
#include <array>

const int ROWS = 3;
const int COLS = 3;

void runGame();
void initialiseGameBoard(std::array<std::array<char, COLS>, ROWS>& gameBoard);
void printCurrentGameBoard(std::array<std::array<char, COLS>, ROWS>& gameBoard);
bool validateUserInput(int col, int row);
void getUserInput(bool xTurn, std::array<std::array<char, COLS>, ROWS> gameBoard);
bool cellAlreadyOccupied(int row, int col, std::array<std::array<char, COLS>, ROWS> gameBoard);
std::string getWinner(std::array<std::array<char, COLS>, ROWS> gameBoard);
bool isBoardFull(std::array<std::array<char, COLS>, ROWS> gameBoard);


int main() {

    runGame();

    return 0;
}

void runGame() {
    std::string winner = "";

    // define 3x3 game board
    std::array<std::array<char, COLS>, ROWS> gameBoard;
    // initialise the game board
    initialiseGameBoard(gameBoard);
    printCurrentGameBoard(gameBoard);
    getUserInput(true, gameBoard);

}


// Initialises the game board with spaces
void initialiseGameBoard(std::array<std::array<char, COLS>, ROWS>& gameBoard) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i][j] = ' ';
        }
    }
}

// Print the current board state to the console
void printCurrentGameBoard(std::array<std::array<char, COLS>, ROWS>& gameBoard) {
    std::cout << "Current: " << std::endl << std::endl;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << gameBoard[i][j];
            if (j != COLS - 1) {
                std::cout << " | ";
            } else {
                std::cout << std::endl;
            }
        }
        if (i != ROWS - 1) {
            std::cout << "- - - - -" << std::endl;
        } else {
            std::cout << std::endl;
        }
    }
}

bool validateUserInput(int col, int row) {
    if ((col >= 0 && col < COLS) && (row >= 0 && row < ROWS)) {
        return true;
    } else {
        return false;
    }
}

void getUserInput(bool xTurn, std::array<std::array<char, COLS>, ROWS> gameBoard) {
    char currentPlayer = xTurn ? 'X' : 'O';

    std::cout << "It is " << currentPlayer << "'s turn" << std::endl;
    std::cout << "Please enter the row THEN the column, each from 0, 1, or 2, separated by a space" << std::endl;

    int colValue;
    int rowValue;
    std::cin >> colValue >> rowValue;

    // validate inputs
    while (true) {
        if (std::cin.fail()) {
            std::cout << "You did not enter an integer. " << std::endl;

            std::cin.clear(); // clear the error state of the cin object
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Try again: " << std::endl;
            std::cin >> colValue >> rowValue;
        } else {
            std::cout << "Entered values:" << std::endl;
            std::cout << "Column: " << colValue << std::endl;
            std::cout << "Row: " << rowValue << std::endl << std::endl;

            break;
        }
    }

}