#include "Area.hpp"

using namespace std;

Area::Area(double common, double living, double kitchen) {
    this->common = common;
    this->living = living;
    this->kitchen = kitchen;
}

Area::Area(const Area& other) {
    common = other.common;
    living = other.living;
    kitchen = other.kitchen;
}

double Area::getCommon() const {
    return common;
}

double Area::getLiving() const {
    return living;
}

double Area::getKitchen() const {
    return kitchen;
}

void Area::setCommon(double common) {
    this->common = common;
}

void Area::setLiving(double living) {
    this->living = living;
}

void Area::setKitchen(double kitchen) {
    this->kitchen = kitchen;
}

void Area::printInformation() const {
    cout << "Площадь общая/жилая/кухня: " << common << "/" << living
    << "/" << kitchen << endl;
}

Area& Area::operator= (const Area& other) {
    common = other.common;
    living = other.living;
    kitchen = other.kitchen;
    return *this;
}


ostream& operator<< (ostream& stream, const Area& area) {
    stream << "общая/жилая/кухня: " << area.common << "/" << area.living
    << "/" << area.kitchen;
    return stream;
}

istream& operator>> (istream& stream, Area& area) {
    stream >> area.common;
    stream.ignore(1);
    stream >> area.living;
    stream.ignore(1);
    stream >> area.kitchen;
    return stream;
}
