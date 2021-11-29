#ifndef FLIGHTREADER
#define FLIGHTREADER

#include "./FileReader.h"
#include <string>
#include <vector>

class FlightReader : public FileReader {
    public:
        FlightReader(std::string fileName, std::string filePath, std::string fileExtension);
        std::vector<std::string> read();
};

#endif