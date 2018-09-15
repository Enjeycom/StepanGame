// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <dirent.h>
#include <iostream>
#include "./Loader.hpp"
#include "./Pathways.hpp"
#include "./Physics.hpp"
#include "./Tools.hpp"
#include "./Log.hpp"

bool Loader::loadVariables() {
    log("Loading variables:");
    if (!Pathways::loadFromFile() || !Physics::loadFromFile())
        return false;
    return true;
}

bool Loader::loadFonts() {
    log("Loading fonts...");
    if (!mainFont.loadFromFile(getPath("fonts") + "font.otf"))
        return false;
    return true;
}
