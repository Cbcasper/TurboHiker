//
// Created by Casper De Smet on 13/12/2020.
//

#include <sstream>
#include "HikerModel.h"
#include "WorldModel.h"

using namespace std;

namespace turboHiker
{
    HikerModel::HikerModel(const weak_ptr<WorldModel>& worldModel, int hikerIndex): worldModel(worldModel), hikerIndex(hikerIndex), x(hikerIndex * 400 + 200), y(1300)
    {
        cout << "HikerModel " << hikerIndex << " is being constructed." << endl;
    }

    void HikerModel::receiveEvent(const shared_ptr<Event>& event)
    {
        stringstream message;
        message << "HikerModel " << hikerIndex << " received an event: " << event->what() << endl;
        cout << message.str();
        switch (event->eventType)
        {
            case Event::HikerControllerEvent:
                y -= 1;
                worldModel.lock()->raiseEvent(
                        make_shared<HikerModelEvent>(shared_from_this(), HikerEvent::StateUpdated,
                                                            "The state of hikerModel " + to_string(hikerIndex) + " was updated."));
            default:
                break;
        }
    }

    void HikerModel::setCurrentLane(const weak_ptr<LaneModel>& givenCurrentLane)
    {
        currentLane = givenCurrentLane;
    }

    std::string HikerModel::toString() const
    {
        stringstream output;
        output << "Hiker " << hikerIndex << " is at " << x << ", " << y;
        return output.str();
    }

    double HikerModel::getX() const
    {
        return x;
    }

    double HikerModel::getY() const
    {
        return y;
    }

    int HikerModel::getIndex() const
    {
        return hikerIndex;
    }
}