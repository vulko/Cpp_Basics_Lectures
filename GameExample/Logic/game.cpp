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

void Game::gameLoop()
{
    while (mIsGameLoopRunning) {
        switch (mState) {
            case GameState::Unknown:
                cout << "Game is not initialized!" << endl;
                break;

            case GameState::Initialized:
                cout << "Game is ready to start!" << endl;
                break;

            case GameState::Started:
                cout << "Game is RUNNING!" << endl;
                break;

            case GameState::Stopped:
                cout << "Game STOPPED!" << endl;
                break;
        }

        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}
