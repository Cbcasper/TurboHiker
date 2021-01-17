cmake_minimum_required(VERSION 3.17)
project(TurboHikerSFML)

set(CMAKE_CXX_STANDARD 11)

SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

FIND_PACKAGE(SFML 2 COMPONENTS system window graphics audio)

SET(SRC Controller/World.cpp Controller/World.h
        Utilities/Random.cpp Utilities/Random.h
        Model/ScoringModel/ScoringModel.cpp Model/ScoringModel/ScoringModel.h
        Model/WorldModel.cpp Model/WorldModel.h
        Model/LaneModel.cpp Model/LaneModel.h
        Model/HikerModel/HikerModel.cpp Model/HikerModel/HikerModel.h
        View/LaneView.cpp View/LaneView.h
        View/WorldView.cpp View/WorldView.h
        View/HikerView/HikerView.cpp View/HikerView/HikerView.h
        Event/Event.cpp Event/Event.h
        Controller/HikerController/HikerController.cpp Controller/HikerController/HikerController.h
        Controller/Game.cpp Controller/Game.h
        Controller/HikerController/ComputerHikerController/RacingHikerController.cpp Controller/HikerController/ComputerHikerController/RacingHikerController.h
        Controller/HikerController/PlayerHikerController.cpp Controller/HikerController/PlayerHikerController.h
        Utilities/Transformation.cpp Utilities/Transformation.h
        View/HikerView/PlayerHikerView.cpp View/HikerView/PlayerHikerView.h
        View/HikerView/RacingHikerView.cpp View/HikerView/RacingHikerView.h
        Model/HikerModel/PlayerHikerModel.cpp Model/HikerModel/PlayerHikerModel.h
        Model/HikerModel/RacingHikerModel.cpp Model/HikerModel/RacingHikerModel.h
        View/GameView.cpp View/GameView.h
        Model/HikerModel/Hitbox.cpp Model/HikerModel/Hitbox.h
        Model/ObstacleModel.cpp Model/ObstacleModel.h
        View/ObstacleView.cpp View/ObstacleView.h
        Model/HikerModel/StandingHikerModel.cpp Model/HikerModel/StandingHikerModel.h
        View/HikerView/StandingHikerView.cpp View/HikerView/StandingHikerView.h
        Model/HikerModel/AdversaryHikerModel.cpp Model/HikerModel/AdversaryHikerModel.h
        View/HikerView/AdversaryHikerView.cpp View/HikerView/AdversaryHikerView.h
        Controller/HikerController/ComputerHikerController/AdversaryHikerController.cpp Controller/HikerController/ComputerHikerController/AdversaryHikerController.h
        Controller/HikerController/ComputerHikerController/ComputerHikerController.cpp Controller/HikerController/ComputerHikerController/ComputerHikerController.h
        View/ScoringView.cpp View/ScoringView.h
        Model/ScoringModel/HikerScore.cpp Model/ScoringModel/HikerScore.h
        TurboHikerFactory/AbstractHiker.cpp TurboHikerFactory/AbstractHiker.h
        TurboHikerFactory/AbstractObstacle.cpp TurboHikerFactory/AbstractObstacle.h
        TurboHikerFactory/AbstractTurboHikerFactory.cpp TurboHikerFactory/AbstractTurboHikerFactory.h
        TurboHikerFactory/ModelFactory.cpp TurboHikerFactory/ModelFactory.h
        TurboHikerFactory/AbstractWorldComponent.cpp TurboHikerFactory/AbstractWorldComponent.h
        TurboHikerFactory/ViewFactory.cpp TurboHikerFactory/ViewFactory.h
        TurboHikerFactory/AbstractLane.cpp TurboHikerFactory/AbstractLane.h)

SET(SFML_SRC main.cpp
             ViewSFML/ViewSFMLFactory.cpp ViewSFML/ViewSFMLFactory.h
             ViewSFML/ObstacleViewSFML.cpp ViewSFML/ObstacleViewSFML.h
             ViewSFML/HikerViewSFML/StandingHikerViewSFML.cpp ViewSFML/HikerViewSFML/StandingHikerViewSFML.h
             ViewSFML/GameViewSFML.cpp ViewSFML/GameViewSFML.h
             ViewSFML/HikerViewSFML/RacingHikerViewSFML.cpp ViewSFML/HikerViewSFML/RacingHikerViewSFML.h
             ViewSFML/HikerViewSFML/AdversaryHikerViewSFML.cpp ViewSFML/HikerViewSFML/AdversaryHikerViewSFML.h
             ViewSFML/WorldViewSFML.cpp ViewSFML/WorldViewSFML.h
             ViewSFML/HikerViewSFML/HikerViewSFML.cpp ViewSFML/HikerViewSFML/HikerViewSFML.h
             ViewSFML/LaneViewSFML.cpp ViewSFML/LaneViewSFML.h
             ViewSFML/HikerViewSFML/PlayerHikerViewSFML.cpp ViewSFML/HikerViewSFML/PlayerHikerViewSFML.h
             ViewSFML/ViewSFMLUtilities/ShiftKeysPressed.cpp ViewSFML/ViewSFMLUtilities/ShiftKeysPressed.h
             ViewSFML/ScoringViewSFML.cpp ViewSFML/ScoringViewSFML.h)

INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

ADD_EXECUTABLE(TurboHikerSFML ${SRC} ${SFML_SRC})

TARGET_LINK_LIBRARIES(TurboHikerSFML ${SFML_LIBRARIES})

INSTALL(TARGETS TurboHikerSFML DESTINATION ${PROJECT_SOURCE_DIR}/bin)