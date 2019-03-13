#include <iostream>

#include "Logic/Objects/gameobject.h"
#include "Logic/Objects/monster.h"
#include "Logic/Objects/player.h"
#include "Logic/gameboard.h"

using namespace std;

int main(int argc, char *argv[])
{
    Player mPlayer("SuperHero");
    Monster mMonster("Bear");
    mMonster.setPos(1, 1);

    char userInput = 0;
    while (userInput != 'x') {
        cin >> userInput;
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

            mPlayer.draw();
        }

    return 0;
}
