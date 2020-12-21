//
// Created by Casper De Smet on 19/12/2020.
//

#include "Game.h"
#include "World.h"

using namespace std;

namespace turboHiker
{
    Game::Game(const weak_ptr<World>& world, int timeToLive): world(world), timeToLive(timeToLive), hasLivedFor(0), living(true)
    {
        gameTask = packaged_task<void()>(bind(&Game::live, this));
        gameFuture = gameTask.get_future();
        thread(move(gameTask)).detach();
    }

    void Game::live()
    {
        for (int i = 3; i >= 1; i--)
        {
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << i << endl;
        }
        world.lock()->raiseGameEvent(make_shared<GameEvent>(GameEvent::Start, "The game has started."));
        while (hasLivedFor++ < timeToLive)
        {
            if (!living)
                return;
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
        world.lock()->raiseGameEvent(make_shared<GameEvent>(GameEvent::Stop, "The game has stopped."));
    }

    Game::~Game()
    {
        cout << "Waiting for gameFuture..." << endl;
        gameFuture.wait();
        cout << "GameFuture has finished." << endl;
    }

    void Game::stop()
    {
        living = false;
    }
}
