#pragma once
class Monitor {
private:
    bool powerOn;


public:
    Monitor(bool powerOn) {
        this->powerOn = powerOn;

    }

    bool isPowerOn() {
        return powerOn;
    }

    void setPowerOn(bool powerOn) {
        this->powerOn = powerOn;
    }


};