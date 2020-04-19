#include "UtilityFunctions.hpp"

using namespace std;

list<House> ToHouses(const list<Property*>& property) {
    list<House> houses;
    for (auto& object : property) {
        houses.push_back(ToHouse(object));
    }
    return houses;
}

list<Apartment> ToApartments(const list<Property*>& property) {
    list<Apartment> apartments;
    for (auto& object : property) {
        apartments.push_back(ToApartment(object));
    }
    return apartments;
}

House ToHouse(const Property* property) {
    return *dynamic_cast<House*>(const_cast<Property*>(property));
}

Apartment ToApartment(const Property* property) {
     return *dynamic_cast<Apartment*>(const_cast<Property*>(property));
}

