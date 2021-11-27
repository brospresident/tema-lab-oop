#include "./FileReader.h"

FileReader::FileReader(std::string fileName, std::string filePath, std::string fileExtension) {
    this->fileName = fileName;
    this->filePath = filePath;
    this->fileExtension = fileExtension;

    this->file = std::fstream(this->filePath + this->fileName + "." + this->fileExtension, std::ios::in);
}