// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <math.h>
#include "./Physics.hpp"
#include "./Player.hpp"
#include "./Tools.hpp"

Player::Player() {
    animation.loadFromFile("player");
    sprite.setPosition(0, 0);
    animation.setSprite(sprite);
    animation.changeAnimation("stay", false);
    animation.update();
    sprite.setScale(0.3f, 0.3f);
    speed = 0.5;
    jumpPower = 3;
    dy = 0;
}

void Player::update() {
    if (sprite.getPosition().y >= 480 - 256 * sprite.getScale().y) {
        animation.changeAnimation("stay", vector);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            dy = -jumpPower;
            animation.changeAnimation("jump", vector);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        vector = true;
        sprite.move(-1 * speed * deltaTime, 0);
        if (sprite.getPosition().y >= 480 - 256 * sprite.getScale().y)
        animation.changeAnimation("go", true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        vector = false;
        sprite.move(1 * speed * deltaTime, 0);
        if (sprite.getPosition().y >= 480 - 256 * sprite.getScale().y)
        animation.changeAnimation("go", false);
    }
    sprite.move(0, dy * deltaTime);
    dy += Physics::g * deltaTime / 2;
    if (sprite.getPosition().y > 480 - 256 * sprite.getScale().y) {
        dy = 0;
        sprite.setPosition(sprite.getPosition().x,
        480 - 256 * sprite.getScale().y);
    }
    animation.update();
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}
