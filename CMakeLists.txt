cmake_minimum_required(VERSION 3.17)
project(TurboHiker)

set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

SET(SRC main.cpp
        Controller/World.cpp Controller/World.h
        Random.cpp Random.h
        Model/Scoring.cpp Model/Scoring.h
        Model/WorldModel.cpp Model/WorldModel.h
        Model/LaneModel.cpp Model/LaneModel.h
        Model/HikerModel.cpp Model/HikerModel.h
        View/LaneView.cpp View/LaneView.h
        View/WorldView.cpp View/WorldView.h
        View/HikerView.cpp View/HikerView.h
        Event/Event.cpp Event/Event.h
        Event/ViewEvent/HikerViewEvent.cpp Event/ViewEvent/HikerViewEvent.h
        Event/ModelEvent/ModelEvent.cpp Event/ModelEvent/ModelEvent.h
        Event/ViewEvent/ViewEvent.cpp Event/ViewEvent/ViewEvent.h
        Event/ModelEvent/HikerModelEvent.cpp Event/ModelEvent/HikerModelEvent.h
        ViewSFML/WorldViewSFML.cpp ViewSFML/WorldViewSFML.h ViewSFML/HikerViewSFML.cpp ViewSFML/HikerViewSFML.h ViewSFML/LaneViewSFML.cpp ViewSFML/LaneViewSFML.h Controller/HikerController/HikerController.cpp Controller/HikerController/HikerController.h Event/GameEvent.cpp Event/GameEvent.h Controller/Game.cpp Controller/Game.h Event/ControllerEvent/HikerControllerEvent.cpp Event/ControllerEvent/HikerControllerEvent.h Event/ControllerEvent/ControllerEvent.cpp Event/ControllerEvent/ControllerEvent.h Controller/HikerController/RacingHikerController.cpp Controller/HikerController/RacingHikerController.h Controller/HikerController/PlayerHikerController.cpp Controller/HikerController/PlayerHikerController.h "Event/Base Classes/HikerEvent.cpp" "Event/Base Classes/HikerEvent.h")

INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

ADD_EXECUTABLE(TurboHiker ${SRC})

TARGET_LINK_LIBRARIES(TurboHiker ${SFML_LIBRARIES})

INSTALL(TARGETS TurboHiker DESTINATION ${PROJECT_SOURCE_DIR}/bin)