// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "./Object.hpp"

class Camera {
 private:
    Object *target;
    sf::View view;
    sf::Vector2i renderSize;
    float x, y;
    float cx, cy;
    float w, h;
    float z, dz;
 public:
    Camera();
    void setRenderSize(sf::Vector2i renderSize);
    void setTarget(Object *object);
    void setZoom(float z, bool slow);
    void update(sf::RenderWindow *window);
    bool checkIn(Object *object);
};

#endif  // CAMERA_HPP_
