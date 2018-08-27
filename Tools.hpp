// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef TOOLS_H_
#define TOOLS_H_

#pragma once
#include <string>
#include <SFML/Graphics.hpp>

#define toStr std::to_string
#define deltaTime Tools::getDeltaTime()
#define trim Tools::trimString
#define mainFont Tools::mainFontValue

class Tools{
 private:
    static sf::Clock deltaClock;
    static float deltaTimeValue;
 public:
    static sf::Font mainFontValue;
    static void updateTime();
    static int getDeltaTime();
    static void trimString(const std::string &str, char sym = ' ');
};

#endif  // TOOLS_H_
