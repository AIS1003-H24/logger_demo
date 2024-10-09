#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

class Logger {
public:
    virtual void log(const std::string &message) = 0;

    virtual ~Logger() = default;
};


#endif //LOGGER_HPP
