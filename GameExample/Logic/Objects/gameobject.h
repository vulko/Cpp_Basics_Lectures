#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <string>
#include "idrawable.h"

using namespace std;

//class PlayerAvatar : public IDrawable {
//};

class GameObject : public IDrawable {
private:
    int posX;
    int posY;
    string mName;

public:
    GameObject() {}
    virtual ~GameObject() {}

    GameObject(string name)
        : posX(0),
          posY(0),
          mName(name) {}

    void setPos(int x, int y) {
        posX = x;
        posY = y;
    }

    int getX() { return posX; }
    int getY() { return posY; }
    string getName() { return mName; }

};

#endif // GAMEOBJECT_H
