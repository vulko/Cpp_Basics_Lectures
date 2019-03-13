#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>

using namespace std;

class GameObject {
private:
    int posX;
    int posY;
    string mName;

public:
    GameObject() {}

    GameObject(string name)
        : posX(0),
          posY(0),
          mName(name) {}

    void draw() {
        cout << mName << " is at " << getX() << ":" << getY() << endl;
    }

    void setPos(int x, int y) {
        posX = x;
        posY = y;
    }

    int getX() { return posX; }
    int getY() { return posY; }
    string getName() { return mName; }
};

#endif // GAMEOBJECT_H
