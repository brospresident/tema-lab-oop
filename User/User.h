#ifndef USER
#define USER

#include <iostream>
#include <string>
#include <vector>
#include "../Flight/flight.h"
#include "../FileWriter/UserWriter.h"
#include <memory>

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
        User(std::string name, std::string password, std::string email);
        User(std::string name, std::string password, std::string email, int balance);
        User(std::string name, std::string password, std::string email, int balance, bool isOperator, bool isLoggedIn);
        std::string getName();
        std::string getPassword();
        std::string getEmail();
        int getBalance();
        void setName(std::string name);
        void setPassword(std::string password);
        void setEmail(std::string email);
        void setBalance(int balance);
        void print();
        bool getIsOperator();
        void setOperator(bool isOperator);
        bool getIsLoggedIn();
        void setLoggedIn(bool isLoggedIn);

        /*
            This function will print user information.
        */
        void showAccountInformation();
        void saveUserData();
        void topUpBalance(int amount);

};

#endif