// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include "./Pathways.hpp"
#include <string>

std::string Pathways::get(std::string key) {
    for (int i = 0; i < pathways.size(); i++){
        if (pathways[i].first == key)
            return pathways[i].second;
    }
    return "";
}

bool Pathways::loadFromFile(){
    
}