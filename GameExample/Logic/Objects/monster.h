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

};

#endif // MONSTER_H
