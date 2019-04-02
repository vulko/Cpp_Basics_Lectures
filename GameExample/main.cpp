#include <iostream>
#include <functional>
#include <vector>

#include "Logic/Objects/gameobject.h"
#include "Logic/Objects/monster.h"
#include "Logic/Objects/player.h"
#include "Logic/gameboard.h"
#include "Logic/game.h"

using namespace std;

void drawMe(IDrawable *obj) {
    obj->draw();
}

void drawAll(IDrawable *obj[2]) {
    for (int i = 0; i < 2; ++i) {
        obj[i]->draw();
    }
}


void getHash(string str, string str1, int a) {
    if (str.length() > 0) {
        cout << str;
    } else {
        cout << "NULL";
    }

    cout << ((str.length() > 0) ? str
                                : "NULL");
}

int main(int argc, char *argv[])
{
    int a = 0;
    Game* game = new Game();

    Player mPlayer("SuperHero");
    Monster mMonster("Bear");
    mMonster.setPos(1, 1);

    IDrawable* drawables[2];
    drawables[0] = &mPlayer;
    drawables[1] = &mMonster;

    char userInput = 0;
    while (userInput != 'x') {
        cin >> userInput;
        if (userInput == 'n') {
            game->start();
        }
        if (userInput == 'e') {
            game->stop();
        }

        if (userInput == 'w') {

            if (mPlayer.getY() + 1 < GameBoard::BOARD_HEIGHT) {

            }
            mPlayer.move(0, 1);
        } else if (userInput == 's') {
            mPlayer.move(0, -1);
        } else if (userInput == 'a') {
            mPlayer.move(-1, 0);
        } else if (userInput == 'd') {
            mPlayer.move(1, 0);
        }

        if (mPlayer.getX() == mMonster.getX()
                && mPlayer.getY() == mMonster.getY()) {
            cout << mPlayer.getName() << " will fight " << mMonster.getName();
        }

        drawAll(drawables);
    }

    return 0;
}
