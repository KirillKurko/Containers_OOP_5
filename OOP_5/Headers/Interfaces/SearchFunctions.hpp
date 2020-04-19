#ifndef SearchFunctions_hpp
#define SearchFunctions_hpp

#include "../Utilities/UtilityFunctions.hpp"
#include "../Classes/House.hpp"
#include "../Classes/Apartment.hpp"
#include <string>

std::map<int, std::function<void(std::list<Property*>&)>> CreateSearchMenu();
void Search(std::map<int, std::list<Property*>> property);
void SearchHouses(std::list<Property*>& houses);
void SearchApartments(std::list<Property*>& apartments);

std::map<int, std::function<void(std::list<Property*>&)>> CreateSearchHousesMenu();
std::map<int, std::function<void(std::list<Property*>&)>> CreateSearchApartmentsMenu();

namespace CommonSearchFuncitons {
    void ByCost(std::list<Property*>& property);
    void ByType(std::list<Property*>& property);
    void ByLocation(std::list<Property*>& property);
    void ByCommonArea(std::list<Property*>& property);
    void ByLivingArea(std::list<Property*>& property);
    void ByKitchenArea(std::list<Property*>& property);
}

namespace HouseSearchFucntions {
    void ByLandArea(std::list<Property*>& houses);
    void ByLevelsAmount(std::list<Property*>& houses);
    void ByWallsMaterial(std::list<Property*>& houses);
    void ByRoofMaterial(std::list<Property*>& houses);
    void WithHeating(std::list<Property*>& houses);
    void WithElectricity(std::list<Property*>& houses);
    void WithGas(std::list<Property*>& houses);
    void WithWaterSupply(std::list<Property*>& houses);
}

namespace ApartmentSearchFunctions {
    void ByRoomsAmount(std::list<Property*>& apartments);
    void ByHouseType(std::list<Property*>& apartments);
    void ByCeilingHeight(std::list<Property*>& apartments);
    void ByBuildingYear(std::list<Property*>& apartments);
    void WithBalcony(std::list<Property*>& apartments);
    void WithPhone(std::list<Property*>& apartments);
    void ByRepair(std::list<Property*>& apartments);
}


#endif 
