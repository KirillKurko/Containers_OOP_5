#ifndef SortFunctions_hpp
#define SortFunctions_hpp

#include <list>
#include <map>
#include "Comparators.hpp"
#include "../Classes/House.hpp"
#include "../Classes/Apartment.hpp"

void Sort(std::map<int, std::list<Property*>> property);

#endif
