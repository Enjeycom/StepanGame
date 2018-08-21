// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <iostream>
#include <dirent.h>
#include "./Loader.hpp"
#include "./Pathways.hpp"
#include "./Physics.hpp"

bool Loader::loadVariables() {
    if (!Pathways::loadFromFile() || !Physics::loadFromFile())
        return false;
    return true;
}
