#pragma once
#include <random>

class OxygenSat {
private:
    int oxygenSat;


public:

    OxygenSat() {
        generateOxygenSat();
    }

    void generateOxygenSat() {

        static std::random_device rd;
        static std::mt19937 generator(rd());

        std::uniform_int_distribution<int> distribution(0, 100);

        oxygenSat = distribution(generator);
    }


    int getOxygenSat() {
        return oxygenSat;
    }
};

