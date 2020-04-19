#include "Comparators.hpp"

using namespace std;

Comparators::Comparators() {
    initHouseComaparators();
    initApartmentComparators();
}

void Comparators::initHouseComaparators() {
    houseComparators[0] = [] (auto lhs, auto rhs) {return lhs->getCost() < rhs->getCost();};
    houseComparators[1] = [] (auto lhs, auto rhs) {return lhs->getType() < rhs->getType();};
    houseComparators[2] = [] (auto lhs, auto rhs) {return lhs->getLocation() < rhs->getLocation();};
    houseComparators[3] = [] (auto lhs, auto rhs) {return lhs->getArea().getCommon() < rhs->getArea().getCommon();};
    houseComparators[4] = [] (auto lhs, auto rhs) {return lhs->getArea().getLiving() < rhs->getArea().getLiving();};
    houseComparators[5] = [] (auto lhs, auto rhs) {return lhs->getArea().getKitchen() < rhs->getArea().getKitchen();};
    houseComparators[6] = [] (auto lhs, auto rhs) {return ToHouse(lhs).getLandArea() < ToHouse(rhs).getLandArea();};
    houseComparators[7] = [] (auto lhs, auto rhs) {return ToHouse(lhs).getLevelsAmount() < ToHouse(rhs).getLevelsAmount();};
    houseComparators[8] = [] (auto lhs, auto rhs) {return ToHouse(lhs).getWallsMaterial() < ToHouse(rhs).getWallsMaterial();};
    houseComparators[9] = [] (auto lhs, auto rhs) {return ToHouse(lhs).getRoofMaterial() < ToHouse(rhs).getRoofMaterial();};
}

void Comparators::initApartmentComparators() {
    apartmentComparators[0] = [] (auto lhs, auto rhs) {return lhs->getCost() < rhs->getCost();};
    apartmentComparators[1] = [] (auto lhs, auto rhs) {return lhs->getType() < rhs->getType();};
    apartmentComparators[2] = [] (auto lhs, auto rhs) {return lhs->getLocation() < rhs->getLocation();};
    apartmentComparators[3] = [] (auto lhs, auto rhs) {return lhs->getArea().getCommon() < rhs->getArea().getCommon();};
    apartmentComparators[4] = [] (auto lhs, auto rhs) {return lhs->getArea().getLiving() < rhs->getArea().getLiving();};
    apartmentComparators[5] = [] (auto lhs, auto rhs) {return lhs->getArea().getKitchen() < rhs->getArea().getKitchen();};
    apartmentComparators[6] = [] (auto lhs, auto rhs) {return ToApartment(lhs).getRoomsAmount() < ToApartment(rhs).getRoomsAmount();};
    apartmentComparators[7] = [] (auto lhs, auto rhs) {return ToApartment(lhs).getHouseType() < ToApartment(rhs).getHouseType();};
    apartmentComparators[8] = [] (auto lhs, auto rhs) {return ToApartment(lhs).getCeilingHeight() < ToApartment(rhs).getCeilingHeight();};
    apartmentComparators[9] = [] (auto lhs, auto rhs) {return ToApartment(lhs).getBuildingYear() < ToApartment(rhs).getBuildingYear();};
}
