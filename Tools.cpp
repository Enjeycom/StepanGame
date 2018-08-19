// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <string>
#include "./Tools.hpp"

void trim(std::string &str, char sym) {
    std::string res;
    for (int i = 0; i <str.length(); i++) {
        if (str[i] != sym)
            res += str[i];
    }
    str = res;
}