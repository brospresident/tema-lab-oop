#include "./flight.h"

Flight::Flight() {
    this->id = -1;
}

Flight::Flight(int id, std::string origin, std::string destination, std::string dateString, int time, int seatsAvailable, int price, std::string originCountry, std::string destinationCountry) {
    this->id = id;
    this->origin = origin;
    this->destination = destination;
    this->flightDate = date(from_simple_string(dateString));
    this->time = time;
    this->seatsAvailable = seatsAvailable;
    this->price = price;
    this->originCountry = originCountry;
    this->destinationCountry = destinationCountry;
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

date Flight::getDate() {
    return this->flightDate;
}

int Flight::getTime() {
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

void Flight::setDate(std::string d) {
    this->flightDate = date(from_simple_string(d));
}

void Flight::setTime(int time) {
    this->time = time;
}

void Flight::setSeatsAvailable(int seatsAvailable) {
    this->seatsAvailable = seatsAvailable;
}

void Flight::toString() {
    std::cout << "Flight: " << this->id << " | " << this->origin << " (" << this->originCountry << ")" << " - " << this->destination << " (" << this->destinationCountry << ")" << " - " << this->flightDate << " - " << this->time << "minutes" << " - " << this->seatsAvailable << " seats available " << " - $" << this->price << std::endl;
}

bool Flight::isAvailable() {
    if (this->seatsAvailable == 0) {
        return false;
    }

    date now = day_clock::local_day();

    if (now > this->flightDate) {
        return false;
    }

    return true;
}

void Flight::setPrice(int price) {
    this->price = price;
}

int Flight::getPrice() {
    return this->price;
}

std::string Flight::getOriginCountry() {
    return this->originCountry;
}

std::string Flight::getDestinationCountry() {
    return this->destinationCountry;
}