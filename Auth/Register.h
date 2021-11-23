#ifndef REGISTER
#define REGISTER

#include "./Auth.h"
#include "../Flight/flight.h"
#include "../FileWriter/FileWriter.h"
#include "../User/User.h"

class Register : public AuthSingleton {
    public:
        User* tryRegisterUser(std::string name, std::string password, std::string confirmPassword, std::string email);
        User* registerUser(std::string name, std::string encodedPassword, std::string email);
};

#endif