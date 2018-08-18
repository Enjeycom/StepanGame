// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef OBJECT_H_
#define OBJECT_H_

#include <SFML/Graphics.hpp>

class Object {
    protected:
        sf::Sprite sprite;
        sf::Texture texture;
        float frame;
    public:
        Object();
        sf::Vector2f getPosition();
};

#endif  // OBJECT_H_