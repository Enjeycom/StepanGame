// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef LOG_HPP_
#define LOG_HPP_

#include <string>
#include <fstream>

#define log Log::write

class Log {
 private:
    static std::ofstream file;
 public:
    static bool debug;
    static void open();
    static void close();
    static void write(std::string note);
    static void write(double note);
};

#endif  // LOG_HPP_
