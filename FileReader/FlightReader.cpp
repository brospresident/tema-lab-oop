#include "./FlightReader.h"

FlightReader::FlightReader(std::string fileName, std::string filePath, std::string fileExtension) : FileReader(fileName, filePath, fileExtension) {}

std::vector<std::string> FlightReader::read() {
    std::vector<std::string> flightData;

    std::string line;
    while (std::getline(this->file, line)) {
        flightData.push_back(line);
    }

    this->file.close();

    return flightData;
}