// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef MANAGERTEXTURES_HPP_
#define MANAGERTEXTURES_HPP_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

struct text {
    sf::Texture *texture;
    std::string filename;
};

class ManagerTextures {
 private:
    static std::vector<text*> textures;
 public:
    static bool loadTextureFromFile(const std::string filename);
    static sf::Texture* getTexture(const std::string filename);
};

#define getTexture ManagerTextures::getTexture

#endif  // MANAGERTEXTURES_HPP_
