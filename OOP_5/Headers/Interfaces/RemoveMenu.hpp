#ifndef RemoveMenu_hpp
#define RemoveMenu_hpp

#include <list>
#include <map>
#include "../Utilities/Comparators.hpp"
#include "../Classes/House.hpp"
#include "../Classes/Apartment.hpp"

void Remove(std::map<int, std::list<Property*>>& property);
void RemoveProperty(std::list<Property*>& property);

#endif
