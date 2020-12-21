#include <iostream>
#include <future>
#include <thread>
#include <vector>
#include "Random.h"
#include "Controller/World.h"
#include "ViewSFML/WorldViewSFML.h"

using namespace std;

int main()
{
    shared_ptr<turboHiker::WorldView> worldViewSFML = make_shared<turboHikerSFML::WorldViewSFML>();
    shared_ptr<turboHiker::World> world = make_shared<turboHiker::World>(worldViewSFML);
    world->run();

    return 0;
}