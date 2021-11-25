#ifndef USERWRITER
#define USERWRITER

#include "FileWriter.h"
#include <iostream>

class UserWriter : public FileWriter {
    public:
        UserWriter(std::string fileName, std::string filePath, std::string fileExtension);
        void write(std::vector<std::string>);
};

#endif