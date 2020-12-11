cmake_minimum_required(VERSION 3.17)
project(TurboHiker)

set(CMAKE_CXX_STANDARD 11)

add_executable(TurboHiker main.cpp
        "Observer Pattern/Observer.cpp" "Observer Pattern/Observer.h"
        "Observer Pattern/Observable.cpp" "Observer Pattern/Observable.h"
        GameController/Controller.cpp GameController/Controller.h
        GameModel/Model.cpp GameModel/Model.h
        GameView/View.cpp GameView/View.h
        Random.cpp Random.h
        GameModel/Scoring.cpp GameModel/Scoring.h
        GameModel/Game.cpp GameModel/Game.h
        GameModel/World.cpp GameModel/World.h
        GameModel/Lane.cpp GameModel/Lane.h)