#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "gameobject.h"

class GameBoard {
public:
    static const int BOARD_HEIGHT = 50;
    static const int BOARD_WIDTH = 50;

private:
    GameObject mBoard[BOARD_HEIGHT][BOARD_WIDTH];

    GameBoard();

};

#endif // GAMEBOARD_H
