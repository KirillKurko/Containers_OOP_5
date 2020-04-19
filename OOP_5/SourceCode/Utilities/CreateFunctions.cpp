#include "CreateFunctions.hpp"

using namespace std;

map<int, function<Property*(void)>> CreateFunctions::CreateAddMenu() {
    map<int, function<Property*(void)>> addMenu;
    addMenu[1] = CreateHouse;
    addMenu[2] = CreateApartment;
    return addMenu;
}

void CreateFunctions::Add(std::map<int, std::list<Property*>>& property) {
    auto addMenu = CreateAddMenu();
    int selection = 0;
    while (true) {
        cout << "\n1 - Добавить дом"
             << "\n2 - Добавить квартиру"
             << "\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        cin.ignore();
        try {
            property[selection].push_back(addMenu.at(selection)());
        }
        catch (const out_of_range& exception) {
            cout << "Выход из меню добавления" << endl;
            return;
        }
    }
}

Property* CreateFunctions::CreateHouse() {
    using namespace CommonEnterFunctions;
    using namespace HouseEnterFunctions;
    auto cost = EnterCost();
    auto type = EnterType();
    auto location = EnterLocation();
    auto area = EnterArea();
    auto additionalInformation = EnterAdditionalInfrmation();
    auto notes = EnterNotes();
    auto landArea = EnterLandArea();
    auto levelsAmount = EnterLevelsAmount();
    auto wallsMaterial = EnterWallsMaterial();
    auto roofMaterial = EnterRoofMaterial();
    auto heating = EnterHeating();
    auto electricity = EnterElectricity();
    auto gas = EnterGas();
    auto waterSupply = EnterWaterSupply();
    return new House(cost, type, location, area,
                     additionalInformation, notes,
                     landArea, levelsAmount,wallsMaterial,
                     roofMaterial, heating, electricity,
                     gas, waterSupply);
}

Property* CreateFunctions::CreateApartment() {
    using namespace CommonEnterFunctions;
    using namespace ApartmentEnterFunctions;
    auto cost = EnterCost();
    auto type = EnterType();
    auto location = EnterLocation();
    auto area = EnterArea();
    auto additionalInformation = EnterAdditionalInfrmation();
    auto notes = EnterNotes();
    auto roomsAmount = EnterRoomsAmount();
    auto houseType = EnterHouseType();
    auto ceilingHeight = EnterCeilingHeight();
    auto buildingYear = EnterBulidingYear();
    auto balcony = EnterBalcony();
    auto phone = EnterPhone();
    auto repair = EnterRepair();
    return new Apartment(cost, type, location, area,
                         additionalInformation, notes,
                         roomsAmount, houseType, ceilingHeight,
                         buildingYear, balcony, phone, repair);
}

double CommonEnterFunctions::EnterCost() {
    double cost = 0.0;
    cout << "Введите стоимость: ";
    cin >> cost;
    cin.ignore();
    return cost;
}

string CommonEnterFunctions::EnterType() {
    string type;
    cout << "Введите тип объекта: ";
    getline(cin, type);
    return type;
}

string CommonEnterFunctions::EnterLocation() {
    string location;
    cout << "Введите месторасположение: ";
    getline(cin, location);
    return location;
}

Area CommonEnterFunctions::EnterArea() {
    Area area;
    cout << "Введите площадь (общая/жилая/кухня): ";
    cin >> area;
    cin.ignore();
    return area;
}

string CommonEnterFunctions::EnterAdditionalInfrmation() {
    string additionalInformation;
    cout << "Введите дополнительную информацию: ";
    getline(cin, additionalInformation);
    return additionalInformation;
}

string CommonEnterFunctions::EnterNotes() {
    string notes;
    cout << "Введите примечания: ";
    getline(cin, notes);
    return notes;
}

double HouseEnterFunctions::EnterLandArea() {
    double landArea = 0.0;
    cout << "Введите площадь участка: ";
    cin >> landArea;
    cin.ignore();
    return landArea;
}

int HouseEnterFunctions::EnterLevelsAmount() {
    int levelsAmount = 0;
    cout << "Введите количество уровней: ";
    cin >> levelsAmount;
    cin.ignore();
    return levelsAmount;
}

string HouseEnterFunctions::EnterWallsMaterial() {
    string wallsMaterial;
    cout << "Введите материал стен: ";
    getline(cin, wallsMaterial);
    return wallsMaterial;
}

string HouseEnterFunctions::EnterRoofMaterial() {
    string roofMaterial;
    cout << "Введите материал крыши: ";
    getline(cin, roofMaterial);
    return roofMaterial;
}

bool HouseEnterFunctions::EnterHeating() {
    bool heating = false;
    cout << "Введите отопление: ";
    cin >> heating;
    cin.ignore();
    return heating;
}

bool HouseEnterFunctions::EnterElectricity() {
    bool electricity = false;
    cout << "Введите электричество: ";
    cin >> electricity;
    cin.ignore();
    return electricity;
}

bool HouseEnterFunctions::EnterGas() {
    bool gas = false;
    cout << "Введите газ: ";
    cin >> gas;
    cin.ignore();
    return gas;
}

bool HouseEnterFunctions::EnterWaterSupply() {
    bool waterSupply = false;
    cout << "Введите водоснабжение: ";
    cin >> waterSupply;
    cin.ignore();
    return waterSupply;
}

int ApartmentEnterFunctions::EnterRoomsAmount() {
    int roomsAmount = 0;
    cout << "Введите количество комнат: ";
    cin >> roomsAmount;
    cin.ignore();
    return roomsAmount;
}

string ApartmentEnterFunctions::EnterHouseType() {
    string houseType;
    cout << "Введите тип дома: ";
    getline(cin, houseType);
    return houseType;
}

double ApartmentEnterFunctions::EnterCeilingHeight() {
    double ceilingHeight = 0.0;
    cout << "Введите высоту потолков: ";
    cin >> ceilingHeight;
    cin.ignore();
    return ceilingHeight;
}

int ApartmentEnterFunctions::EnterBulidingYear() {
    int buildingYear = 0;
    cout << "Введите год постройки: ";
    cin >> buildingYear;
    cin.ignore();
    return buildingYear;
}

bool ApartmentEnterFunctions::EnterBalcony() {
    bool balcony = false;
    cout << "Введите балкон: ";
    cin >> balcony;
    cin.ignore();
    return balcony;
}

bool ApartmentEnterFunctions::EnterPhone() {
    bool phone = false;
    cout << "Введите телефон: ";
    cin >> phone;
    cin.ignore();
    return phone;
}

string ApartmentEnterFunctions::EnterRepair() {
    string repair;
    cout << "Введите ремонт: ";
    getline(cin, repair);
    return repair;
}
