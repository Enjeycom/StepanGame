// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <string>
#include <SFML/Graphics.hpp>
#include "./Animation.hpp"

class Object {
 protected:
    int id;
    bool solid;
    float dy, dx;
    sf::Sprite sprite;
    Animation animation;
 public:
    Object();
    void setId(int id);
    void setSolid(bool solid);
    void setAnimation(const std::string filename);
    void setPosition(int x, int y);
    void update();
    void draw(sf::RenderWindow *window);
    int getId();
    bool isSolid();
    sf::Vector2f getVector();
    sf::Vector2f getPosition();
};

#endif  // OBJECT_HPP_
