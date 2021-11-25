#ifndef USER_READER
#define USER_READER

#include <string>
#include <vector>
#include "./FileReader.h"

class UserReader : public FileReader {
    public:
        UserReader(std::string fileName, std::string filePath, std::string fileExtension);
        std::vector<std::string> read();
};

#endif