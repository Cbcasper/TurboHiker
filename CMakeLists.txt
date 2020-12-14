cmake_minimum_required(VERSION 3.17)
project(TurboHiker)

set(CMAKE_CXX_STANDARD 11)

add_executable(TurboHiker main.cpp
        Controller/World.cpp Controller/World.h
        Random.cpp Random.h
        Model/Scoring.cpp Model/Scoring.h
        Model/GameModel.cpp Model/GameModel.h
        Model/WorldModel.cpp Model/WorldModel.h
        Model/LaneModel.cpp Model/LaneModel.h
        View/LaneView.cpp View/LaneView.h
        View/WorldView.cpp View/WorldView.h
        View/GameView.cpp View/GameView.h
        Event/Event.cpp Event/Event.h
        Event/ViewEvent/ViewClickEvent.cpp Event/ViewEvent/ViewClickEvent.h
        Model/HikerModel.cpp Model/HikerModel.h
        View/HikerView.cpp View/HikerView.h Event/ViewEvent/ViewHikerEvent.cpp Event/ViewEvent/ViewHikerEvent.h Event/ModelEvent/ModelEvent.cpp Event/ModelEvent/ModelEvent.h Event/ViewEvent/ViewEvent.cpp Event/ViewEvent/ViewEvent.h Event/ModelEvent/ModelHikerEvent.cpp Event/ModelEvent/ModelHikerEvent.h)