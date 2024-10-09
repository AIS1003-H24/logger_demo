#include "Simulation.hpp"

#include "MultiLogger.hpp"
#include "ConsoleLogger.hpp"
#include "FileLogger.hpp"

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
