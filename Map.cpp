// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <fstream>
#include "./Pathways.hpp"
#include "./Log.hpp"
#include "./Map.hpp"

bool Map::loadFromFile(std::string filename) {
    filename = getPath("maps") + filename + ".map";
    std::ifstream file(filename);
    if (!file.is_open()) {
        log("Error map loading: file \""+filename+" not found!");
        return false;
    }
    int sizeX, sizeY;
    if (!(file >> sizeX >> sizeY)) {
        log("Error map loading: incorrect file!");
        return false;
    }
    for (int i = 0; i < sizeY; i++) {
        staticObjects.push_back(std::vector<int>());
        for (int j = 0; j < sizeX; j++) {
            int tmp;
            if (!file >> tmp) {
                log("Error map loading: incorrect file!");
                return false;
            }
            staticObjects[i].push_back(tmp);
        }
    }
    return true;
}