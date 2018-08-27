// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef MAP_HPP_
#define MAP_HPP_

#include <vector>
#include <string>
#include "./Object.hpp"

class Map {
 private:
    static std::vector<Object> objects;
    static std::vector<std::vector<Object>> staticObjects;
    static int sizeObjects;
 public:
    static void update();
    static void draw(const sf::RenderWindow &window);
    static bool loadFromFile(const std::string filename);
    static bool loadObjects();
    static int getSizeObject();
    static int getAtPosition(int x, int y);
    static Object searchObject(int id);
    static sf::Vector2i getSize();
};

#define mapSize Map::getSizeObject()

#endif  // MAP_HPP_
