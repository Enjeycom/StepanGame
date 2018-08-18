// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "./Animation.hpp"
#include "./Log.hpp"

int Animation::findAnimation(std::string name) {
    for (unsigned int i = 0; i < animations.size(); i++)
        if (animations[i].name == name)
            return i;
    return -1;
}

bool Animation::loadFromFile(sf::String filename) {
    std::ifstream file("./animations/"+filename);
    if (!file.is_open()) {
        Log::write("ErrorAnimation: file not found!");
        return false;
    }
    std::string command;
    animation tmp;
    while (!file.eof()) {
        getline(file, command);
        if (command.empty())
            continue;
        size_t indx = command.find("=");
        if (indx == std::string::npos) {
            Log::write("ErrorAnimation: incorrect note!");
            return false;
        }
        std::string name = command.substr(0, indx);
        std::string value = command.substr(indx + 1, command.length() - 1);
        name.erase(std::remove(name.begin(), name.end(), ' '), name.end());
        value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
        if (name == "texture")
            texture.loadFromFile("./textures/" + value);
        if (name == "levels")
            levels = std::stoi(value);
        if (name == "name") {
            if (value[value.length() - 1] != ':') {
                Log::write("ErrorAnimation: incorrect name animation!");
                return false;
            }
            if (findAnimation(value.substr(0, value.length() - 1)) != -1) {
                Log::write("ErrorAnimation: double name animation!");
                return false;
            }
            if (tmp.name != "") {
                animations.push_back(tmp);
                tmp.name = "";
            }
            tmp.name = value.substr(0, value.length() - 1);
        }
        if (name == "level")
            tmp.level = std::stoi(value);
        if (name == "frames")
            tmp.frames = std::stoi(value);
        if (name == "speed")
            tmp.speed = std::stof(value);
        if (name == "width")
            tmp.width = std::stoi(value);
        if (name == "height")
            tmp.height = std::stoi(value);
    }
    if (tmp.name != "")
        animations.push_back(tmp);
    return true;
}

void Animation::update() {
    if (changed > -1 && changed < static_cast<int>(animations.size())) {
        frame += animations[changed].speed;
        if (frame > animations[changed].frames - 1)
            frame = 0;
        if (animations[changed].reverse) {
            int x = animations[changed].width * (static_cast<int>(frame) + 1);
            int y = animations[changed].height * animations[changed].level;
            int w = -animations[changed].width;
            int h = animations[changed].height;
            sprite->setTextureRect(sf::IntRect(x, y, w, h));
        } else {
            int x = animations[changed].width * static_cast<int>(frame);
            int y = animations[changed].height * animations[changed].level;
            int w = animations[changed].width;
            int h = animations[changed].height;
            sprite->setTextureRect(sf::IntRect(x, y, w, h));
        }
    }
}

void Animation::setSprite(sf::Sprite &sprite) {
    this->sprite = &sprite;
    this->sprite->setTexture(texture);
}

bool Animation::changeAnimation(sf::String name, bool reverse = false) {
    int indx = findAnimation(name);
    if (indx != -1) {
        changed = indx;
        animations[changed].reverse = reverse;
        return true;
    }
    return false;
}
