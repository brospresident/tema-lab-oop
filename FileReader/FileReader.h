#ifndef FILEREADER
#define FILEREADER

#include <string>
#include <vector>
#include <fstream>

class FileReader {
    protected:
        std::string fileName;
        std::string filePath;
        std::string fileExtension;

    public:
        std::fstream file;
        FileReader(std::string fileName, std::string filePath, std::string fileExtension);
        virtual std::vector<std::string> read() = 0;

};

#endif