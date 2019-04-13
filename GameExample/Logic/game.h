#ifndef GAME_H
#define GAME_H

#include <thread>
#include <iostream>
#include <vector>
#include "Objects/monster.h"
#include "Objects/player.h"

using namespace std;

enum GameState
{
   // объект Game не инициализирован и не готов к использованию
   Unknown,

   // объект Game инициализирован и готов к использованию
   Initialized,

   // игра начата и в процессе
   Started,

   // игра остановлена… например закончилась или пользователь
   // завершил игровую сессию
   Stopped
};

typedef std::vector<IDrawable*> DrawableVector;

class Game
{

public:
    Game();
    ~Game();

    void dispose() { mIsGameLoopRunning = false; }
    void start() { mState = GameState::Started; }
    void stop() { mState = GameState::Stopped; }

    Player* getPlayer() { return mPlayer; }
    Monster* getMonster() { return mMonster; }

private:
    thread* mGameThread;
    void gameLoop();
    GameState mState = GameState::Unknown;

    bool mIsGameLoopRunning = true;

    Player* mPlayer = new Player("SuperHero");
    Monster* mMonster = new Monster("Bear");
    DrawableVector mDrawables;

    void drawAll();

};

#endif // GAME_H
