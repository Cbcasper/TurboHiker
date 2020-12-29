//
// Created by Casper De Smet on 21/12/2020.
//

#ifndef TURBOHIKER_TRANSFORMATION_H
#define TURBOHIKER_TRANSFORMATION_H

#include <utility>
#include <cmath>

namespace turboHiker
{
    class Transformation
    {
    private:
        double screenToWorldRatioX;
        double screenToWorldRatioY;
        double worldToScreenRatioX;
        double worldToScreenRatioY;

        double currentY;

        Transformation() = default;

    public:
        static Transformation& getInstance();

        void setRatios(int screenX, int screenY, double worldX, double worldY, bool resize);

        std::pair<int, int> worldToScreen(double x, double y) const;
        std::pair<int, int> worldToScreen(const std::pair<double, double>& worldCoordinates);
        std::pair<double, double> screenToWorld(int x, int y) const;
        std::pair<double, double> screenToWorld(const std::pair<int, int>& screenCoordinates);
    };
}


#endif //TURBOHIKER_TRANSFORMATION_H
