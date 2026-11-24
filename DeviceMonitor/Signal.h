#pragma once
class Signal {
private:
    bool vitalsDetected;
    bool signalQuality;

public:
    Signal(bool vitalsDetected, bool signalQuality) {
        this->vitalsDetected = vitalsDetected;
        this->signalQuality = signalQuality;
    }

    bool isVitalsDetected() {
        return vitalsDetected;
    }

    bool isSignalQuality() {
        return signalQuality;
    }

    void setVitalsDetected(bool vitalsDetected) {
        this->vitalsDetected = vitalsDetected;
    }

    void setSignalQuality(bool signalQuality) {
        this->signalQuality = signalQuality;
    }
};
