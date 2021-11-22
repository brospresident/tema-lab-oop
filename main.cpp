#include <iostream>

#include "./Auth/Register.h"

int main () {
    std::cout << "Welcome to BemRom application!" << std::endl;

    while (true) {
        std::cout << "Please type your option(0 - exit the app | 1 - register | 2 - login " << std::endl;
        std::cout << "3 - Account information | 4 - Find flight by origin and destination | 5 - Book flight" << std::endl;
        std::cout << "6 - Top up your balance | 7 - See what flights you reserved since you joined us):" << std::endl;
        int option;
        std::cin >> option;

        if (option == 0) break;
        else if (option == 1) {
            std::cout << "Welcome to our register page:" << std::endl;
            std::cout << "Please type in the following information: " << std::endl;

            Register* registerInstance = new Register();

        } 
        else if (option == 2) {
            std::cout << "Welcome to our login page:" << std::endl;
            std::cout << "Please type in the following information: " << std::endl;
        } 
        else {
            std::cout << "Invalid option!" << std::endl;
        }
    }
    return 0;
}