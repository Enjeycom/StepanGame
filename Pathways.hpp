// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef PATHAAYS_H_
#define PATHWAYS_H_

#include <vector>
#include <string>

#define getPath Pathways::get

class Pathways {
    private:
        static std::vector<std::pair<std::string,std::string>> pathways;
    public:
        static bool loadFromFile();
        static std::string get(std::string key);
};

#endif  // PATHWAYS_H_