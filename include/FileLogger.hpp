
#ifndef FILELOGGER_HPP
#define FILELOGGER_HPP

#include "Logger.hpp"

#include <fstream>

class FileLogger : public Logger {
public:
    explicit FileLogger(const std::string &fileName)
        : out_(fileName) {
    }

    void log(const std::string &message) override {
        out_ << message << std::endl;
    }

private:
    std::ofstream out_;
};


#endif //FILELOGGER_HPP
