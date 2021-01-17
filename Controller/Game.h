//
// Created by Casper De Smet on 19/12/2020.
//

#ifndef TURBOHIKER_GAME_H
#define TURBOHIKER_GAME_H

#include <memory>
#include <thread>
#include <future>
#include <iostream>

namespace turboHiker
{
    class World;

    // Game class that raises events to count the game down, start it,
    // send a tick every millisecond and stop the game
    class Game
    {
    private:
        std::weak_ptr<World> world;

        // Members for the game thread
        std::packaged_task<void()> gameTask;
        std::future<void> gameFuture;

        // How long the game will go for at the max
        int timeToLive;
        // How long the game has been going for
        int hasLivedFor;
        // Flag to check whether the game is still going
        bool living;

        // Function executed in thread
        void live();

    public:
        // Flag to check whether the game has started yet
        bool started;

        Game(const std::weak_ptr<World>& world, int timeToLive);
        virtual ~Game();

        // Stop and start the game
        void stop();
        void start();
    };
}


#endif //TURBOHIKER_GAME_H
