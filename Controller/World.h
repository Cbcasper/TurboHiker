//
// Created by Casper De Smet on 04/12/2020.
//

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#define TIMETOLIVE 10

#include <iostream>
#include <vector>
#include <memory>
#include "../View/WorldView.h"
#include "../Model/WorldModel.h"
#include "HikerController/HikerController.h"
#include "HikerController/RacingHikerController.h"
#include "HikerController/PlayerHikerController.h"
#include "../Event/GameEvent.h"
#include "Game.h"
#include "../Event/ControllerEvent/HikerControllerEvent.h"
#include "../Event/ModelEvent/HikerModelEvent.h"

namespace turboHiker
{
    class World: public std::enable_shared_from_this<World>
    {
    private:
        std::shared_ptr<Game> game;
        std::shared_ptr<WorldModel> worldModel;
        std::shared_ptr<WorldView> worldView;
        std::vector<std::shared_ptr<HikerController>> hikerControllers;

        void construct();

    public:
        enum HikerType {PlayerHiker, RacingHiker};

        explicit World(const std::shared_ptr<WorldView>& worldView);
        virtual ~World();

        void raiseViewEvent(const std::shared_ptr<ViewEvent>& event);
        void raiseModelEvent(const std::shared_ptr<ModelEvent>& event);
        void raiseGameEvent(const std::shared_ptr<GameEvent>& event);
        void raiseControllerEvent(const std::shared_ptr<ControllerEvent>& event);

        const std::shared_ptr<WorldModel>& getModel() const;
        const std::shared_ptr<WorldView>& getView() const;

        void run();

        void constructHikerController(int i, HikerType type);
    };
}


#endif //TURBOHIKER_WORLD_H
