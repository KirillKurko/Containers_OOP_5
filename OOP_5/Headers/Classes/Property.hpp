#ifndef Property_hpp
#define Property_hpp

#include <iostream>
#include <string>
#include "../Utilities/Area.hpp"

enum{HOUSES = 1, APARTMENTS};

class Property {
protected:
    double cost;
    std::string type;
    std::string location;
    Area area;
    std::string additionalInformation;
    std::string notes;
public:
    Property(double cost = 0.0,
             std::string type = std::string(),
             std::string location = std::string(),
             Area area = Area(),
             std::string additionalInformation = std::string(),
             std::string notes = std::string());
    Property(const Property& other);
    virtual ~Property() = default;
    
    double getCost() const;
    std::string getType() const;
    std::string getLocation() const;
    Area getArea() const;
    std::string getAdditionalInformation() const;
    std::string getNotes() const;
    
    void setCost(double cost);
    void setType(std::string type);
    void setLocation(std::string location);
    void setArea(Area area);
    void setAdditionalInformation(std::string additionalInformation);
    void setNotes(std::string notes);
    
    virtual void printInformation() const;
    
    Property& operator= (const Property& other);
};

#endif
