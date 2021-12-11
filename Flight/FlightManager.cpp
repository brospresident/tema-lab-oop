#include "./FlightManager.h"

FlightManager::FlightManager() {
    std::string path = "./Data/Flights";

    for (const auto& file : std::filesystem::directory_iterator(path)) {
        std::string fileName(file.path().filename().string());
        fileName = fileName.substr(0, fileName.find("."));

        FlightReader fr(fileName, "./Data/Flights/", "txt");
        std::vector<std::string> flightData = fr.read();

        Flight newFlight (
            std::stoi(flightData[0]),
            flightData[1],
            flightData[2],
            flightData[3],
            std::stoi(flightData[4]),
            std::stoi(flightData[5]),
            std::stoi(flightData[6])
        );

        this->flights.push_back(newFlight);
    }

    std::cout << "Loaded " << this->flights.size() << " flights." << std::endl;
}

void FlightManager::printAllAvailableFlights() {
    try {
        bool found = false;
        for (int i = 0; i < this->flights.size(); i++) {
            if (this->flights[i].isAvailable()) {
                this->flights[i].toString();
                found = true;
            }
        }

        if (!found) {
            throw "There are no available flights right now!";
        }
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

bool FlightManager::existsFlight(int id) {
    for (int i = 0; i < this->flights.size(); i++) {
        if (this->flights[i].getId() == id) {
            return true;
        }
    }

    return false;
}

bool FlightManager::isFlightAvailable(int id) {
    for (int i = 0; i < this->flights.size(); i++) {
        if (this->flights[i].getId() == id) {
            return this->flights[i].isAvailable();
        }
    }

    return false;
}

void FlightManager::findFlightByOriginAndDestination(std::string origin, std::string destination) {
    try {
        bool found = false;

        for (Flight flight : this->flights) {
            if (flight.getOrigin() == origin && flight.getDestination() == destination && flight.isAvailable()) {
                flight.toString();
                found = true;
            }
        }

        if (!found) {
            throw "There is no available flight for your destination";
        }
    }
    catch (char* const excp) {
        std::cout << excp << std::endl;
    }
}

void FlightManager::saveFlights() {
    std::string path = "./Data/Flights";
    for (const auto& file : std::filesystem::directory_iterator(path)) {
        remove(file.path());
    }

    for (int i = 0; i < this->flights.size(); i++) {
        std::vector<std::string> flightData;
        flightData.push_back(std::to_string(this->flights[i].getId()));
        flightData.push_back(this->flights[i].getOrigin());
        flightData.push_back(this->flights[i].getDestination());
        flightData.push_back(to_simple_string(this->flights[i].getDate()));
        flightData.push_back(std::to_string(this->flights[i].getTime()));
        flightData.push_back(std::to_string(this->flights[i].getSeatsAvailable()));
        flightData.push_back(std::to_string(this->flights[i].getPrice()));
        FlightWriter fw(std::to_string(this->flights[i].getId()), "./Data/Flights/", "txt");
        fw.write(flightData);
    }
}

std::vector<Flight> FlightManager::getFlights() {
    return this->flights;
}

void FlightManager::addFlight(std::string origin, std::string destination, std::string date, int time, int seatsAvailable, int price) {
    try {
        if (this->checkCityName(origin) || this->checkCityName(destination)) {
            throw "Invalid city name";
        }

        if (this->checkDate(date)) {
            throw "Date does not match the format (YYYY-MM-DD) or it is in the past.";
        }

        Flight newFlight (
            this->flights.size() + 1,
            origin,
            destination,
            date,
            time,
            seatsAvailable,
            price
        );

        this->flights.push_back(newFlight);
        this->saveFlights();
        std::cout << "Added a new flight!" << std::endl;
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

Flight FlightManager::findFlightById(int id) {
    for (int i = 0; i < this->flights.size(); i++) {
        if (this->flights[i].getId() == id) {
            return this->flights[i];
        }
    }

    return Flight();
}

/*
    This function checks if the city name contains only letters.
    @param cityName: The name of the city.
    @returns true if the city name is valid, false otherwise.
*/
bool FlightManager::checkCityName(std::string cityName) {
    if (!((cityName.find("0") != std::string::npos) ||
            cityName.find("1") != std::string::npos ||
            cityName.find("2") != std::string::npos ||
            cityName.find("3") != std::string::npos ||
            cityName.find("4") != std::string::npos ||
            cityName.find("5") != std::string::npos ||
            cityName.find("6") != std::string::npos ||
            cityName.find("7") != std::string::npos ||
            cityName.find("8") != std::string::npos ||
            cityName.find("9") != std::string::npos)) {
        return false;
    }

    return true;
}

/*
    This function checks if the date is in the future and if it has the correct format.
    @param date: The date to be checked.
    @returns true if the date is valid, false otherwise.
*/
bool FlightManager::checkDate(std::string dateStr) {
    const std::regex pattern("^\\d{4}\\-(0[1-9]|1[012])\\-(0[1-9]|[12][0-9]|3[01])$");

    date d;

    if (d < date(from_simple_string(dateStr))) {
        return false;
    }

    return regex_match(dateStr, pattern);
}

void FlightManager::removeFlight(int id) {
    try {
        if (!this->existsFlight(id)) {
            throw "There is no flight with that id";
        }

        for (int i = 0; i < this->flights.size(); i++) {
            if (this->flights[i].getId() == id) {
                this->flights.erase(this->flights.begin() + i);
                this->saveFlights();
                std::cout << "Removed flight with id " << id << std::endl;
                return;
            }
        }
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void FlightManager::printAllExistingFlights() {
    try {
        if (this->flights.size() == 0) {
            throw "There are no flights";
        }

        for (int i = 0; i < this->flights.size(); i++) {
            this->flights[i].toString();
        }
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

int getFlightPrice(FlightManager& flightManager, int id) {
    try {
        for (int i = 0; i < flightManager.getFlights().size(); i++) {
            if (flightManager.getFlights()[i].getId() == id) {
                return flightManager.getFlights()[i].getPrice();
            }
        }

        throw "There is no flight with that id";
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
        return -1;
    }
}