// DeviceMonitor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <fstream>
#include "Monitor.h"
#include "Signal.h"
#include "PulseRate.h"
#include "Alarms.h"
#include "OxygenSat.h"
#include "DataLogger.h"



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
        
        int recordCount = 0;

        while (recordCount <=30 && monitor.isPowerOn()) {
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

            recordCount += 1;
                if (recordCount == 30) {
                    monitor.setPowerOn(false);
                }


                if (!signal.isVitalsDetected()) {

                    std::cout << "Patient Disconnect " << "\n";
                }
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }

   


    

