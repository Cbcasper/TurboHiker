//
// Created by Casper De Smet on 11/12/2020.
//

#include "ClickEvent.h"

turboHiker::ClickEvent::ClickEvent(const string& message): Event(message)
{

}

string turboHiker::ClickEvent::what()
{
    return message + ", of type Click Event";
}
