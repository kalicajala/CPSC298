#include "TicTacToe.h"

int TicTacToeMain() {
    TicTacToe* p_game = new TicTacToe();
    p_game->play();
    delete p_game;
    return;
}



