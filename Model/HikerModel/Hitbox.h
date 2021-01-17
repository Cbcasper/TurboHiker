//
// Created by Casper De Smet on 29/12/2020.
//

#ifndef TURBOHIKER_HITBOX_H
#define TURBOHIKER_HITBOX_H

#include <memory>

namespace turboHiker
{
    class Hitbox
    {
    private:
        // Position relative to the center
        double centerX;
        double centerY;

        // Position relative to the left top
        double leftTopX;
        double leftTopY;

        double width;
        double height;

    public:
        Hitbox(double centerX, double centerY, double width, double height);

        // Check whether it collides with a given hitbox
        bool collidesWith(const std::shared_ptr<Hitbox>& hitbox) const;

        // Move to a new center
        void move(double newCenterX, double newCenterY);
        // Move with an offset in a direction
        void moveVertically(double verticalOffset);
        void moveHorizontally(double horizontalOffset);
        void setSize(const std::pair<double, double>& size);

        double getWidth() const;
        double getHeight() const;
    };
}


#endif //TURBOHIKER_HITBOX_H
