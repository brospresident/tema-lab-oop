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
        /*
        * @brief: This function is used to check if the data matches the format
        * @param: username, password, confirmPassword, email
        * @return: User object
        */
        std::unique_ptr<User> tryRegisterUser(std::string name, std::string password, std::string confirmPassword, std::string email);

        /*
        * @brief: This function is used to create the new User object and return it
        * @param: username, password, encodePassword, email
        * @return: User object
        */
        std::unique_ptr<User> registerUser(std::string name, std::string encodedPassword, std::string email);
};

#endif