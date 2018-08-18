// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <ctime>
#include <string>
#include "./Log.hpp"

std::ofstream Log::file;

void Log::open() {
    file.open("./log.txt", std::ios::app);
}

void Log::close() {
    file.close();
}

void Log::write(std::string note) {
    time_t now = time(0);
    std::string snow = ctime(&now);
    file << snow.substr(0, snow.size() - 1) << " " << note << std::endl;
}
