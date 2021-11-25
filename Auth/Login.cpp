#include "./Login.h"

User* Login::tryLoginUser(std::string name, std::string password) {
    try {
        if (!this->existsUser(name)) {
            throw "User with name " + name + " does not exist";
        }

        RSA rsa;
        std::string encryptedPass = rsa.encryptPassword(password);
        UserReader ur(name, "./Data/Users/", "txt");
        std::vector<std::string> userData = ur.read();

        if (userData[1] != encryptedPass) {
            throw "Wrong password";
        }
    }
    catch (const char* excp) {
        std::cout << excp << std::endl;
    }
}