#ifndef FILEWRITER
#define FILEWRITER

#include <string>
#include <vector>
#include <fstream>

class FileWriter {
    protected:
        std::string fileName;
        std::string filePath;
        std::string fileExtension;
    public:
        std::fstream file;
        FileWriter(std::string fileName, std::string filePath, std::string fileExtension);
        virtual void write(std::vector<std::string>) = 0;
};


#endif