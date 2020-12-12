//
// Created by Casper De Smet on 11/12/2020.
//

#include "Event.h"

turboHiker::Event::Event(const string& message) : message(message)
{}

string turboHiker::Event::what()
{
    return "Event: " + message;
}
