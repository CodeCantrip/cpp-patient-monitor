#pragma once
#include <fstream>

class DataLogger {
	private:
		std::ofstream outputFile;

public:
bool openFile(std::string fileName) {
	outputFile.open(fileName);

	if (outputFile.is_open()) {
		return true;
	}
	else {
		return false;
	}

}

void writeMonitorInfo(int pulseRate, int oxygenSat) {
	if (outputFile.is_open()) {
		outputFile << pulseRate << "," << oxygenSat << "\n";
	}
}

void closeOutPutFile() {
	if (outputFile.is_open()) {
		outputFile.close();
	}
}
};