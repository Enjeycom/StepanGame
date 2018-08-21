// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <fstream>
#include <string>
#include <vector>
#include "./Log.hpp"
#include "./Tools.hpp"
#include "./Physics.hpp"

float Physics::g;
float Physics::timeSpeed;

bool Physics::loadFromFile() {
    std::ifstream file("./variables/physics.variables");
    if (!file.is_open()) {
        log("Error physics load: file \"./variables/physics.variables\" not found!");
        return false;
    }
    std::string command;
    while (!file.eof()) {
        getline(file, command);
        if (command.empty())
            continue;
        size_t indx = command.find("=");
        if (indx == std::string::npos) {
            log("Error physics load: incorrect note!");
            return false;
        }
        std::string name = command.substr(0, indx);
        std::string value = command.substr(indx + 1, command.length() - 1);
        trim(name);
        trim(value);
        if(name.empty() || value.empty()){
            log("Error physics load: incorrect note!");
            return false;
        } else {
            if (name == "gravity")
                g = std::stof(value);
            if (name == "timeSpeed")
                timeSpeed = std::stof(value);
        } 
    }
    return true;
}
