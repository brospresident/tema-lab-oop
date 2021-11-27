#ifndef REGISTER
#define REGISTER

#include "./Auth.h"
#include "../Flight/flight.h"
#include "../User/User.h"
#include "../RSA/RSA.h"
#include "../FileWriter/UserWriter.h"
#include <memory>

class Register : public AuthSingleton {
    public:
        std::unique_ptr<User> tryRegisterUser(std::string name, std::string password, std::string confirmPassword, std::string email);
        std::unique_ptr<User> registerUser(std::string name, std::string encodedPassword, std::string email);
};

#endif