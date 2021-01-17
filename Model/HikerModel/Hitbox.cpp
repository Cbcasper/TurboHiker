//
// Created by Casper De Smet on 29/12/2020.
//

#include "Hitbox.h"

namespace turboHiker
{
    // Compute the leftTop based on the center and size
    Hitbox::Hitbox(double centerX, double centerY, double width, double height):
            centerX(centerX), centerY(centerY), leftTopX(centerX - (width / 2)), leftTopY(centerY - (height / 2)),
            width(width), height(height)
    {}

    bool Hitbox::collidesWith(const std::shared_ptr<Hitbox>& hitbox) const
    {
        return leftTopX < hitbox->leftTopX + hitbox->width &&
               leftTopX + width > hitbox->leftTopX &&
               leftTopY < hitbox->leftTopY + hitbox->height &&
               leftTopY + height > hitbox->leftTopY;
    }

    void Hitbox::move(double newCenterX, double newCenterY)
    {
        // Set the new center
        centerX = newCenterX;
        centerY = newCenterY;
        // And compute the new leftTop
        leftTopX = centerX - (width / 2);
        leftTopY = centerY - (height / 2);
    }

    void Hitbox::moveVertically(double verticalOffset)
    {
        // Calculate a new center and move to it
        move(centerX, centerY + verticalOffset);
    }

    void Hitbox::moveHorizontally(double horizontalOffset)
    {
        // Calculate a new center and move to it
        move(centerX + horizontalOffset, centerY);
    }

    void Hitbox::setSize(const std::pair<double, double>& size)
    {
        // Set the size
        width = size.first;
        height = size.second;
        // And compute the new leftTop
        leftTopX = centerX - (width / 2);
        leftTopY = centerY - (height / 2);
    }

    double Hitbox::getWidth() const
    {
        return width;
    }

    double Hitbox::getHeight() const
    {
        return height;
    }
}