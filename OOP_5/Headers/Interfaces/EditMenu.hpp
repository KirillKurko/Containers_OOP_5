#ifndef EditMenu_hpp
#define EditMenu_hpp

#include <list>
#include <map>
#include "../Classes/House.hpp"
#include "../Classes/Apartment.hpp"
#include "../Utilities/UtilityFunctions.hpp"

std::map<int, std::function<void(std::list<Property*>&)>> CreateEditMenu();
std::map<int, std::function<void(Property*)>> CreateEditHouseMenu();
std::map<int, std::function<void(Property*)>> CreateEditApartmentMenu();

void Edit(std::map<int, std::list<Property*>>& property);
void EditHouses(std::list<Property*>& houses);
void EditApartments(std::list<Property*>& apartments);
void EditHouse(Property* house);
void EditApartment(Property* apartment);

namespace CommonEditFuncitons {
    void EditCost(Property* property);
    void EditType(Property* property);
    void EditLocation(Property* property);
    void EditCommonArea(Property* property);
    void EditLivingArea(Property* property);
    void EditKitchenArea(Property* property);
    void EditAdditionalInformation(Property* property);
    void EditNotes(Property* property);
}

namespace HouseEditFunctions {
    void EditLandArea(Property* house);
    void EditLevelsAmount(Property* house);
    void EditWallsMaterial(Property* house);
    void EditRoofMaterial(Property* house);
    void EditHeating(Property* house);
    void EditElectricity(Property* house);
    void EditGas(Property* house);
    void EditWaterSupply(Property* house);
}

namespace ApartmentEditFunctions {
    void EditRoomsAmount(Property* apartment);
    void EditHouseType(Property* apartment);
    void EditCeilingHeight(Property* apartment);
    void EditBuildingYear(Property* apartment);
    void EditBalcony(Property* apartment);
    void EditPhone(Property* apartment);
    void EditRepair(Property* apartment);
}

#endif
