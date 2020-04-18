#include "UtilityFunctions.hpp"

using namespace std;

list<House> ConvertProperyToHouses(const list<Property*>& property) {
    list<House> houses;
    for (auto& object : property) {
        houses.push_back(*dynamic_cast<House*>(object));
    }
    return houses;
}

list<Apartment> ConvertPropertyToApartments(const list<Property*>& property) {
    list<Apartment> apartments;
    for (auto& object : property) {
        apartments.push_back(*dynamic_cast<Apartment*>(object));
    }
    return apartments;
}
