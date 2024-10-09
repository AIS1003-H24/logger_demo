#include <iostream>

#include "Logger.hpp"


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


int main() {
    Simulation sim;

    //sim.setLogger(std::make_unique<ConsoleLogger>());
    //sim.setLogger(std::make_unique<FileLogger>("log.txt"));

    auto logger = std::make_unique<MultiLogger>();
    logger->addLogger(std::make_unique<ConsoleLogger>());
    logger->addLogger(std::make_unique<FileLogger>("log.txt"));

    sim.setLogger(std::move(logger));

    sim.init();

    float deltaTime = 0.1;
    for (int i = 0; i < 10; i++) {
        sim.step(deltaTime);
    }
    sim.terminate();

    return 0;
}
