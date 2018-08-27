// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef PHYSICS_HPP_
#define PHYSICS_HPP_

class Physics {
 public:
    static float g;
    static float timeSpeed;
    static bool loadFromFile();
};

#define gravity Physics::g

#endif  // PHYSICS_HPP_
