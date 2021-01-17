//
// Created by Casper De Smet on 19/12/2020.
//

#include "Game.h"
#include "World.h"

using namespace std;

namespace turboHiker
{
    // Constructor for game: by default it has lived for 0 milliseconds, it is living, but it hasn't started yet
    Game::Game(const weak_ptr<World>& world, int timeToLive): world(world), timeToLive(timeToLive), hasLivedFor(0), living(true), started(false)
    {
        gameTask = packaged_task<void()>(bind(&Game::live, this));
        gameFuture = gameTask.get_future();
    }

    void Game::live()
    {
        // Raise event that the countdown has started
        world.lock()->handleEvent(make_shared<Event>(Event::StartCountDown, "Start counting down."));
        for (int i = 3; i >= 1; i--)
        {
            // Before raising an event, check whether the game is still running.
            // This ensures we never raise an event after the world is already deconstructed
            if (!living) return;
            // Raise event 3 times to count down
            world.lock()->handleEvent(make_shared<Event>(Event::CountDown, "Count down."));
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
        if (!living) return;
        // Set started to true and raise event to indicate it
        started = true;
        world.lock()->handleEvent(make_shared<Event>(Event::StartGame, "The game has started."));

        chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
        chrono::time_point<chrono::system_clock> end;

        while (hasLivedFor < timeToLive * 1000)
        {
            end = chrono::system_clock::now();
            // Sleep for a millisecond
            this_thread::sleep_for(chrono::microseconds(1000 - chrono::duration_cast<chrono::microseconds>(end - start).count()));

            start = chrono::system_clock::now();
            // Raise event for the tick
            if (!living) return;
            world.lock()->handleEvent(make_shared<Event>(Event::Tick));
            hasLivedFor += 1;
        }
        // Raise event to end the game
        if (!living) return;
        world.lock()->handleEvent(make_shared<Event>(Event::StopGame, chrono::milliseconds(hasLivedFor)));
    }

    Game::~Game()
    {
        if (started)
            gameFuture.wait();
    }

    void Game::stop()
    {
        // Set living to false and raise event to indicate the game has stopped
        living = false;
        world.lock()->handleEvent(make_shared<Event>(Event::StopGame, chrono::milliseconds(hasLivedFor)));
    }

    void Game::start()
    {
        // Set started to true and start the thread
        started = true;
        thread(move(gameTask)).detach();
    }
}
