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

    class Game
    {
    private:
        std::weak_ptr<World> world;

        std::packaged_task<void()> gameTask;
        std::future<void> gameFuture;

        int timeToLive;
        int hasLivedFor;
        bool living;

        void live();

    public:
        explicit Game(const std::weak_ptr<World>& world, int timeToLive);
        virtual ~Game();

        void stop();
    };
}


#endif //TURBOHIKER_GAME_H
