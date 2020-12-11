#include <iostream>
#include <future>
#include <thread>
#include <vector>
#include "GameController/Controller.h"

using namespace std;

int main()
{
    shared_ptr<turboHiker::Controller> controller = make_shared<turboHiker::Controller>();
    shared_ptr<turboHiker::Model> model = make_shared<turboHiker::Model>();
    shared_ptr<turboHiker::View> view = make_shared<turboHiker::View>();

    model->addObserver(view);
    view->addObserver(controller);

    return 0;
}