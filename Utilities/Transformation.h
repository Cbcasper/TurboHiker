//
// Created by Casper De Smet on 21/12/2020.
//

#ifndef TURBOHIKER_TRANSFORMATION_H
#define TURBOHIKER_TRANSFORMATION_H

#include <utility>
#include <cmath>
#include <iostream>

namespace turboHiker
{
    // Singleton class for transforming world coordinates to screen coordinates and back
    class Transformation
    {
    private:
        // Ratios between screen and world
        double screenToWorldRatioX;
        double screenToWorldRatioY;
        double worldToScreenRatioX;
        double worldToScreenRatioY;

        // Current y value of the viewport
        double currentY;

        Transformation() = default;

    public:
        static Transformation& getInstance();

        void setRatios(int screenX, int screenY, double worldX, double worldY, bool resize);
        void moveViewport(double offset);

        // Self explanatory function for the transformations
        std::pair<int, int> worldToScreen(double x, double y) const;
        std::pair<int, int> worldToScreen(const std::pair<double, double>& worldCoordinates) const;
        std::pair<double, double> screenToWorld(int x, int y) const;
        std::pair<double, double> screenToWorld(const std::pair<int, int>& screenCoordinates) const;
        std::pair<double, double> screenToWorldDimensions(const std::pair<float, float>& screenCoordinates) const;
    };
}


#endif //TURBOHIKER_TRANSFORMATION_H
