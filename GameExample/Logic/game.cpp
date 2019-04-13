#include "game.h"

Game::Game()
{
    mGameThread = new thread(&Game::gameLoop, this);
}

Game::~Game()
{
    // break loop
    mIsGameLoopRunning = false;
    // wait for thread to finish
    mGameThread->join();
    // cleanup
    delete mGameThread;
}

#include <condition_variable>
#include <mutex>
static std::mutex somelock;
static std::condition_variable cvGameStarted;

void monsterMoveLoop(Monster *monster) {
    std::unique_lock<std::mutex> guard(somelock);
    cvGameStarted.wait(guard);

    while (true) {
        if (monster->getX() >= 10 || monster->getY() >= 10) {
            monster->move(-1, -1);
        } else {
            monster->move(1, 1);
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void Game::gameLoop()
{
    std::thread monsterMoverThread(monsterMoveLoop, mMonster);
    mDrawables.push_back(mPlayer);
    mDrawables.push_back(mMonster);

    while (mIsGameLoopRunning) {
        switch (mState) {
            case GameState::Unknown:
                cout << "Game is not initialized!" << endl;
                break;

            case GameState::Initialized:
                cout << "Game is ready to start!" << endl;
                break;

            case GameState::Started:
                cvGameStarted.notify_one();
                drawAll();
                cout << "Game is RUNNING!" << endl;
                break;

            case GameState::Stopped:
                drawAll();
                cout << "Game STOPPED!" << endl;
                break;
        }

        if (mPlayer->getX() == mMonster->getX()
                && mPlayer->getY() == mMonster->getY()) {
            cout << "Battle begins!" << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void Game::drawAll() {
    cout.clear();
    for (auto i = mDrawables.begin(); i != mDrawables.end(); ++i) {
        ((IDrawable*) *i)->draw();
    }
}
