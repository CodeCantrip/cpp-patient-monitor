#pragma once
#include <random>

class PulseRate {
private:
    int pulseRate;



public:
    PulseRate() {
        generatePulseRate();
    }

    void generatePulseRate() {

        static std::random_device rd;
        static std::mt19937 generator(rd());

        std::uniform_int_distribution<int> distribution(0, 200);

        pulseRate = distribution(generator);
    }

    int getPulseRate() {
        return pulseRate;
    }

};