#ifndef Area_hpp
#define Area_hpp

#include <iostream>
#include <fstream>

class Area {
    friend std::ostream& operator<< (std::ostream& stream, const Area& area);
    friend std::istream& operator>> (std::istream& stream, Area& area);
private:
    double common;
    double living;
    double kitchen;
public:
    Area(double common = 0.0, double living = 0.0, double kitchen = 0.0);
    Area(const Area& other);
    
    double getCommon() const;
    double getLiving() const;
    double getKitchen() const;
    
    void setCommon(double common);
    void setLiving(double living);
    void setKitchen(double kitchen);
    
    void printInformation() const;
    
    Area& operator= (const Area& other);
};

#endif
