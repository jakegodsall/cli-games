#include <iostream>
#include <string>
#include <limits>
#include <array>

const int ROWS = 3;
const int COLS = 3;

void runGame();
void initialiseGameBoard(std::array<std::array<char, COLS>, ROWS>& gameBoard);
void printCurrentGameBoard(std::array<std::array<char, COLS>, ROWS>& gameBoard);
bool validateInputInRange(int col, int row);
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

bool validateInputInRange(int row, int col) {
    if ((row >= 0 && row < ROWS) && (col >= 0 && col < COLS)) {
        return true;
    } else {
        return false;
    }
}

bool cellAlreadyOccupied(int row, int col, std::array<std::array<char, COLS>, ROWS> gameBoard) {
    return (gameBoard[row][col] != ' ');
}

void getUserInput(bool xTurn, std::array<std::array<char, COLS>, ROWS> gameBoard) {
    char currentPlayer = xTurn ? 'X' : 'O';

    std::cout << "It is " << currentPlayer << "'s turn" << std::endl;
    std::cout << "Please enter the row THEN the column, each from 0, 1, or 2, separated by a space" << std::endl;

    int rowValue;
    int colValue;
    std::cin >> rowValue >> colValue;

    // validate inputs
    while (true) {

        
        if (std::cin.fail()) { // VALIDATE INPUTS ARE INTEGERS
            std::cout << "You did not enter an integer. " << std::endl;

            std::cin.clear(); // clear the error state of the cin object
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the input buffer

            std::cout << "Try again: " << std::endl;
            std::cin >> colValue >> rowValue;
        } else if (!validateInputInRange(rowValue, colValue)) { // VALIDATED INPUTS ARE IN RANGE
            std::cout << "Entered values are out of range." << std::endl;

            std::cin.clear(); // clear the error state of the cin object
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the input buffer
            
            std::cout << "Try again: " << std::endl;
            std::cin >> colValue >> rowValue;
        } else if (cellAlreadyOccupied(rowValue, colValue, gameBoard)) { // VALIDATE CELL ISN'T ALREADY OCCUPIED
            std::cout << "Cell is already occupied. " << std::endl;

            std::cin.clear(); // clear the error state of the cin object
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the input buffer

            std::cout << "Try again: " << std::endl;
            std::cin >> colValue >> rowValue;
        }

        break;
        
    }

    std::cout << "Entered values:" << std::endl;
    std::cout << "Row: " << rowValue << std::endl << std::endl;
    std::cout << "Column: " << colValue << std::endl;

    gameBoard[rowValue][colValue] = currentPlayer;
}