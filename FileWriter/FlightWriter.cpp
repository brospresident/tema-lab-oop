#include "./FlightWriter.h"

FlightWriter::FlightWriter(std::string fileName, std::string filePath, std::string fileExtension) : FileWriter(fileName, filePath, fileExtension) {}

void FlightWriter::write(std::vector<std::string> data) {
    try {
        if (!this->file.is_open()) { 
            throw "File is not opened!";
        }

        for (auto line : data) {
            this->file << line << std::endl;
        }
    }
    catch (char* const msg) {
        std::cout << msg << std::endl;
    }
}