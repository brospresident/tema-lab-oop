#include "UserWriter.h"

UserWriter::UserWriter(std::string fileName, std::string filePath, std::string fileExtension) : FileWriter(fileName, filePath, fileExtension) {
    //this->file.open(this->filePath + this->fileName + this->fileExtension, std::fstream::out);
}

void UserWriter::write(std::vector<std::string> data) {
    if (!this->file.is_open()) {
        throw "File could not be opened";
    }
    for (std::string line : data) {
        this->file << line << std::endl;
    }
    this->file.close();
}