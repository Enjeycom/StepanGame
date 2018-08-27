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
    sf::Sprite sprite;
    Animation animation;
 public:
    Object();
    void setId(int id);
    void setAnimation(const std::string filename);
    void setPosition(int x, int y);
    void update();
    void draw(const sf::RenderWindow &window);
    int getId();
    sf::Vector2f getPosition();
};

#endif  // OBJECT_HPP_
