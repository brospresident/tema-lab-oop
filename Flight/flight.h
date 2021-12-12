#ifndef FLIGHT
#define FLIGHT

#include <iostream>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

class Flight {
    private:
        int id;
        std::string origin;
        std::string destination;
        date flightDate;
        int time;
        int seatsAvailable;
        int price;
        std::string originCountry;
        std::string destinationCountry;

    public:
        Flight();
        Flight(int id, std::string origin, std::string destination, std::string date, int time, int seatsAvailable, int price, std::string originCountry, std::string destinationCountry);
        int getId();
        std::string getOrigin();
        std::string getDestination();
        std::string getOriginCountry();
        std::string getDestinationCountry();
        date getDate();
        int getTime();
        int getSeatsAvailable();
        void setId(int id);
        void setOrigin(std::string origin);
        void setDestination(std::string destination);
        void setDate(std::string date);
        void setTime(int time);
        void setSeatsAvailable(int seatsAvailable);
        bool isAvailable();
        void toString();
        void setPrice(int price);
        int getPrice();

        //bool operator == (Flight flight);
};

#endif
