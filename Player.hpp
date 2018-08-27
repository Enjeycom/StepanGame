// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SFML/Graphics.hpp>
#include "./Object.hpp"
#include "./Animation.hpp"

class Player : public Object {
 private:
    float speed;
    float jumpPower;
    float dy, dx;
    bool vector;
    bool onGround;
    bool onTop;
    bool onLeft;
    bool onRight;
    Animation animation;

    float cyb;
    float cxr;
    float cyt;
    float cxl;
 public:
    Player();
    void update();
    void draw(const sf::RenderWindow &window);
};

#endif  // PLAYER_HPP_
