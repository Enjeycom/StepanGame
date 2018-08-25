// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include "Object.hpp"

Object::Object() {
    
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
}

int Object::getId(){
    return id;
}

sf::Vector2f Object::getPosition() {
    return sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y);
}

void Object::update() {
    animation.update();
}

void Object::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}
