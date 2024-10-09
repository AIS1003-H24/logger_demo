
#ifndef CONSOLELOGGER_HPP
#define CONSOLELOGGER_HPP

#include "Logger.hpp"

#include <iostream>

class ConsoleLogger : public Logger {
public:
    void log(const std::string &message) override {
        std::cout << message << std::endl;
    }
};

#endif //CONSOLELOGGER_HPP
