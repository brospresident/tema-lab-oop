#ifndef REGISTER
#define REGISTER

#include "./Auth.h"
#include "../Flight/flight.h"

class Register : public AuthSingleton {
    public:
        bool tryRegisterUser(std::string name, std::string password, std::string email, int balance, std::vector<Flight> reservedFlights);
};

#endif