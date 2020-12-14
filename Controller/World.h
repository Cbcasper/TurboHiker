//
// Created by Casper De Smet on 04/12/2020.
//

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include <iostream>
#include <memory>
#include "../View/WorldView.h"
#include "../Model/WorldModel.h"

namespace turboHiker
{
    class World
    {
    private:
        std::shared_ptr<WorldModel> worldModel;
        std::shared_ptr<WorldView> worldView;

    public:
        explicit World(const std::shared_ptr<WorldView>& worldView);
        void raiseViewEvent(const std::shared_ptr<ViewEvent>& event);
        void raiseModelEvent(const std::shared_ptr<ModelEvent>& event);

        const std::shared_ptr<WorldModel>& getModel() const;
        const std::shared_ptr<WorldView>& getView() const;

        void start();
    };
}


#endif //TURBOHIKER_WORLD_H
