#include "FileSystemManager.hpp"

using namespace std;

FileSystemManager::FileSystemManager(string housesFilename,
                           string apartmentsFilname) {
    this->housesFilename = housesFilename;
    this->apartmentsFilename = apartmentsFilname;
}

void FileSystemManager::save(const std::map<int, list<Property*>>& property) const {
    try {
        auto houses = ToHouses(property.at(HOUSES));
        saveHouses(houses);
        auto apartments = ToApartments(property.at(APARTMENTS));
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
    file << "\n" << house.getCost() << endl <<
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
    file << "\n" << apartment.getCost() << endl <<
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

void FileSystemManager::load(map<int, list<Property*>>& property) const {
    loadHouses(property[HOUSES]);
    loadApartments(property[APARTMENTS]);
}

void FileSystemManager::loadHouses(list<Property*>& houses) const {
    string data;
    ifstream file;
    file.open(housesFilename, ios_base::in);
    if (file.is_open()) {
        while (getline(file, data)) {
            if (data == "EOF") {
                break;
            }
            auto house = loadHouse(file);
            houses.push_back(house);
        }
    }
    file.close();
}

Property* FileSystemManager::loadHouse(ifstream& file) const {
    string data;
    vector<string> arguments;
    for (int i = 0; i < 17; ++i) {
        getline(file, data);
        arguments.push_back(data);
    }
    return new House(stod(arguments[0]),
                     arguments[1],
                     arguments[2],
                     Area(stod(arguments[3]),
                          stod(arguments[4]),
                          stod(arguments[5])),
                     arguments[6],
                     arguments[7],
                     stod(arguments[8]),
                     stoi(arguments[9]),
                     arguments[10],
                     arguments[11],
                     (bool)stoi(arguments[12]),
                     (bool)stoi(arguments[13]),
                     (bool)stoi(arguments[14]),
                     (bool)stoi(arguments[15]));
}

void FileSystemManager::loadApartments(list<Property*>& apartments) const {
    string data;
    ifstream file;
    file.open(apartmentsFilename, ios_base::in);
    if (file.is_open()) {
        while (getline(file, data)) {
            if (data == "EOF") {
                break;
            }
            auto apartment = loadApartment(file);
            apartments.push_back(apartment);
        }
    }
    file.close();
}

Property* FileSystemManager::loadApartment(ifstream& file) const {
    string data;
    vector<string> arguments;
    for (int i = 0; i < 16; ++i) {
        getline(file, data);
        arguments.push_back(data);
    }
    return new Apartment(stod(arguments[0]),
                         arguments[1],
                         arguments[2],
                         Area(stod(arguments[3]),
                              stod(arguments[4]),
                              stod(arguments[5])),
                         arguments[6],
                         arguments[7],
                         stoi(arguments[8]),
                         arguments[9],
                         stod(arguments[10]),
                         stoi(arguments[11]),
                         (bool)stoi(arguments[12]),
                         (bool)stoi(arguments[13]),
                         arguments[14]);
}
