// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include "./Object.hpp"
#include "./Map.hpp"
#include "./Log.hpp"

Object::Object() {
    id = 0;
    solid = false;
}

void Object::setId(int id) {
    this->id = id;
}

void Object::setSolid(bool solid) {
    this->solid = solid;
}

void Object::setAnimation(std::string filename) {
    animation.loadFromFile(filename);
    animation.setSprite(&sprite);
    if(!animation.changeAnimation("main", true))
        log("Animation changed error: animation not found!");
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

bool Object::isSolid() {
    return solid;
}

sf::Vector2f Object::getVector(){
    return {dx ,dy};
}

sf::Vector2f Object::getPosition() {
    return sprite.getPosition();
}

void Object::update() {
    animation.changeAnimation("main",true);    
    animation.update();
}

void Object::draw(sf::RenderWindow *window) {
    window->draw(sprite);
}
