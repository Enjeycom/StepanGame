// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include "./ManagerTextures.hpp"
#include "./Pathways.hpp"

std::vector<text> ManagerTextures::textures;

bool ManagerTextures::loadTextureFromFile(std::string filename) {
    sf::Texture texture;
    if (texture.loadFromFile(getPath("textures") + filename + ".textures"))
        return false;
    textures.push_back({texture, filename});
    return true;
}

sf::Texture ManagerTextures::getTexture(std::string filename) {

}