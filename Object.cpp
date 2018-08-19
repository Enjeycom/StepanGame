// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include "Object.hpp"

Object::Object() {
    sprite.setScale(0.5f, 0.5f);
    frame = 0;
}

sf::Vector2f Object::getPosition() {
    return sf::Vector2f(sprite.getPosition().x +
            texture.getSize().x / 2 * sprite.getScale().x,
            sprite.getPosition().y +
            texture.getSize().y / 2 * sprite.getScale().y);
}
