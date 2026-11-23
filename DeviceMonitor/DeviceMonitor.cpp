// DeviceMonitor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <random>

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

class Alarms {
private:
    bool bypassAlarm= false;
    int lowPulseAlarmLimit =30;
    int highPulseAlarmLimit=200;
    int criticalHeartRate = 30;
    int lowOxygenSatLimit=50;
    int highOxygenSatLimit=100;
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
         if ((highOxygenSatLimit < lowOxygenSatLimit + 15 && !bypassAlarm || highOxygenSatLimit <= lowOxygenSatLimit) || highOxygenSatLimit > 100){
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




    int main()
    {

        int lowPulseAlarmLimit;
        int highPulseAlarmLimit;
        int lowOxygenSatLimit;
        int highOxygenSatLimit;


        Alarms alarms; 

        std::cin >> lowPulseAlarmLimit;
        alarms.setlowPulseAlarmLimit(lowPulseAlarmLimit);

        std::cin >> highPulseAlarmLimit;
        alarms.setHighPulseAlarmLimit(highPulseAlarmLimit);

        std::cin >> lowOxygenSatLimit;
        alarms.setLowOxygenSatLimit(lowOxygenSatLimit);

        std::cin >> highOxygenSatLimit;
        alarms.setHighOxygenSatLimit(highOxygenSatLimit);

        PulseRate pulseRate;
        OxygenSat oxygenSat;
        

        Signal signal(true, true);
        Monitor monitor = true;
      

        while (monitor.isPowerOn()) {
            if (signal.isVitalsDetected()) {
                pulseRate.generatePulseRate();
                oxygenSat.generateOxygenSat();
                std::cout << "HR: " << pulseRate.getPulseRate() << "\n";
                std::cout << "SpO2: " << oxygenSat.getOxygenSat() << "\n";
    

                if (alarms.isCriticalHeartRate(pulseRate.getPulseRate())) {
                    std::cout << "CRITICAL HEART RATE " << pulseRate.getPulseRate() << "\n";
                }

                else {
                    if (alarms.isHighPulseRate(pulseRate.getPulseRate())) {
                        std::cout << "ALARM HIGH HEART RATE " << pulseRate.getPulseRate() << "\n";
                    }
                    else if (alarms.isLowPulseRate(pulseRate.getPulseRate())) {

                        std::cout << "ALARM LOW HEART RATE " << pulseRate.getPulseRate() << "\n";
                    }
                }
                if (alarms.isCriticalOxygenSat(oxygenSat.getOxygenSat())) {
                    std::cout << "CRITICAL OXYGEN SATURATION " << oxygenSat.getOxygenSat() << "\n";

                }
                else {

                    if (alarms.isLowOxygenSat(oxygenSat.getOxygenSat())) {
                        std::cout << "AlARM LOW SPO2 " << oxygenSat.getOxygenSat() << "\n";
                    }

                    else if (alarms.isHighOxygenSat(oxygenSat.getOxygenSat())) {
                        std::cout << "ALARM HIGH SPO2 " << oxygenSat.getOxygenSat() << "\n";
                    }
                }

            }


                if (!signal.isVitalsDetected()) {

                    std::cout << "Patient Disconnect " << "\n";
                }
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }

   


    

