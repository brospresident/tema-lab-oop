#ifndef USER
#define USER

#include <iostream>
#include <string>
#include <vector>
#include "../Flight/flight.h"

class User {
    private:
        int id;
        std::string name;
        std::string password;
        std::string email;
        int balance;
        std::vector<Flight> reservedFlights;

    public:
        User(int id, std::string name, std::string password, std::string email, int balance);
        User(int id, std::string name, std::string password, std::string email, int balance, std::vector<Flight> reservedFlights);
        int getId();
        std::string getName();
        std::string getPassword();
        std::string getEmail();
        int getBalance();
        std::vector<Flight> getReservedFlights();
        void setId(int id);
        void setName(std::string name);
        void setPassword(std::string password);
        void setEmail(std::string email);
        void setBalance(int balance);
        void setReservedFlights(std::vector<Flight> reservedFlights);
        void addReservedFlight(Flight flight);
        void removeReservedFlight(Flight flight);
        void print();
};

#endif