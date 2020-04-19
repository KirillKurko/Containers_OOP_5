#ifndef Comparators_hpp
#define Comparators_hpp

#include "UtilityFunctions.hpp"
#include "../Classes/House.hpp"
#include "../Classes/Apartment.hpp"
#include <array>

struct Comparators {
    std::array<std::function<bool(const Property*, const Property*)>, 10> houseComparators;
    std::array<std::function<bool(const Property*, const Property*)>, 10> apartmentComparators;
    
    explicit Comparators();
    Comparators(const Comparators& other) = delete;
    Comparators& operator= (const Comparators& other) = delete;
    
    void initHouseComaparators();
    void initApartmentComparators();
    
};

#endif
