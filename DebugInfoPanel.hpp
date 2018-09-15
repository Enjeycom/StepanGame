// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef DEBUGINFOPANEL_HPP_
#define DEBUGINFOPANEL_HPP_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

struct info {
    std::string value;
    std::string name;
};

class DebugInfoPanel {
 private:
    static std::vector<info> infoes;
    static int fpsCount;
    static float prewTime;
    static float newTime;
 public:
    static void set(std::string name, std::string value);
    static void set(std::string name, int value);
    static void set(std::string name, double value);
    static void set(std::string name, bool value);
    static void draw(sf::RenderWindow *window);
};

#define setInfo DebugInfoPanel::set

#endif  // DEBUGINFOPANEL_HPP_
