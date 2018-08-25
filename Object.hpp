// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef OBJECT_H_
#define OBJECT_H_

#include <SFML/Graphics.hpp>
#include "./Animation.hpp"

class Object {
    protected:
        int id;
        sf::Sprite sprite;
        Animation animation;
    public:
        Object();
        void setId(int id);
        void setAnimation(std::string filename);
        void setPosition(int x, int y);
        int getId();
        sf::Vector2f getPosition();
        void update();
        void draw(sf::RenderWindow &window);
        Object copy();
};

#endif  // OBJECT_H_