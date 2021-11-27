#ifndef LOGIN
#define LOGIN

#include "./Auth.h"
#include "../Flight/flight.h"
#include "../User/User.h"
#include "../RSA/RSA.h"
#include "../FileReader/UserReader.h"
#include <vector>

class Login : public AuthSingleton {
    public:
        User* tryLoginUser(std::string name, std::string password);
        User* loginUser(std::vector<std::string> const);
};

#endif