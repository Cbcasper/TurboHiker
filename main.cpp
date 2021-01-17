#include "Controller/World.h"
#include "ViewSFML/ViewSFMLFactory.h"
#include "Model/ScoringModel/ScoringModel.h"

using namespace std;

int main()
{
    shared_ptr<turboHiker::ViewFactory> viewSFMLFactory = make_shared<turboHikerSFML::ViewSFMLFactory>();
    shared_ptr<turboHiker::World> world = make_shared<turboHiker::World>(viewSFMLFactory);
    world->run();

//    turboHiker::ScoringModel scoringModel;
//    scoringModel.writeScore();
//    scoringModel.writeScore();
//    scoringModel.writeScore();
//
//    fstream highScoreFile("../HighScores/highScores.th");
//    string fileContent;
//    highScoreFile >> fileContent;
//    highScoreFile.close();
//    cout << fileContent;

    return 0;
}