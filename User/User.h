#ifndef USER
#define USER

#include <iostream>
#include <string>
#include <vector>
#include "../Flight/flight.h"

class User {
    private:
        std::string name;
        std::string password;
        std::string email;
        int balance;
        bool isOperator;
        bool isLoggedIn;

    public:
        User();
        /*
            The constructor I will call when a new user is created.
            It will set the name, password, email, balance, isOperator, and isLoggedIn to the given values.
            @param name: The name of the user.
            @param email: The email of the user.
        */
        User(std::string name, std::string email);
        User(std::string name, std::string password, std::string email, int balance);
        User(std::string name, std::string password, std::string email, int balance, std::vector<Flight> reservedFlights);
        std::string getName();
        std::string getPassword();
        std::string getEmail();
        int getBalance();
        //std::vector<Flight> getReservedFlights();
        void setName(std::string name);
        void setPassword(std::string password);
        void setEmail(std::string email);
        void setBalance(int balance);
        //void setReservedFlights(std::vector<Flight> reservedFlights);
        //void addReservedFlight(Flight flight);
        //void removeReservedFlight(Flight flight);
        void print();
        bool getIsOperator();
        void setOperator(bool isOperator);
        bool getIsLoggedIn();
        void setLoggedIn(bool isLoggedIn);

};

#endif