#ifndef UtilityFunctions_hpp
#define UtilityFunctions_hpp

#include <list>
#include <map>
#include "../Classes/Apartment.hpp"
#include "../Classes/House.hpp"

std::list<House> ToHouses(const std::list<Property*>& property);
std::list<Apartment> ToApartments(const std::list<Property*>& property);

House ToHouse(const Property* property);
Apartment ToApartment(const Property* property);

House& ToHouse(Property* property);
Apartment& ToApartment(Property* property);


#endif
