// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include "./ManagerTextures.hpp"
#include "./Pathways.hpp"
#include "./Log.hpp"

std::vector<text*> ManagerTextures::textures;

bool ManagerTextures::loadTextureFromFile(std::string filename) {
    sf::Texture *texture = new sf::Texture();
    if (!texture->loadFromFile(getPath("textures") + filename + ".texture"))
        return false;
    textures.push_back(new text{texture, filename});
    return true;
}

sf::Texture* ManagerTextures::getTexture(std::string filename) {
    for (size_t i = 0; i < textures.size(); i++) {
        if (filename == textures[i]->filename)
            return textures[i]->texture;
    }
    if (loadTextureFromFile(filename))
        return textures[textures.size()-1]->texture;
    return new sf::Texture;
}
