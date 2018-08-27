// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef PATHWAYS_HPP_
#define PATHWAYS_HPP_

#include <vector>
#include <string>
#include <utility>

#define getPath Pathways::get

class Pathways {
 private:
    static std::vector<std::pair<std::string, std::string>> pathways;
 public:
    static bool loadFromFile();
    static std::string get(const std::string key);
};

#endif  // PATHWAYS_HPP_
