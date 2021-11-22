#ifndef AUTH
#define AUTH

#include <iostream>
#include <string>
#include <filesystem>
#include <algorithm>

class AuthSingleton {
    protected:
        static AuthSingleton* instance;
    
    public:
        const int minPassLength = 3;
        static AuthSingleton* getInstance();
        bool existsUser(std::string name);

        /*
            @param password the password provided for checking
            @returns true if the password meets the criteria, false otherwise
            The criteria is:
                - at least 8 characters
                - at least one uppercase letter
                - at least one lowercase letter
                - at least one number
                - at least one special character
        */
        bool validatePassword(std::string password);
        std::string encodePassword(const std::string);
        std::string decodePassword(const std::string);
};


#endif