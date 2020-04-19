#ifndef SortFunctions_hpp
#define SortFunctions_hpp

#include <list>
#include <map>
#include "Comparators.hpp"
#include "../Classes/House.hpp"
#include "../Classes/Apartment.hpp"

std::map<int, std::function<void(std::list<Property*>&)>> CreateSortMenu();
void Sort(std::map<int, std::list<Property*>> property);
void SortHouses(std::list<Property*>& houses);
void SortApartments(std::list<Property*>& apartments);

#endif
