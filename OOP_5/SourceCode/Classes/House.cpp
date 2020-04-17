#include "House.hpp"

using namespace std;

House::House(double cost,
             string type,
             string location,
             Area area,
             string additionalInformation,
             string notes,
             double landArea,
             int levelsAmount,
             string wallsMaterial,
             string roofMaterial,
             bool heating,
             bool electricity,
             bool gas,
             bool waterSupply) : Property(cost, type, location, area,
                                          additionalInformation, notes) {
    this->landArea = landArea;
    this->levelsAmount = levelsAmount;
    this->wallsMaterial = wallsMaterial;
    this->roofMateral = roofMateral;
    this->heating = heating;
    this->electricity = electricity;
    this->gas = gas;
    this->waterSupply = waterSupply;
}

House::House(const House& other) : Property(other) {
    landArea = other.landArea;
    levelsAmount = other.levelsAmount;
    wallsMaterial = other.wallsMaterial;
    roofMateral = other.roofMateral;
    heating = other.heating;
    electricity = other.electricity;
    gas = other.gas;
    waterSupply = other.waterSupply;
}

double House::getLandArea() const {
    return landArea;
}

int House::getLevelsAmount() const {
    return levelsAmount;
}

string House::getWallsMaterial() const {
    return wallsMaterial;
}

string House::getRoofMaterial() const {
    return roofMateral;
}

bool House::getHeating() const {
    return heating;
}

bool House::getElectricity() const {
    return electricity;
}

bool House::getGas() const {
    return gas;
}

bool House::getWaterSupply() const {
    return waterSupply;
}

void House::setLandArea(double landArea) {
    this->landArea = landArea;
}

void House::setLevelsAmount(int levelsAmount) {
    this->levelsAmount = levelsAmount;
}

void House::setWallsMaterial(string wallsMaterial) {
    this->wallsMaterial = wallsMaterial;
}

void House::setRoofMaterial(string roofMaterial) {
    this->roofMateral = roofMateral;
}

void House::setHeating(bool heating) {
    this->heating = heating;
}

void House::setElectricity(bool electricity) {
    this->electricity = electricity;
}

void House::setGas(bool gas) {
    this->gas = gas;
}

void House::setWaterSupply(bool waterSupply) {
    this->waterSupply = waterSupply;
}

void House::printInformation() const {
    Property::printInformation();
    cout << "Площадь участка: " << landArea << endl
    << "Материал стен: " << wallsMaterial << endl
    << "Материал крыши: " << roofMateral << endl
    << "Отопление: " << boolalpha << heating << endl
    << "Электричество: " << electricity << endl
    << "Газ: " << gas << endl
    << "Водоснабжение: " << waterSupply << noboolalpha << endl;
}

House& House::operator= (const House& other) {
    Property::operator=(other);
    landArea = other.landArea;
    levelsAmount = other.levelsAmount;
    wallsMaterial = other.wallsMaterial;
    roofMateral = other.roofMateral;
    heating = other.heating;
    electricity = other.electricity;
    gas = other.gas;
    waterSupply = other.waterSupply;
    return *this;
}
