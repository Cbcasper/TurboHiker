#include <iostream>
#include <future>
#include <thread>
#include <vector>
#include "Random.h"
#include "Controller/World.h"

using namespace std;

int main()
{
    shared_ptr<turboHiker::WorldView> worldView = make_shared<turboHiker::WorldView>();
    shared_ptr<turboHiker::World> world = make_shared<turboHiker::World>(worldView);
    world->start();

    return 0;
}