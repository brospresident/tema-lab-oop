#ifndef FLIGHTMANAGER
#define FLIGHTMANAGER

#include "./flight.h"
#include <vector>
#include "../FileReader/FlightReader.h"
#include "../FileWriter/FlightWriter.h"
#include <filesystem>
#include <regex>

class FlightManager {
    public:
        std::vector<Flight> flights;
        FlightManager();
        bool existsFlight(int id);
        void printAllAvailableFlights();
        bool isFlightAvailable(int id);
        void findFlightByOriginAndDestination(std::string origin, std::string destination);
        void saveFlights();
        void addFlight(std::string origin, std::string destination, std::string date, int time, int seatsAvailable, int price);
        std::vector<Flight> getFlights();
        Flight findFlightById(int id);
        bool checkDate(std::string date);
        bool checkCityName(std::string cityName);
        void removeFlight(int id);
        void printAllExistingFlights();

        friend int getFlightPrice(FlightManager& flightManager, int id);
};

int getFlightPrice(FlightManager& flightManager, int id);

#endif