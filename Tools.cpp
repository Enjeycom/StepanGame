// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <string>
#include "./Tools.hpp"
#include "./Physics.hpp"

float Tools::deltaTimeValue;
sf::Clock Tools::deltaClock;

void Tools::updateTime() {
    deltaTimeValue = deltaClock.restart().asMicroseconds() / 1000 * Physics::timeSpeed;
}

int Tools::getDeltaTime() {
    return deltaTimeValue;
}

void Tools::trimString(std::string &str, char sym) {
    std::string res;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] != sym)
            res += str[i];
    }
    str = res;
}