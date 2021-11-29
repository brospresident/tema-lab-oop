#ifndef FLIGHTWRITER
#define FLIGHTWRITER

#include <vector>
#include <string>
#include <iostream>
#include "./FileWriter.h"

class FlightWriter : public FileWriter {
    public:
        FlightWriter(std::string fileName, std::string filePath, std::string fileExtension);
        void write(std::vector<std::string> data);
};

#endif