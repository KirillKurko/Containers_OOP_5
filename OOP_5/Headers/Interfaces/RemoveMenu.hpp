#ifndef RemoveMenu_hpp
#define RemoveMenu_hpp

#include <list>
#include <map>
#include "../Utilities/Comparators.hpp"
#include "../Classes/House.hpp"
#include "../Classes/Apartment.hpp"

std::map<int, std::function<void(std::list<Property*>&)>> CreateRemoveMenu();
void Remove(std::map<int, std::list<Property*>>& property);

#endif
