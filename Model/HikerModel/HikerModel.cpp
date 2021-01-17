//
// Created by Casper De Smet on 13/12/2020.
//

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

#include <sstream>
#include "HikerModel.h"
#include "../WorldModel.h"
#include "../ObstacleModel.h"

using namespace std;

namespace turboHiker
{
    // x is initialized to 0, it is later defined when initializing the lane
    HikerModel::HikerModel(const weak_ptr<WorldModel>& worldModel, int hikerIndex):
                worldModel(worldModel), hikerIndex(hikerIndex), x(0), y(worldModel.lock()->getWorldY() - 30),
                hitbox(make_shared<Hitbox>(x, y, 0, 0)), stride(0.12), moving(true)
    {}

    void HikerModel::handleEvent(const shared_ptr<Event>& event)
    {
        switch (event->eventType)
        {
            case Event::MoveLeft: x -= 50;          break;
            case Event::MoveRight: x += 50;         break;
            case Event::MoveForward: y -= stride;   break;
            case Event::MoveBackward: y += stride;  break;
            case Event::Jump: y -= stride * 600;    break;
            default:
                break;
        }
        // After every position change, move the hitbox to the new location
        hitbox->move(x, y);
    }

    void HikerModel::setCurrentLane(const weak_ptr<LaneModel>& givenCurrentLane)
    {
        currentLane = givenCurrentLane;
    }

    void HikerModel::initializeCurrentLane(const weak_ptr<LaneModel>& givenCurrentLane)
    {
        currentLane = givenCurrentLane;
        // Compute x based on the lane index
        double laneWidth = worldModel.lock()->getWorldX() / 4;
        x = (laneWidth * currentLane.lock()->getLaneIndex()) + (laneWidth / 2);
        // Update the view and request the size of the hitbox
        worldModel.lock()->raiseEvent(make_shared<Event>(Event::HikerStateUpdated, shared_from_this()));
        worldModel.lock()->raiseEvent(make_shared<Event>(Event::RequestHikerHitboxSize, hikerIndex));
    }

    string HikerModel::toString() const
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

    int HikerModel::getLaneIndex() const
    {
        return currentLane.lock()->getLaneIndex();
    }

    std::shared_ptr<LaneModel> HikerModel::getLane()
    {
        return currentLane.lock();
    }

    bool HikerModel::collidesWith(const shared_ptr<HikerModel>& hiker)
    {
        // Check whether the hitbox of the hiker collides with mine (if the hiker is not this one)
        if (hiker->getIndex() == hikerIndex)
            return false;
        return hitbox->collidesWith(hiker->hitbox);
    }

    void HikerModel::setHitboxSize(const std::pair<float, float>& hitboxSize)
    {
        // Transform the size and set it
        hitbox->setSize(Transformation::getInstance().screenToWorldDimensions(hitboxSize));
    }

    bool HikerModel::collidesWith(const shared_ptr<ObstacleModel>& obstacle)
    {
        return hitbox->collidesWith(obstacle->getHitbox());
    }

    std::pair<float, float> HikerModel::getHitboxSize()
    {
        return {hitbox->getWidth(), hitbox->getHeight()};
    }

    double HikerModel::getHitboxHeight()
    {
        return hitbox->getHeight();
    }

    double HikerModel::getHitboxWidth()
    {
        return hitbox->getWidth();
    }

    const shared_ptr<Hitbox>& HikerModel::getHitbox() const
    {
        return hitbox;
    }

    bool HikerModel::finished() const
    {
        return y < -50;
    }

    bool HikerModel::isMoving() const
    {
        return moving;
    }

    void HikerModel::setMoving(bool newValue)
    {
        moving = newValue;
    }
}