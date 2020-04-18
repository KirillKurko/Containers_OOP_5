#include "FileSystemManager.hpp"

using namespace std;

FileSystemManager::FileSystemManager(string housesFilename,
                           string apartmentsFilname) {
    this->housesFilename = housesFilename;
    this->apartmentsFilename = apartmentsFilename;
}

void FileSystemManager::save(const std::map<int, list<Property*>>& property) const {
    try {
        auto houses = ConvertProperyToHouses(property.at(HOUSES));
        saveHouses(houses);
        auto apartments = ConvertPropertyToApartments(property.at(APARTMENTS));
        saveApartments(apartments);
    }
    catch (const out_of_range& excepition) {
        cout << "Ошибка при сохранении: " << excepition.what() << endl;
    }
}

void FileSystemManager::saveHouses(const list<House> houses) const {
    ofstream file;
    file.open(housesFilename, ios_base::out);
    if (file.is_open()) {
        for (auto& house : houses) {
            saveHouse(file, house);
        }
    }
    file << "EOF" << endl;
    file.close();
}

void FileSystemManager::saveHouse(ofstream& file, const House& house) const {
    file << house.getCost() << endl <<
    house.getType() << endl <<
    house.getLocation() << endl <<
    house.getArea().getCommon() << endl <<
    house.getArea().getLiving() << endl <<
    house.getArea().getKitchen() << endl <<
    house.getAdditionalInformation() << endl <<
    house.getNotes() << endl <<
    house.getLandArea() << endl <<
    house.getLevelsAmount() << endl <<
    house.getWallsMaterial() << endl <<
    house.getRoofMaterial() << endl <<
    house.getHeating() << endl <<
    house.getElectricity() << endl <<
    house.getGas() << endl <<
    house.getWaterSupply() << endl <<
    "EOH" << endl;
}

void FileSystemManager::saveApartments(const list<Apartment> apartments) const {
    ofstream file;
    file.open(apartmentsFilename, ios_base::out);
    if (file.is_open()) {
        for (auto& apartment : apartments) {
            saveApartment(file, apartment);
        }
    }
    file << "EOF" << endl;
    file.close();
}

void FileSystemManager::saveApartment(ofstream& file, const Apartment& apartment) const {
    file << apartment.getCost() << endl <<
    apartment.getType() << endl <<
    apartment.getLocation() << endl <<
    apartment.getArea().getCommon() << endl <<
    apartment.getArea().getLiving() << endl <<
    apartment.getArea().getKitchen() << endl <<
    apartment.getAdditionalInformation() << endl <<
    apartment.getNotes() << endl <<
    apartment.getRoomsAmount() << endl <<
    apartment.getHouseType() << endl <<
    apartment.getCeilingHeight() << endl <<
    apartment.getBuildingYear() << endl <<
    apartment.getBalcony() << endl <<
    apartment.getPhone() << endl <<
    apartment.getRepair() << endl <<
    "EOA" << endl;
}

//map<int, list<Property*>> FileSystemManager::loadProperty() const {
//
//}
//
//list<Property*> FileSystemManager::loadHouses() const {
//
//}
//
//Property* FileSystemManager::loadHouse(ifstream& file) const {
//
//}
//
//list<Property*> FileSystemManager::loadApartments() const {
//
//}
//
//Property* FileSystemManager::loadApartment(ifstream& file) const {
//
//}
