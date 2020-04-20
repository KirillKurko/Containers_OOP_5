#ifndef MainMenu_hpp
#define MainMenu_hpp

#include <iostream>
#include <map>
#include <list>
#include "../Classes/House.hpp"
#include "../Classes/Apartment.hpp"
#include "../Utilities/CreateFunctions.hpp"
#include "SortFunctions.hpp"
#include "SearchFunctions.hpp"
#include "ViewMenu.hpp"
#include "RemoveMenu.hpp"

std::map<int, std::function<void(std::map<int, std::list<Property*>>&)>> CreateMainMenu();
void MainMenu(std::map<int, std::list<Property*>>&);

#endif
