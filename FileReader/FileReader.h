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

        /*
            @brief: (It is implemented in the other classes)Reads the file and returns the content as a vector of strings
        */
        virtual std::vector<std::string> read() = 0;

};

#endif