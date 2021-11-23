#ifndef FILEWRITER
#define FILEWRITER

#include <string>
#include <vector>
#include <fstream>

class FileWriter {
    private:
        std::string fileName;
        std::string filePath;
        std::string fileExtension;
    public:
        std::fstream file;
        FileWriter(std::string fileName, std::string filePath, std::string fileExtension);
};


#endif