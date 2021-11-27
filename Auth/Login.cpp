#include "./Login.h"

User* Login::tryLoginUser(std::string name, std::string password) {
    try {
        if (!this->existsUser(name)) {
            throw "That user is not in our database!";
        }

        RSA rsa;
        std::string encryptedPass = rsa.encryptPassword(password);
        UserReader* ur = new UserReader(name, "./Data/Users/", "txt");
        std::vector<std::string> userData = ur->read();

        if (userData[1].compare(encryptedPass) != 0) {
            throw "Wrong password";
        }

        delete ur;

        return this->loginUser(userData);
    }
    catch (char const* excp) {
        std::cout << excp << std::endl;
    }

    return new User();
}

User* Login::loginUser(const std::vector<std::string> userData) {
    bool isOperator = false;

    int balance = stoi(userData[3]);
    if (userData[4] == "1") {
        isOperator = true;
    }
    return new User (
        userData[0],
        userData[1],
        userData[2],
        balance,
        isOperator,
        true
    );
}