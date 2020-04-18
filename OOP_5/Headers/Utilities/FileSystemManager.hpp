#ifndef FileSystemManager_hpp
#define FileSystemManager_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <exception>
#include "../Classes/House.hpp"
#include "../Classes/Apartment.hpp"
#include "UtilityFunctions.hpp"

class FileSystemManager {
private:
    std::string housesFilename;
    std::string apartmentsFilename;
public:
    explicit FileSystemManager(std::string housesFilename = "houses.txt",
                      std::string apartmentsFilname = "apartments.txt");
    FileSystemManager(const FileSystemManager& other) = delete;
    FileSystemManager& operator= (const FileSystemManager& other) = delete;
    
    void save(const std::map<int, std::list<Property*>>& property) const;
    void saveHouses(const std::list<House> houses) const;
    void saveHouse(std::ofstream& file, const House& house) const;
    void saveApartments(const std::list<Apartment> apartments) const;
    void saveApartment(std::ofstream& file, const Apartment& apartment) const;
    
    void load(std::map<int, std::list<Property*>>& property) const;
    void loadHouses(std::list<Property*>& houses) const;
    Property* loadHouse(std::ifstream& file) const;
    void loadApartments(std::list<Property*>& apartments) const;
    Property* loadApartment(std::ifstream& file) const;
};

#endif
