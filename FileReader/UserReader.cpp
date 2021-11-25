#include "UserReader.h"

UserReader::UserReader(std::string fileName, std::string filePath, std::string fileExtension) : FileReader(fileName, filePath, fileExtension) {

}

std::vector<std::string> UserReader::read() {
    std::vector<std::string> userData;

    std::string line;
    while (std::getline(this->file, line)) {
        userData.push_back(line);
    }

    this->file.close();

    return userData;   
}