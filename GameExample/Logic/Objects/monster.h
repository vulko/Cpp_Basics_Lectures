#ifndef MONSTER_H
#define MONSTER_H

#include "gameobject.h"
#include <iostream>

using namespace std;

class Monster : public GameObject
{
private:

public:
    Monster(string name)
        : GameObject(name) {
    }

    virtual void draw()  {
        cout << "Monster(" << getName() << ") is at " << getX() << ":" << getY() << endl;
    }

    void move(int x, int y) {
        setPos(getX() + x, getY() + y);
    }
};

#endif // MONSTER_H
