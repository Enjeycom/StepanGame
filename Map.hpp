// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef MAP_H_
#define MAP_H_

#include <vector>
#include <string>
#include "./Object.hpp"

class Map {
    private:
        static std::vector<Object> objects;
        static std::vector<std::vector<Object>> staticObjects;
    public:
        static bool loadFromFile(std::string filename);
        static bool loadObjects();
        static Object searchObject(int id);
        static void update();
        static void draw(sf::RenderWindow &window);
};

#endif  // MAP_H_