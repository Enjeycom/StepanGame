// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <string>
#include "./Tools.hpp"
#include "./Log.hpp"
#include "./Physics.hpp"

float Tools::deltaTimeValue;
sf::Clock Tools::deltaClock;
sf::Font Tools::mainFontValue;

void Tools::updateTime() {
    deltaTimeValue = deltaClock.restart().asMicroseconds() /
    1000 * Physics::timeSpeed;
}

int Tools::getDeltaTime() {
    return deltaTimeValue;
}

void Tools::trimString(std::string *str) {
    str->erase(0, str->find_first_not_of("\t "));
    str->erase(str->find_last_not_of("\t ") + 1);
}
