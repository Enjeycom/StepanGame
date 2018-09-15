// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <math.h>
#include "./Physics.hpp"
#include "./Player.hpp"
#include "./DebugInfoPanel.hpp"
#include "./Tools.hpp"
#include "./Log.hpp"
#include "./Map.hpp"

Player::Player() {
    animation.loadFromFile("player");
    sprite.setPosition(0, 0);
    animation.setSprite(&sprite);
    animation.changeAnimation("stay", false);
    animation.update();
    sprite.setScale(0.3, 0.3);
    speed = 0.3;
    jumpPower = 1;
    vector = false;
    onGround = false;
    onLeft = false;
    onRight = false;
    dy = 0;
    dx = 0;
}

void Player::update() {
    // Calculate physics
    cyb = Map::getSize().y * mapSize;
    cxr = Map::getSize().x * mapSize;
    cyt = -MAXFLOAT;
    cxl = 0;
    float x = getPosition().x;
    float y = getPosition().y;
    float w = animation.getSizeFrame().x * sprite.getScale().x;
    float h = animation.getSizeFrame().y * sprite.getScale().y;
    float xw = x + w;
    float yh = y + h;
    float mx = getPosition().x / mapSize;
    float my = getPosition().y / mapSize;
    float mxw = (x + w) / mapSize;
    dx = 0;

    // Control
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && onGround) {
        onGround = false;
        dy = -jumpPower * deltaTime;
        animation.changeAnimation("jump", vector);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        vector = true;
        dx = -speed * deltaTime;
        if (onGround)
            animation.changeAnimation("go", vector);
        else 
            animation.changeAnimation("jump", vector);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        vector = false;
        dx = speed * deltaTime;
        if (onGround)
            animation.changeAnimation("go", vector);
        else 
            animation.changeAnimation("jump", vector);
    }

    if (onGround && dx == 0)
        animation.changeAnimation("stay", vector);

    // Colision
    for (int i = x + w * 0.2; i < xw - w * 0.2; i++)
        if (Map::getAtPosition(i / mapSize, (yh + 1) / mapSize).isSolid()) {
            int tmp = static_cast<int>((yh + 1) / mapSize) * mapSize;
            if (my - tmp < cyb - tmp)
                cyb = tmp;
        }

    for (int i = x + w * 0.2; i < xw - w * 0.2; i++)
        if (Map::getAtPosition(i / mapSize, (y - 1) / mapSize).isSolid()) {
            int tmp = static_cast<int>((y - 1) / mapSize + 1) * mapSize;
            if (tmp - my < tmp - cyt)
                cyt = tmp;
        }

    for (int i = y + 2; i < yh - 2; i++)
        if (Map::getAtPosition((xw + 1) / mapSize, i / mapSize).isSolid()) {
            int tmp = static_cast<int>((xw + 1) / mapSize) * mapSize;
            if (mxw - tmp < cxr - tmp)
                cxr = tmp;
        }

    for (int i = y + 2; i < yh - 2; i++)
        if (Map::getAtPosition((x - 1) / mapSize, i/mapSize).isSolid()) {
            int tmp = static_cast<int>((x - 1) / mapSize + 1) * mapSize;
            if (tmp - mx < tmp - cxl)
                cxl = tmp;
        }

    // Calculate
    dy += gravity * deltaTime;

    if (yh + dy >= cyb) {
        onGround = true;
        dy = 0;
        y = cyb - h;
    } else {
        onGround = false;
    }

    if (y < cyt) {
        onTop = true;
        dy = 0;
        y = cyt;
    } else {
        onTop = false;
    }

    if (xw + dx > cxr) {
        onRight = true;
        x = cxr - w;
    } else {
        onRight = false;
    }

    if (x + dx < cxl) {
        onLeft = true;
        x = cxl;
    } else {
        onLeft = false;
    }

    if (!onGround && !onTop)
        y += dy;

    if (!onRight && !onLeft)
        x += dx;

    setPosition(x, y);
    animation.update();
}

void Player::draw(sf::RenderWindow *window) {
    window->draw(sprite);
    /* Collision line
    sf::RectangleShape s;
    s.setPosition(cxl-2,0);
    s.setSize({4,800});
    s.setFillColor(sf::Color::Red);
    window.draw(s);
    s.setPosition(cxr-2,0);
    s.setSize({4,800});
    s.setFillColor(sf::Color::Red);
    window.draw(s);
    s.setPosition(-2,cyb);
    s.setSize({800,4});
    s.setFillColor(sf::Color::Red);
    window.draw(s);
    s.setPosition(-2,cyt);
    s.setSize({800,4});
    s.setFillColor(sf::Color::Red);
    window.draw(s);*/
}
