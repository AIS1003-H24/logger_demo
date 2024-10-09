#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Logger.hpp"

#include <memory>

class Simulation {
public:
    void init() {
        if (logger_) {
            logger_->log("Simulation initialized!");
        }
    }

    void step(double dt) {
        t_ += dt;
        if (logger_) {
            logger_->log("t=" + std::to_string(t_));
        }
    }

    void terminate() {
        if (logger_) {
            logger_->log("Simulation terminated!");
        }
    }

    void setLogger(std::unique_ptr<Logger> logger) {
        logger_ = std::move(logger);
    }

private:
    float t_ = 0;
    std::unique_ptr<Logger> logger_;
};

#endif //SIMULATION_HPP
