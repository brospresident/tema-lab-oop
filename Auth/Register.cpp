#include "./Register.h"

User* Register::tryRegisterUser(std::string name, std::string password, std::string confirmPassword, std::string email) {
    try {
        if (!this->validatePassword(password)) {
            throw "Password must be at least 8 characters long and contain at least one number, one special character and one capital letter.";
        }

        if (password != confirmPassword) {
            throw "Password and confirm password do not match";
        }

        if (this->existsUser(name)) {
            throw "User already exists";
        }
    }
    catch (char const* excp) {
        std::cout << excp << std::endl;
    }

    return this->registerUser(name, password, email);
}

User* Register::registerUser(std::string name, std::string encodedPassword, std::string email) {
    FileWriter* fw = new FileWriter(name, "./Data/Users/", "txt");
    fw->file << name << std::endl << encodedPassword << std::endl << email << std::endl << 0 << std::endl << true << std::endl << false << std::endl;
    std::cout << "User " << name << " registered successfully" << std::endl;
    delete fw;
    return new User(
        name,
        email
    );
}