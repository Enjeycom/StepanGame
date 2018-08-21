// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef MAP_H_
#define MAP_H_

#include <vector>
#include <string>

class Map {
    private:
        std::vector<std::vector<int>> staticObjects;
    public:
        bool loadFromFile(std::string filename);
};

#endif  // MAP_H_