#if !defined(TICTACTOE_H)
#define TICTACTOE_H
#include <utility>
/// @file TicTacToe.h
/// @brief header file for TicTacToe class
/// @author Kali Cajala

class TicTacToe {
    public:
        // contrustor, destructor, and play function
        TicTacToe();
        ~TicTacToe();
        void play();
    
    private:
        // 2d array variable
        char ** pp_cGrid;
        // player variable
        int currentPlayer;

        // private functions
        void initializeGrid();
        void displayGrid();
        bool makeMove(int row, int col);
        bool isGridFull();
        char checkWin();
        bool checkDraw();
        void computerMove();
        bool isValidMove(int row, int col);
        std::pair<int, int> getComputerMove();
};

#endif