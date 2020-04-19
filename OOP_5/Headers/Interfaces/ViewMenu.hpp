#ifndef ViewMenu_hpp
#define ViewMenu_hpp

#include <list>
#include <map>
#include "../Utilities/Comparators.hpp"
#include "../Classes/House.hpp"
#include "../Classes/Apartment.hpp"

void View(std::map<int, std::list<Property*>>& property);
void ViewProperty(std::list<Property*>& property);

#endif
