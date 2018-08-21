// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <iostream>
#include <dirent.h>
#include "./Loader.hpp"
#include "./Pathways.hpp"
#include "./Physics.hpp"
#include "./Tools.hpp"

bool Loader::loadVariables() {
    if (!Pathways::loadFromFile() || !Physics::loadFromFile())
        return false;
    return true;
}

bool Loader::loadFonts() {
    if (!mainFont.loadFromFile(getPath("fonts") + "font.otf"))
        return false;
    return true;
}
