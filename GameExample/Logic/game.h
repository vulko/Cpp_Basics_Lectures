#ifndef GAME_H
#define GAME_H

#include <thread>
#include <iostream>

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


class Game
{

public:
    Game();
    ~Game();

    void dispose() { mIsGameLoopRunning = false; }
    void start() { mState = GameState::Started; }
    void stop() { mState = GameState::Stopped; }

private:
    thread* mGameThread;
    void gameLoop();
    GameState mState = GameState::Unknown;

    bool mIsGameLoopRunning = true;

};

#endif // GAME_H
