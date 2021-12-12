#ifndef LOGIN
#define LOGIN

#include "./Auth.h"
#include "../Flight/flight.h"
#include "../User/User.h"
#include "../User/Operator.h"
#include "../RSA/RSA.h"
#include "../FileReader/UserReader.h"
#include <vector>

class Login : public AuthSingleton {
    public:

        /*
        * @brief: This function is used to load the data from file and check if the user gave the right credentials.
        * @param: username, password
        * @return: true if the user gave the right credentials, false otherwise.
        */
        std::unique_ptr<User> tryLoginUser(std::string name, std::string password);

        /*
        * @brief: This function is used to create the user object and return it
        * @param: userData
        * @return: user object
        */
        std::unique_ptr<User> loginUser(std::vector<std::string> const);
};

#endif