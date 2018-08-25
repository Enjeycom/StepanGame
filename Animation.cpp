// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "./Animation.hpp"
#include "./Log.hpp"
#include "./Tools.hpp"
#include "./Pathways.hpp"

int Animation::findAnimation(std::string name) {
    for (unsigned int i = 0; i < animations.size(); i++)
        if (animations[i].name == name)
            return i;
    return -1;
}

bool Animation::loadFromFile(std::string filename) {
    filename = getPath("animations") + filename + ".animation";
    std::ifstream file(filename);
    if (!file.is_open()) {
        log("Error loading animation: file \"" + filename + "\" not found!");
        return false;
    }
    std::string command;
    anim tmp;
    int numStr = 0;
    while (!file.eof()) {
        getline(file, command);
        if (command.empty())
            continue;
        size_t indx = command.find("=");
        if (indx == std::string::npos) {
            log(filename + " line:" + toStr(numStr) + " Error loading animation: incorrect note!");
            return false;
        }
        std::string name = command.substr(0, indx);
        std::string value = command.substr(indx + 1, command.length() - 1);
        trim(name);
        trim(value);
        if (name == "texture"){
            if (!texture.loadFromFile(getPath("textures") + value + ".texture"))
                return false;
        }
        if (name == "levels")
            levels = std::stoi(value);
        if (name == "name") {
            if (value[value.length() - 1] != ':') {
                log(filename + " line:" + toStr(numStr) + " Error loading animation: incorrect animation name!");
                return false;
            }
            if (findAnimation(value.substr(0, value.length() - 1)) != -1) {
                log(filename + " line:" + toStr(numStr) + " Error loading animation: animation with the name already added!");
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
        numStr++;
    }
    if (tmp.name != "")
        animations.push_back(tmp);
    return true;
}

void Animation::update() {
    if (changed > -1 && changed < static_cast<int>(animations.size())) {
        frame += animations[changed].speed * deltaTime;
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
    texture.setSmooth(8);
    this->sprite->setTexture(texture.getTexture());
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

sf::Texture Animation::getTexture() {
    return texture;
}

Animation::Animation(const Animation &object) {
    *this = object;
    this->texture = object.getTexture().get;
}
