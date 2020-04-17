#include "Property.hpp"

using namespace std;

Property::Property(double cost,
                   string type,
                   string location,
                   Area area,
                   string additionalInformation,
                   string notes) {
    this->cost = cost;
    this->type = type;
    this->location = location;
    this->area = area;
    this->additionalInformation = additionalInformation;
    this->notes = notes;
}

Property::Property(const Property& other) {
    cost = other.cost;
    type = other.type;
    location = other.location;
    area = other.area;
    additionalInformation = other.additionalInformation;
    notes = other.notes;
}

double Property::getCost() const {
    return cost;
}

string Property::getType() const {
    return type;
}

string Property::getLocation() const {
    return location;
}

Area Property::getArea() const {
    return area;
}

string Property::getAdditionalInformation() const {
    return additionalInformation;
}

string Property::getNotes() const {
    return notes;
}

void Property::setCost(double cost) {
    this->cost = cost;
}

void Property::setType(string type) {
    this->type = type;
}

void Property::setLocation(string location) {
    this->location = location;
}

void Property::setArea(Area area) {
    this->area = area;
}

void Property::setAdditionalInformation(string additionalInformation) {
    this->additionalInformation = additionalInformation;
}

void Property::setNotes(string notes) {
    this->notes = notes;
}

void Property::printInformation() const {
    cout << "Стоимость: " << cost << endl
    << "Тип: " << type << endl
    << "Месторасположение: " << location << endl
    << "Площадь: " << area << endl
    << "Дополнительная информация: " << additionalInformation << endl
    << "Примечания: " << notes << endl;
}

Property& Property::operator= (const Property& other) {
    cost = other.cost;
    type = other.type;
    location = other.location;
    area = other.area;
    additionalInformation = other.additionalInformation;
    notes = other.notes;
    return *this;
}
