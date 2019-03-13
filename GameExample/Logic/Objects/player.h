#ifndef PLAYER_H
#define PLAYER_H

#include "gameobject.h"

class Player : public GameObject {
private:

public:
    Player(string name)
        : GameObject(name) {
    }

    void move(int x, int y) {
        setPos(getX() + x, getY() + y);
    }
};

#endif // PLAYER_H
