// DeviceMonitor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>

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

class PulseRate {
private:
    int pulseRate;
   
    

public:
    PulseRate(int initialPulseRate) {
        this->pulseRate = initialPulseRate;
    }


    int getPulseRate() {
        return pulseRate;
    }

    void setPulseRate(int pulseRate) {
        this->pulseRate = pulseRate;
    }
    
};

class Alarms {
private:
    int lowPulseAlarmLimit;
    int highPulseAlarmLimit;
    int criticalHeartRate = 30;
    int lowOxygenSatLimit;
    int highOxygenSatLimit;
public:
     Alarms(int lowPulseAlarmLimit, int highPulseAlarmLimit, int lowOxygenSatLimit, int highOxygenSatLimit) {
        

        this->lowPulseAlarmLimit = lowPulseAlarmLimit;
        this->highPulseAlarmLimit = highPulseAlarmLimit;
        this->highOxygenSatLimit = highOxygenSatLimit;
        this->lowOxygenSatLimit = lowOxygenSatLimit;
    }
     bool isCriticalHeartRate(int pulseRate) {
         if (pulseRate <= criticalHeartRate) {
             return true;
         }
         else {
             return false;
         }

     }
     int getLowPulseAlarmLimit() {
         return lowPulseAlarmLimit;
     }

     void setlowPulseAlarmLimit(int lowPulseAlarmLimit) {
         this->lowPulseAlarmLimit = lowPulseAlarmLimit;
     }

     int getHighPulseAlarmLimit() {
         return highPulseAlarmLimit;
     }

     void setHighPulseAlarmLimit(int highPulseAlarmLimit) {
         this->highPulseAlarmLimit = highPulseAlarmLimit;
     }


     int getLowOxygenSatLimit() {
         return lowOxygenSatLimit;
     }

     void setLowOxygenSatLimit(int lowOxygenSatLimit) {
         this->lowOxygenSatLimit = lowOxygenSatLimit;
     }

     int getHighOxygenSatLimit() {
         return highOxygenSatLimit;
     }

     void setHighOxygenSatLimit(int highOxygenSatLimit) {
         this->highOxygenSatLimit = highOxygenSatLimit;
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

    class OxygenSat {
    private:
        int oxygenSat;

    public:
        OxygenSat(int initialOxygenSat) {
            this->oxygenSat = initialOxygenSat;
        }

        int getOxygenSat() {
            return oxygenSat;
        }

        void setOxygenSat(int oxygenSat) {
            this->oxygenSat = oxygenSat;
        }
    };




    int main()
    {

        int lowPulseAlarmLimit;
        int highPulseAlarmLimit;
        int lowOxygenSatLimit;
        int highOxygenSatLimit;

        std::cin >> lowPulseAlarmLimit;
        std::cin >> highPulseAlarmLimit;
        std::cin >> lowOxygenSatLimit;
        std::cin >> highOxygenSatLimit;

        PulseRate pulseRate(140);
        OxygenSat oxygenSat = 101;
        Alarms alarms (lowPulseAlarmLimit, highPulseAlarmLimit, lowOxygenSatLimit, highOxygenSatLimit);

        Signal signal(true, true);
        Monitor monitor = true;
      

        while (monitor.isPowerOn()) {
            if (signal.isVitalsDetected()) {
                std::cout << "HR: " << pulseRate.getPulseRate() << "\n";
                std::cout << "SpO2: " << oxygenSat.getOxygenSat() << "\n";


                if (alarms.isHighPulseRate(pulseRate.getPulseRate())) {
                    std::cout << "ALARM HIGH HEART RATE " << pulseRate.getPulseRate() << "\n";
                }

                else if (alarms.isLowPulseRate(pulseRate.getPulseRate())) {

                    std::cout << "ALARM LOW HEART RATE " << pulseRate.getPulseRate() << "\n";
                }

                if (alarms.isLowOxygenSat(oxygenSat.getOxygenSat())){
                    std::cout << "AlARM LOW SPO2 " << oxygenSat.getOxygenSat() << "\n";
                }

                else if (alarms.isHighOxygenSat(oxygenSat.getOxygenSat())) {
                    std::cout << "ALARM HIGH SPO2 " << oxygenSat.getOxygenSat() << "\n";
                }
            }


            if (!signal.isVitalsDetected()) {

                std::cout << "Patient Disconnect " << "\n";
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));


        }


    
}
