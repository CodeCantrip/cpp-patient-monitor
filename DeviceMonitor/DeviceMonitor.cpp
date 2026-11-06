// DeviceMonitor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int getHeartRate() {
    int heartRate = 60;
    return heartRate;
}

bool isHighHeartRate(int heartRate) {
    if (heartRate > 120) {
        return true;
    }

    else {
        return false;
    }
}
bool isLowHeartRate(int heartRate) {
    if (heartRate < 60) {
        return true;
    }
    else {
         return false;
    }
}
int main()
{
    int heartRate = getHeartRate();
    int oxygenSat = 98;

    std::cout << "SpO2: " << oxygenSat << "\n";
    std::cout << "HR: " << heartRate << "\n";
   
    if (isHighHeartRate(heartRate)) {
        std::cout << "ALARM HIGH HEART RATE " << heartRate << "\n";
    }

    else if (isLowHeartRate(heartRate)) {
        std::cout << "ALARM LOW HEART RATE " << heartRate << "\n";
    }
}

    
  


