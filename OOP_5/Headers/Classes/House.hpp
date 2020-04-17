#ifndef House_hpp
#define House_hpp

#include "Property.hpp"
#include <iomanip>

class House : public Property {
private:
    double landArea;
    int levelsAmount;
    std::string wallsMaterial;
    std::string roofMateral;
    bool heating;
    bool electricity;
    bool gas;
    bool waterSupply;
public:
    House(double cost = 0.0,
          std::string type = std::string(),
          std::string location = std::string(),
          Area area = Area(),
          std::string additionalInformation = std::string(),
          std::string notes = std::string(),
          double landArea = 0.0,
          int levelsAmount = 0,
          std::string wallsMaterial = std::string(),
          std::string roofMaterial = std::string(),
          bool heating = false,
          bool electricity = false,
          bool gas = false,
          bool waterSupply = false);
    House(const House& other);
    
    double getLandArea() const;
    int getLevelsAmount() const;
    std::string getWallsMaterial() const;
    std::string getRoofMaterial() const;
    bool getHeating() const;
    bool getElectricity() const;
    bool getGas() const;
    bool getWaterSupply() const;
    
    void setLandArea(double landArea);
    void setLevelsAmount(int levelsAmount);
    void setWallsMaterial(std::string wallsMaterial);
    void setRoofMaterial(std::string roofMaterial);
    void setHeating(bool heating);
    void setElectricity(bool electricity);
    void setGas(bool gas);
    void setWaterSupply(bool waterSupply);

    void printInformation() const override;
    
    House& operator= (const House& other);
};


#endif
