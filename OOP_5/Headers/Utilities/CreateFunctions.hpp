#ifndef CreateFunctions_hpp
#define CreateFunctions_hpp

#include <iostream>
#include "../Classes/House.hpp"
#include "../Classes/Apartment.hpp"

namespace CommonEnterFunctions {
    double EnterCost();
    std::string EnterType();
    std::string EnterLocation();
    Area EnterArea();
    std::string EnterAdditionalInfrmation();
    std::string EnterNotes();
}

namespace HouseEnterFunctions {
    double EnterLandArea();
    int EnterLevelsAmount();
    std::string EnterWallsMaterial();
    std::string EnterRoofMaterial();
    bool EnterHeating();
    bool EnterElectricity();
    bool EnterGas();
    bool EnterWaterSupply();
}

namespace ApartmentEnterFunctions {
    int EnterRoomsAmount();
    std::string EnterHouseType();
    double EnterCeilingHeight();
    int EnterBulidingYear();
    bool EnterBalcony();
    bool EnterPhone();
    std::string EnterRepair();
}

namespace CreateFunctions {
    Property* CreateHouse();
    Property* CreateApartment();
}

#endif
