//
// Created by Casper De Smet on 13/12/2020.
//

#ifndef TURBOHIKER_HIKERMODEL_H
#define TURBOHIKER_HIKERMODEL_H

#include <memory>
#include <future>
#include <thread>
#include <iostream>
#include "../Event/ModelEvent/ModelHikerEvent.h"

namespace turboHiker
{
    class WorldModel;

    class HikerModel
    {
    private:
        int index;
        std::shared_ptr<WorldModel> worldModel;
        std::packaged_task<void()> hikerTask;
        std::future<void> hikerFuture;

        void live();

    public:
        HikerModel(const std::shared_ptr<WorldModel>& worldModel, int index);

        void wait();
    };
}


#endif //TURBOHIKER_HIKERMODEL_H
