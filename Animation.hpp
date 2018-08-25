// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <SFML/Graphics.hpp>
#include <vector>

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
        sf::Texture texture;
        sf::Sprite *sprite;
        std::vector <anim> animations;
        bool work;
        float frame = 0;
        int levels = 0;
        int changed = -1;
        int findAnimation(std::string name);
    public:
        bool loadFromFile(std::string filename);
        void update();
        sf::Texture getTexture();
        void setSprite(sf::Sprite &sprite);
        bool changeAnimation(sf::String name, bool reverse);
};

#endif  // ANIMATION_H_