// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef MANAGERTEXTURES_H_
#define MANAGERTEXTURES_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

struct text {
    sf::Texture texture;
    std::string filename;
};

class ManagerTextures {
    private:
        static std::vector<text> textures;
    public:
        static bool loadTextureFromFile(std::string filename);
        static sf::Texture getTexture(std::string filename);
};

#endif  // MANAGERTEXTURES_H_