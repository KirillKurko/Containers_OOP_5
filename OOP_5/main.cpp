#include <iostream>
#include <map>
#include "list"
#include "Headers/Classes/House.hpp"
#include "Headers/Classes/Apartment.hpp"
#include "Headers/Utilities/FileSystemManager.hpp"

using namespace std;

int main() {
    FileSystemManager f;
    Property* p = new House();
    map<int, list<Property*>> property;
    property[HOUSES].push_back(p);
    property[APARTMENTS] = list<Property*>();
    f.save(property);
    delete p;
    return 0;
}
