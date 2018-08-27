// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include "./Object.hpp"
#include "./Map.hpp"
#include "./Log.hpp"

Object::Object() {
    id = 0;
}

void Object::setId(int id) {
    this->id = id;
}

void Object::setAnimation(std::string filename) {
    animation.loadFromFile(filename);
    animation.setSprite(sprite);
}

void Object::setPosition(int x, int y) {
    sprite.setPosition(x, y);
    if (id != 0) {
        float scaleX = static_cast<float>(mapSize) /
        static_cast<float>(sprite.getTexture()->getSize().x);
        float scaleY = static_cast<float>(mapSize) /
        static_cast<float>(sprite.getTexture()->getSize().y);
        sprite.setScale(scaleX, scaleY);
    }
}

int Object::getId() {
    return id;
}

sf::Vector2f Object::getPosition() {
    return sprite.getPosition();
}

void Object::update() {
    animation.update();
}

void Object::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}
