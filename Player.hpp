// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.hpp>
#include "./Object.hpp"
#include "./Animation.hpp"

class Player : public Object {
    private:
        float speed;
        float jumpPower;
        float dy;
        bool vector;
        Animation animation;
    public:
        Player();
        void update();
        void draw(sf::RenderWindow &window);
};

#endif  // PLAYER_H_