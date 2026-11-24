#pragma once
class Alarms {
private:
    bool bypassAlarm = false;
    int lowPulseAlarmLimit = 30;
    int highPulseAlarmLimit = 200;
    int criticalHeartRate = 30;
    int lowOxygenSatLimit = 50;
    int highOxygenSatLimit = 100;
    int criticalOxygenSat = 79;
public:
    Alarms() {

    }

    bool isBypassAlarms() {
        return bypassAlarm;
    }

    void setBypassAlarm(bool bypassAlarm) {
        this->bypassAlarm = bypassAlarm;
    }


    bool isCriticalHeartRate(int pulseRate) {
        if (pulseRate <= criticalHeartRate) {
            return true;
        }
        else {
            return false;
        }

    }

    bool isCriticalOxygenSat(int oxygenSat) {
        if (oxygenSat <= criticalOxygenSat) {
            return true;
        }
        else {
            return false;
        }
    }

    int getLowPulseAlarmLimit() {
        return lowPulseAlarmLimit;
    }



    bool setlowPulseAlarmLimit(int lowPulseAlarmLimit) {
        if ((lowPulseAlarmLimit > highPulseAlarmLimit - 10 && !bypassAlarm || lowPulseAlarmLimit >= highPulseAlarmLimit) || lowPulseAlarmLimit < 30) {
            return false;
        }

        else {
            this->lowPulseAlarmLimit = lowPulseAlarmLimit;
            return true;

        }

    }

    int getHighPulseAlarmLimit() {
        return highPulseAlarmLimit;
    }

    bool setHighPulseAlarmLimit(int highPulseAlarmLimit) {
        if ((highPulseAlarmLimit < lowPulseAlarmLimit + 10 && !bypassAlarm || highPulseAlarmLimit <= lowPulseAlarmLimit) || highPulseAlarmLimit > 200) {
            return false;
        }
        else {
            this->highPulseAlarmLimit = highPulseAlarmLimit;
            return true;
        }
    }


    int getLowOxygenSatLimit() {
        return lowOxygenSatLimit;
    }

    bool setLowOxygenSatLimit(int lowOxygenSatLimit) {
        if ((lowOxygenSatLimit > highOxygenSatLimit - 15 && !bypassAlarm || lowOxygenSatLimit >= highOxygenSatLimit) || lowOxygenSatLimit < 50) {
            return false;
        }
        else {
            this->lowOxygenSatLimit = lowOxygenSatLimit;
            return true;
        }
    }

    int getHighOxygenSatLimit() {
        return highOxygenSatLimit;
    }

    bool setHighOxygenSatLimit(int highOxygenSatLimit) {
        if ((highOxygenSatLimit < lowOxygenSatLimit + 15 && !bypassAlarm || highOxygenSatLimit <= lowOxygenSatLimit) || highOxygenSatLimit > 100) {
            return false;
        }
        else {
            this->highOxygenSatLimit = highOxygenSatLimit;
            return true;
        }
    }

    bool isHighPulseRate(int pulseRate) {
        if (pulseRate >= highPulseAlarmLimit) {
            return true;
        }

        else {
            return false;
        }
    }

    bool isLowPulseRate(int pulseRate) {
        if (pulseRate <= lowPulseAlarmLimit) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isLowOxygenSat(int oxygenSat) {
        if (oxygenSat <= lowOxygenSatLimit) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isHighOxygenSat(int oxygenSat) {
        if (oxygenSat >= highOxygenSatLimit) {
            return true;
        }
        else {
            return false;
        }
    }


};