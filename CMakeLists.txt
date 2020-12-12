cmake_minimum_required(VERSION 3.17)
project(TurboHiker)

set(CMAKE_CXX_STANDARD 11)

add_executable(TurboHiker main.cpp
        Controller/Controller.cpp Controller/Controller.h
        Random.cpp Random.h
        Model/Scoring.cpp Model/Scoring.h
        Model/GameModel.cpp Model/GameModel.h
        Model/WorldModel.cpp Model/WorldModel.h
        Model/LaneModel.cpp Model/LaneModel.h
        View/LaneView.cpp View/LaneView.h
        View/WorldView.cpp View/WorldView.h
        View/GameView.cpp View/GameView.h Model/Event.cpp Model/Event.h Model/ClickEvent.cpp Model/ClickEvent.h)