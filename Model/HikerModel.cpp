//
// Created by Casper De Smet on 13/12/2020.
//

#include <sstream>
#include "HikerModel.h"
#include "WorldModel.h"

using namespace std;

namespace turboHiker
{

    HikerModel::HikerModel(const std::shared_ptr<WorldModel>& worldModel, int index): worldModel(worldModel), index(index)
    {
        cout << "HikerModel " << index << " is being constructed." << endl;
        hikerTask = packaged_task<void()>(bind(&HikerModel::live, this));
        hikerFuture = hikerTask.get_future();
        thread(move(hikerTask)).detach();
    }

    void HikerModel::live()
    {
        stringstream output;
        output << "HikerModel " << index << " started living." << endl;
        cout << output.str();

//        int i = 0;
//        while (worldModel->inWait)
//        {
//            if (i % 1000 == 0)
//                cout << boolalpha << i << " " << worldModel->inWait  << endl;
//            i++;
//        }

        int timeToLive = 5000;
        int hasLivedFor = 0;
        int interval = (index + 1) * 500;

        stringstream intervalMessage;
        intervalMessage << string(index * 5, '\t') << "HikerModel " << index << " has an interval of " << interval << endl;
        cout << intervalMessage.str();

        this_thread::sleep_for(chrono::milliseconds(1000));
        while (hasLivedFor < timeToLive)
        {
            this_thread::sleep_for(chrono::milliseconds(interval));
            stringstream message;
            message << string(index * 5, '\t') << "HikerModel " << index << " at " << hasLivedFor;
            worldModel->raiseEvent(make_shared<ModelHikerEvent>(message.str(), index));
            hasLivedFor += interval;
        }
        this_thread::sleep_for(chrono::milliseconds(1000));

        stringstream stoppedMessage;
        stoppedMessage << "HikerModel " << index << " has stopped living." << endl;
        cout << stoppedMessage.str();
    }

    void HikerModel::wait()
    {
        hikerFuture.wait();
    }
}