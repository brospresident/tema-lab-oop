#include "./Auth.h"

AuthSingleton* AuthSingleton::instance = nullptr;

AuthSingleton* AuthSingleton::getInstance() {
    if (instance == nullptr) {
        instance = new AuthSingleton();
    }
    return instance;
}

bool AuthSingleton::existsUser(std::string name) {
    std::string path = "./Data/Users";
    for (const auto& file : std::filesystem::directory_iterator(path)) {
        std::string fileName = file.path().filename().string();
        std::transform(name.begin(), name.end(), name.begin(), ::tolower);
        if (fileName.compare(name + ".txt") == 0) {
            return true;
        }
    }

    return false;
}

bool AuthSingleton::validatePassword(std::string password) {
    if (password.length() < this->minPassLength) {
        // throw "Your password is too short. Minimum " + std::to_string(this->minPassLength) + " characters."; 
        return false;
    }

    bool foundDigit = false;
    for (int i = 0; i <= 9; ++i) {
        if (password.find(i) != std::string::npos) {
            foundDigit = true;
            break;
        }
    }
    if (!foundDigit) {
        return false;
    }

    if (!((password.find("@") != std::string::npos) ||
        (password.find("#") != std::string::npos) ||
        (password.find("!") != std::string::npos) ||
        (password.find("~") != std::string::npos) ||
        (password.find("$") != std::string::npos) ||
        (password.find("%") != std::string::npos) ||
        (password.find("^") != std::string::npos) ||
        (password.find("&") != std::string::npos) ||
        (password.find("*") != std::string::npos) ||
        (password.find("(") != std::string::npos) ||
        (password.find(")") != std::string::npos) ||
        (password.find("-") != std::string::npos) ||
        (password.find("+") != std::string::npos) ||
        (password.find("/") != std::string::npos) ||
        (password.find(":") != std::string::npos) ||
        (password.find(".") != std::string::npos) ||
        (password.find(",") != std::string::npos) ||
        (password.find("<") != std::string::npos) ||
        (password.find(">") != std::string::npos) ||
        (password.find("?") != std::string::npos) ||
        (password.find("|") != std::string::npos)))
    return false;

    int count = 0; 
  
    // Checking capital letters 
    for (int i = 65; i <= 90; i++) { 
            
        // Type casting 
        char c = (char)i;
        std::string str1(1, c);
            
        if (password.find(str1) != std::string::npos) {
            count = 1;
            break;
        }
            
    } 
    if (count == 0) return false;

    count = 0;
    for (int i = 90; i <= 122; i++) { 
        // Type casting 
        char c = (char)i; 
        std::string str1(1, c); 

        if (password.find(str1) != std::string::npos) {
            count = 1;
            break;
        }
            
    } 
    if (count == 0) return false; 
    return true;
}