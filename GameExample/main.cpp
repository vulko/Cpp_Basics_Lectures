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
            game->getPlayer()->move(0, 1);
        } else if (userInput == 's') {
            game->getPlayer()->move(0, -1);
        } else if (userInput == 'a') {
            game->getPlayer()->move(-1, 0);
        } else if (userInput == 'd') {
            game->getPlayer()->move(1, 0);
        }
    }

    return 0;
}
