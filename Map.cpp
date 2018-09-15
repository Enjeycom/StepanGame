// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <dirent.h>
#include <fstream>
#include "./Pathways.hpp"
#include "./Log.hpp"
#include "./Map.hpp"
#include "./Tools.hpp"
#include "./Camera.hpp"

std::vector<Object> Map::objects;
std::vector<std::vector<Object>> Map::staticObjects;
int Map::sizeObjects;

bool Map::loadFromFile(std::string filename) {
    log("Loading map...");

    filename = getPath("maps") + filename + ".map";
    std::ifstream file(filename);
    if (!file.is_open()) {
        log("Error map loading: file \""+filename+" not found!");
        return false;
    }
    int sizeX, sizeY;
    log("Read size map...");
    if (!(file >> sizeX >> sizeY >> sizeObjects)) {
        log("Error map loading: incorrect file!");
        return false;
    }
    log("Read map...");
    for (int i = 0; i < sizeY; i++) {
        staticObjects.push_back(std::vector<Object>());
        for (int j = 0; j < sizeX; j++) {
            int tmp;
            if (!(file >> tmp)) {
                log("Error map loading: incorrect file!");
                return false;
            }
            Object object = searchObject(tmp);
            object.setPosition(j * sizeObjects, i * sizeObjects);
            staticObjects[i].push_back(object);
        }
    }
    return true;
}

bool Map::loadObjects() {
    log("Loading objects...");

    std::vector<std::string> files;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(getPath("objects").c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            files.push_back(ent->d_name);
        }
        closedir(dir);
    } else {
        log("Error objects loading: folder \"" +
        getPath("objects") + "\" not found!");
        return false;
    }
    for (size_t i = 0; i < files.size(); i++) {
        if (files[i].size() < 9)
            continue;
        if (files[i].substr(files[i].size()-7, files[i].size()-1) != ".object")
            continue;
        Object object;
        std::string filename = getPath("objects") + files[i];
        std::ifstream file(filename);
        while (!file.eof()) {
            std::string command;
            std::string mode;
            int numStr = 0;
            while (!file.eof()) {
                getline(file, command);
                if (command.empty())
                    continue;
                if (command == "characters:" || command == "effects:") {
                    mode = command;
                    continue;
                }
                size_t indx = command.find("=");
                if (indx == std::string::npos) {
                    log(filename + " line:" + toStr(numStr) +
                    " Error loading onbject: incorrect note!");
                    return false;
                }
                std::string name = command.substr(0, indx);
                std::string value = command.substr(indx + 1,
                                    command.length() - 1);
                trim(&name);
                trim(&value);
                if (mode == "characters:") {
                    if (name == "id")
                        object.setId(std::stoi(value));
                    if (name == "solid") {
                        int a = std::stoi(value);
                        if (a == 0)
                            object.setSolid(false);
                        else
                            object.setSolid(true);
                    }
                    if (name == "animation")
                        object.setAnimation(value);
                }
                numStr++;
            }
        }
        objects.push_back(object);
    }
    return true;
}

Object Map::searchObject(int id) {
    for (size_t i = 0; i < objects.size(); i++) {
        if (objects[i].getId() == id)
            return objects[i];
    }
    return Object();
}

void Map::update() {
    for (size_t i = 0; i < staticObjects.size(); i++) {
        for (size_t j = 0; j < staticObjects[i].size(); j++) {
            staticObjects[i][j].update();
        }
    }
}

void Map::draw(sf::RenderWindow *window, Camera *camera) {
    for (size_t i = 0; i < staticObjects.size(); i++) {
        for (size_t j = 0; j < staticObjects[i].size(); j++) {
            if (camera->checkIn(&staticObjects[i][j])){
                staticObjects[i][j].draw(window);
            }
        }
    }
}

sf::Vector2i Map::getSize() {
    return { static_cast<int>(staticObjects[0].size()),
            static_cast<int>(staticObjects.size())};
}

Object Map::getAtPosition(int x, int y) {
    if (x >= 0 && x < getSize().x && y >= 0 && y < getSize().y)
        return staticObjects[y][x];
    return Object();
}

int Map::getSizeObject() {
    return sizeObjects;
}
