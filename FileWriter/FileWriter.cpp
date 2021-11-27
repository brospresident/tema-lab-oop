#include "./FileWriter.h"

FileWriter::FileWriter(std::string fileName, std::string filePath, std::string fileExtension) {
    this->fileName = fileName;
    this->filePath = filePath;
    this->fileExtension = fileExtension;

    this->file = std::fstream(this->filePath + this->fileName + "." + this->fileExtension, std::ios::out | std::ios::trunc);
    if (!this->file.is_open()) {
        throw "File could not be opened";
    }
}
