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

        RSA rsa;

        std::string encodedPassword = rsa.encryptPassword(password);

        return this->registerUser(name, encodedPassword, email);
    }
    catch (char const* excp) {
        std::cout << excp << std::endl;
    }

    return nullptr;
}

User* Register::registerUser(std::string name, std::string encodedPassword, std::string email) {
    UserWriter* uw = new UserWriter(name, "./Data/Users/", "txt");
    std::vector<std::string> userData = {  name,
                                            encodedPassword,
                                            email,
                                            "0",
                                            "1",
                                            "0"
                                        };
    uw->write(userData); 
    std::cout << "User " << name << " registered successfully" << std::endl;
    delete uw;
    return new User (
        name,
        email
    );
}