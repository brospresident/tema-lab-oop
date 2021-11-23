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
        return false;
    }

    int count = 0; 
    // Check digits from 0 to 9 
    for(int i = 0; i <= 9; i++) { 
        // To convert int to string 
        std::string str1 = std::to_string(i); 

        if (password.find(str1) != std::string::npos) {
            count = 1; 
            break;
        }
            
    } 
    if (count == 0) 
        return false; 

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

    count = 0; 
  
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