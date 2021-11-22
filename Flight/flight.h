#ifndef FLIGHT
#define FLIGHT

#include <iostream>
#include <string>

class Flight {
    private:
        int id;
        std::string origin;
        std::string destination;
        std::string date;
        std::string time;
        int seatsAvailable;

    public:
        Flight();
        Flight(int id, std::string origin, std::string destination, std::string date, std::string time, int seatsAvailable);
        int getId();
        std::string getOrigin();
        std::string getDestination();
        std::string getDate();
        std::string getTime();
        int getSeatsAvailable();
        void setId(int id);
        void setOrigin(std::string origin);
        void setDestination(std::string destination);
        void setDate(std::string date);
        void setTime(std::string time);
        void setSeatsAvailable(int seatsAvailable);

        bool operator == (Flight flight);
};

#endif
