#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Logger {
public:
    virtual void log(const std::string &message) = 0;
};

class ConsoleLogger : public Logger {
public:
    void log(const std::string &message) override {
        std::cout << message << std::endl;
    }
};

class FileLogger : public Logger {
public:
    FileLogger(std::string fileName)
        : out_(fileName) {
    }

    void log(const std::string &message) override {
        out_ << message << std::endl;
    }

private:
    std::ofstream out_;
};

class MultiLogger: public Logger {

public:
    void log(const std::string &message) override {
        for (auto& logger : loggers) {
            logger->log(message);
        }
    }

    void addLogger(std::unique_ptr<Logger> logger) {
        loggers.push_back(std::move(logger));
    }

private:
    std::vector<std::unique_ptr<Logger>> loggers;
};

#endif //LOGGER_HPP
