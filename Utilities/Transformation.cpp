//
// Created by Casper De Smet on 21/12/2020.
//

#include "Transformation.h"

using namespace std;

namespace turboHiker
{
    Transformation& Transformation::getInstance()
    {
        static Transformation transformation;
        return transformation;
    }

    pair<int, int> Transformation::worldToScreen(double x, double y) const
    {
        return {static_cast<int>(round(x * worldToScreenRatioX)),
                static_cast<int>(round((y - currentY) * worldToScreenRatioY))};
    }

    pair<int, int> Transformation::worldToScreen(const pair<double, double>& worldCoordinates) const
    {
        return worldToScreen(worldCoordinates.first, worldCoordinates.second);
    }

    pair<double, double> Transformation::screenToWorld(int x, int y) const
    {
        return {x * screenToWorldRatioX, y * screenToWorldRatioY + currentY};
    }

    pair<double, double> Transformation::screenToWorld(const pair<int, int>& screenCoordinates) const
    {
        return screenToWorld(screenCoordinates.first, screenCoordinates.second);
    }

    std::pair<double, double> Transformation::screenToWorldDimensions(const pair<float, float>& screenCoordinates) const
    {
        return {screenCoordinates.first * screenToWorldRatioX, screenCoordinates.second * screenToWorldRatioY};
    }

    void Transformation::setRatios(int screenX, int screenY, double worldX, double worldY, bool resize)
    {
        double screenRatio = double(screenY) / double(screenX);
        double visibleWorldY = worldX * screenRatio;
        worldToScreenRatioX = screenX / worldX;
        worldToScreenRatioY = screenY / visibleWorldY;
        screenToWorldRatioX = worldX / screenX;
        screenToWorldRatioY = visibleWorldY / screenY;

        if (!resize)
            currentY = worldY - visibleWorldY;
    }

    void Transformation::moveViewport(double offset)
    {
        currentY -= offset * screenToWorldRatioY;
    }
}