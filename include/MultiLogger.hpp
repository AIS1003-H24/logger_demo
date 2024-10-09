
#ifndef MULTILOGGER_HPP
#define MULTILOGGER_HPP

#include "Logger.hpp"

#include <vector>
#include <memory>

class MultiLogger : public Logger {
public:
    void log(const std::string &message) override {
        for (auto &logger: loggers) {
            logger->log(message);
        }
    }

    void addLogger(std::unique_ptr<Logger> logger) {
        loggers.push_back(std::move(logger));
    }

private:
    std::vector<std::unique_ptr<Logger> > loggers;
};

#endif //MULTILOGGER_HPP
