// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include "./Camera.hpp"
#include "./Tools.hpp"
#include "./Map.hpp"

Camera::Camera() {
    cx = 0;
    cy = 0;
    z = 1;
    dz = 2;
}

void Camera::setTarget(Object *object) {
    target = object;
}

 void Camera::setZoom(float z, bool slow) {
     if (slow)
        this->z = z;
     else
        this->dz = z;
 }

void Camera::update(sf::RenderWindow *window) {
    w = renderSize.x;
    h =  renderSize.y;
    dz += (z - dz) / 20;
    cx += (target->getPosition().x + (target->getVector().x > 0 ? 200:(target->getVector().x<0?-200:0)) - cx) / 20;
    cy += (target->getPosition().y - cy) / 20;
    x = cx - w / 2;
    y = cy - h / 2;
    view.zoom(dz);
    view.setSize(w, h);
    view.setCenter(cx, cy);
    window->setView(view);
}

bool Camera::checkIn(Object *object) {
    if (object->getPosition().x + mapSize > x &&
        object->getPosition().x < x + w &&
        object->getPosition().y + mapSize > y &&
        object->getPosition().y < y + h)
        return true;
    return false;
}

void Camera::setRenderSize(sf::Vector2i renderSize){
    this->renderSize = renderSize;
}
