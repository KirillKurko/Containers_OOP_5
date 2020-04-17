#include "Apartment.hpp"

using namespace std;

Apartment::Apartment(double cost,
                     string type,
                     string location,
                     Area area,
                     string additionalInformation,
                     string notes,
                     int roomsAmount,
                     string houseType,
                     double ceilingHeight,
                     int buildingYear,
                     bool balcony,
                     bool phone,
                     string repair) : Property(cost, type, location, area,
                                               additionalInformation, notes) {
    this->roomsAmount = roomsAmount;
    this->houseType = houseType;
    this->ceilingHeight = ceilingHeight;
    this->buildingYear = buildingYear;
    this->balcony = balcony;
    this->phone = phone;
    this->repair = repair;
}

Apartment::Apartment(const Apartment& other) : Property(other) {
    roomsAmount = other.roomsAmount;
    houseType = other.houseType;
    ceilingHeight = other.ceilingHeight;
    buildingYear = other.buildingYear;
    balcony = other.balcony;
    phone = other.phone;
    repair = other.repair;
}

int Apartment::getRoomsAmount() const {
    return roomsAmount;
}

string Apartment::getHouseType() const {
    return houseType;
}

double Apartment::getCeilingHeight() const {
    return ceilingHeight;
}

int Apartment::getBuildingYear() const {
    return buildingYear;
}

bool Apartment::getBalcony() const {
    return balcony;
}

bool Apartment::getPhone() const {
    return phone;
}

string Apartment::getRepair() const {
    return repair;
}

void Apartment::setRoomsAmount(int roomsAmount) {
    this->roomsAmount = roomsAmount;
}

void Apartment::setHouseType(string houseType) {
    this->houseType = houseType;
}

void Apartment::setCeilingHeight(double ceilingHeight) {
    this->ceilingHeight = ceilingHeight;
}

void Apartment::setBulidingYear(int buildingYear) {
    this->buildingYear = buildingYear;
}

void Apartment::setBalcony(bool balcony) {
    this->balcony = balcony;
}

void Apartment::setPhone(bool phone) {
    this->phone = phone;
}

void Apartment::setRepair(string repair) {
    this->repair = repair;
}

void Apartment::printInformation() const {
    Property::printInformation();
    cout << "Количество комнат: " << roomsAmount << endl
    << "Тип дома: " << houseType << endl
    << "Высота потолков: " << ceilingHeight << endl
    << "Год постройки: " << buildingYear << endl
    << "Балкон: " << boolalpha << balcony << endl
    << "Телефон: " << phone << endl
    << "Ремонт: " << repair << noboolalpha << endl;
}

Apartment& Apartment::operator= (const Apartment& other) {
    Property::operator=(other);
    roomsAmount = other.roomsAmount;
    houseType = other.houseType;
    ceilingHeight = other.ceilingHeight;
    buildingYear = other.buildingYear;
    balcony = other.balcony;
    phone = other.phone;
    repair = other.repair;
    return *this;
}
