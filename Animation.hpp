// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

struct anim{
    sf::String name;
    int width;
    int height;
    int frames;
    int level;
    bool reverse;
    float speed;
};

class Animation {
 private:
    sf::Texture *texture;
    sf::Sprite *sprite;
    std::vector <anim> animations;
    bool work;
    float frame = 0;
    int levels = 0;
    int changed = -1;
    int findAnimation(std::string name);
 public:
    void update();
    void setSprite(const sf::Sprite &sprite);
    bool changeAnimation(sf::String name, bool reverse);
    bool loadFromFile(std::string filename);
    sf::Vector2i getSizeFrame();
};

#endif  // ANIMATION_HPP_
