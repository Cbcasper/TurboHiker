#include <iostream>
#include <future>
#include <thread>
#include <vector>
#include "Random.h"
#include "Controller/Controller.h"

using namespace std;

int main()
{
    shared_ptr<turboHiker::Controller> controller = make_shared<turboHiker::Controller>();
    controller->getWorldView()->getLane(2)->raiseEvent();
    for (int i = 0; i < 20; ++i)
        cout << turboHiker::Random::getInstance().randomInt(0, 100) << " ";

    return 0;
}