// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef LOG_H_
#define LOG_H_

#include <string>
#include <fstream>

class Log {
    private:
        static std::ofstream file;
    public:
        static void open();
        static void close();
        static void write(std::string note);
};

#endif  // LOG_H_
