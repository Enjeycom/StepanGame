// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <ctime>
#include <string>
#include <iostream>
#include "./Log.hpp"

std::ofstream Log::file;
bool Log::debug;

void Log::open() {
    file.open("./log.txt", std::ios::app);
    file << "-----------------------------------------------------------------------\n";
}

void Log::close() {
    file.close();
}

void Log::write(std::string note) {
    if (debug)
        std::cout << note << std::endl;
    if (!file.is_open())
        open();
    time_t now = time(0);
    std::string snow = ctime(&now);
    file << snow.substr(0, snow.size() - 1) << " | " << note << std::endl;
}
