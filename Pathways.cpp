// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <fstream>
#include <string>
#include <vector>
#include "./Pathways.hpp"
#include "./Log.hpp"
#include "./Tools.hpp"

std::vector<std::pair<std::string, std::string>> Pathways::pathways;

std::string Pathways::get(std::string key) {
    for (size_t i = 0; i < pathways.size(); i++) {
        if (pathways[i].first == key)
            return pathways[i].second;
    }
    return "";
}

bool Pathways::loadFromFile() {
    std::string filename = "./variables/pathways.variables";
    std::ifstream file(filename);
    if (!file.is_open()) {
        log("Error pathways load: file \"" + filename + "\" not found!");
        return false;
    }
    std::string command;
    while (!file.eof()) {
        getline(file, command);
        if (command.empty())
            continue;
        size_t indx = command.find("=");
        if (indx == std::string::npos) {
            log("Error pathways load: incorrect note!");
            return false;
        }
        std::string name = command.substr(0, indx);
        std::string value = command.substr(indx + 1, command.length() - 1);
        trim(name);
        trim(value);
        if (name.empty() || value.empty()) {
            log("Error pathways load: incorrect note!");
            return false;
        } else {
            pathways.push_back({name, value});
        }
    }
    return true;
}
