/// @file TicTacToe.cpp
/// @brief generates a game of tic tac toe between the user and the computer
/// @author Kali Cajala

#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe() {
    pp_cGrid = new char*[3];
    for (int i = 0; i < 3; i++) {
        pp_cGrid[i] = new char[3];
    }
    initializeGrid();
    currentPlayer = 1;
}

TicTacToe::~TicTacToe() {
    for (int i = 0; i < 3; i++) {
        delete[] pp_cGrid[i];
    }
    delete[] pp_cGrid;
}

void TicTacToe::initializeGrid() {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            pp_cGrid[r][c] = '~';
        }
    }
}

void TicTacToe::displayGrid() {
    for (int r = 0; r < 3; r++) {
        std::cout << " ";
        for (int c = 0; c < 3; c++) {
            std::cout << pp_cGrid[r][c] << " ";
        }
        std::cout << std::endl;
    }
}

bool TicTacToe::makeMove(int row, int col) {
    if (!isValidMove(row, col)) {
        std::cout << "Invalid move. Try again." << std::endl;
        return false;
    }
    
    char mark = (currentPlayer == 1) ? 'X' : 'O';
    pp_cGrid[row][col] = mark;
    currentPlayer = 3 - currentPlayer;
    return true;
}

bool TicTacToe::isValidMove(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && pp_cGrid[row][col] == '~');
}

char TicTacToe::checkWin() {
    if ((pp_cGrid[0][0] == pp_cGrid[1][1] && pp_cGrid[1][1] == pp_cGrid[2][2]) ||
        (pp_cGrid[0][2] == pp_cGrid[1][1] && pp_cGrid[1][1] == pp_cGrid[2][0])) {
            return pp_cGrid[1][1];
        }
    else if ((pp_cGrid[0][0] == pp_cGrid[0][1] && pp_cGrid[0][1] == pp_cGrid[0][2]) ||
            (pp_cGrid[0][0] == pp_cGrid[1][0] && pp_cGrid[1][0] == pp_cGrid[2][0])) {
                return pp_cGrid[0][0];
            }
    else if ((pp_cGrid[1][0] == pp_cGrid[1][1] && pp_cGrid[1][1] == pp_cGrid[1][2]) ||
            (pp_cGrid[0][1] == pp_cGrid[1][1] && pp_cGrid[1][1] == pp_cGrid[2][1])) {
                return pp_cGrid[1][1];
            }
    else if ((pp_cGrid[2][0] == pp_cGrid[2][1] && pp_cGrid[2][1] == pp_cGrid[2][2]) ||
            (pp_cGrid[0][2] == pp_cGrid[1][2] && pp_cGrid[1][2] == pp_cGrid[2][2])) {
                return pp_cGrid[2][2];
            }
    else {
        return '~';
    }
}

bool TicTacToe::checkDraw() {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (pp_cGrid[r][c] == '~') {
                return false;
            }
        }
    }
    return true;
}

std::pair<int, int> TicTacToe::getComputerMove() {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (pp_cGrid[r][c] == '~') {
                return std::make_pair(r, c);
            }
        }
    }
    return std::make_pair(-1, -1);
}

void TicTacToe::play() {
    int row, col;
    bool gameOver = false;

    while (!gameOver) {
        displayGrid();

        if (currentPlayer == 1) {
            std::cout << "Please enter grid row number: " << std::endl;
            std::cin >> row;
            std::cout << "Please enter a grid column number: " << std::endl;
            std::cin >> col;
            while (!makeMove(row, col)) {
                std::cout << "Please enter grid row number: " << std::endl;
                std::cin >> row;
                std::cout << "Please enter a grid column number: " << std::endl;
                std::cin >> col;
            }
        }

        else {
            std::pair<int, int> computerMove = getComputerMove();
            row = computerMove.first;
            col = computerMove.second;
            makeMove(row, col);
        }

        char winner = checkWin();
        if (winner != '~') {
            displayGrid();
            std::cout << "Winner: " << winner << std::endl;
            gameOver = true;
            break;
        }
        else if (checkDraw()) {
            displayGrid();
            std::cout << "Draw!" << std::endl;
            gameOver = true;
        }
    }
}