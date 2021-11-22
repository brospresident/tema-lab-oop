#include "./flight.h"

Flight::Flight(int id, std::string origin, std::string destination, std::string date, std::string time, int seatsAvailable) {
    this->id = id;
    this->origin = origin;
    this->destination = destination;
    this->date = date;
    this->time = time;
    this->seatsAvailable = seatsAvailable;
}

int Flight::getId() {
    return this->id;
}

std::string Flight::getOrigin() {
    return this->origin;
}

std::string Flight::getDestination() {
    return this->destination;
}

std::string Flight::getDate() {
    return this->date;
}

std::string Flight::getTime() {
    return this->time;
}

int Flight::getSeatsAvailable() {
    return this->seatsAvailable;
}

void Flight::setId(int id) {
    this->id = id;
}

void Flight::setOrigin(std::string origin) {
    this->origin = origin;
}

void Flight::setDestination(std::string destination) {
    this->destination = destination;
}

void Flight::setDate(std::string date) {
    this->date = date;
}

void Flight::setTime(std::string time) {
    this->time = time;
}

void Flight::setSeatsAvailable(int seatsAvailable) {
    this->seatsAvailable = seatsAvailable;
}

bool Flight::operator == (Flight flight) {
    return this->id == flight.getId();
}

