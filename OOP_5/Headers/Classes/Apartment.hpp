#ifndef Apartment_hpp
#define Apartment_hpp

#include "Property.hpp"
#include <iomanip>

class Apartment : public Property {
private:
    int roomsAmount;
    std::string houseType;
    double ceilingHeight;
    int buildingYear;
    bool balcony;
    bool phone;
    std::string repair;
public:
    Apartment(double cost = 0.0,
              std::string type = std::string(),
              std::string location = std::string(),
              Area area = Area(),
              std::string additionalInformation = std::string(),
              std::string notes = std::string(),
              int roomsAmount = 0,
              std::string houseType = std::string(),
              double ceilingHeight = 0.0,
              int buildingYear = 0,
              bool balcony = false,
              bool phone = false,
              std::string repair = std::string());
    Apartment(const Apartment& other);
    
    int getRoomsAmount() const;
    std::string getHouseType() const;
    double getCeilingHeight() const;
    int getBuildingYear() const;
    bool getBalcony() const;
    bool getPhone() const;
    std::string getRepair() const;
    
    void setRoomsAmount(int roomsAmount);
    void setHouseType(std::string houseType);
    void setCeilingHeight(double ceilingHeight);
    void setBulidingYear(int builingYear);
    void setBalcony(bool balcony);
    void setPhone(bool phone);
    void setRepair(std::string repair);
    
    void printInformation() const override;
    
    Apartment& operator= (const Apartment& other);
};

#endif
