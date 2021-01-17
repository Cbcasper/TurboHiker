//
// Created by Casper De Smet on 11/01/2021.
//

#include "ObstacleModel.h"
#include "WorldModel.h"

using namespace std;

namespace turboHiker
{
    // The hitbox is initialised with a size of 0, 0. This will later be set to the correct size
    ObstacleModel::ObstacleModel(const weak_ptr<WorldModel>& worldModel, const weak_ptr<LaneModel>& laneModel, double x, double y):
    worldModel(worldModel), currentLane(laneModel), x(x), y(y), hitbox(make_shared<Hitbox>(x, y, 0, 0)), broken(false)
    {
        // Every obstacle has a unique index
        static int indexGenerator = 0;
        index = indexGenerator;
        indexGenerator++;
    }

    std::string ObstacleModel::toString()
    {
        stringstream output;
        output << "Obstacle " << index << " at " << x << ", " << y << ", "
               << "width: " << hitbox->getWidth() << " and height: " << hitbox->getHeight() << endl;
        return output.str();
    }

    void ObstacleModel::setHitboxSize(const pair<float, float>& hitboxSize)
    {
        hitbox->setSize(Transformation::getInstance().screenToWorldDimensions(hitboxSize));
    }

    double ObstacleModel::getX() const
    {
        return x;
    }

    double ObstacleModel::getY() const
    {
        return y;
    }

    double ObstacleModel::getHitboxWidth()
    {
        return hitbox->getWidth();
    }

    double ObstacleModel::getHitboxHeight()
    {
        return hitbox->getHeight();
    }

    const shared_ptr<Hitbox>& ObstacleModel::getHitbox() const
    {
        return hitbox;
    }

    int ObstacleModel::getIndex() const
    {
        return index;
    }

    void ObstacleModel::goBroken()
    {
        broken = true;
    }

    bool ObstacleModel::isBroken() const
    {
        return broken;
    }
}
