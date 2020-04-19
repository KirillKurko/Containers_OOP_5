#include "SearchFunctions.hpp"

using namespace std;
using namespace CommonSearchFuncitons;

map<int, function<void(list<Property*>&)>> CreateSearchMenu() {
    map<int, function<void(list<Property*>&)>> searchMenu;
    searchMenu[1] = SearchHouses;
    searchMenu[2] = SearchApartments;
    return searchMenu;
}

map<int, function<void(list<Property*>&)>> CreateSearchHousesMenu() {
    using namespace HouseSearchFucntions;
    map<int, function<void(list<Property*>&)>> searchHousesMenu;
    searchHousesMenu[1] = ByCost;
    searchHousesMenu[2] = ByType;
    searchHousesMenu[3] = ByLocation;
    searchHousesMenu[4] = ByCommonArea;
    searchHousesMenu[5] = ByLivingArea;
    searchHousesMenu[6] = ByKitchenArea;
    searchHousesMenu[7] = ByLandArea;
    searchHousesMenu[8] = ByLevelsAmount;
    searchHousesMenu[9] = ByWallsMaterial;
    searchHousesMenu[10] = ByRoofMaterial;
    searchHousesMenu[11] = WithHeating;
    searchHousesMenu[12] = WithElectricity;
    searchHousesMenu[13] = WithGas;
    searchHousesMenu[14] = WithWaterSupply;
    return searchHousesMenu;
}

map<int, function<void(list<Property*>&)>> CreateSearchApartmentsMenu() {
    using namespace ApartmentSearchFunctions;
    map<int, function<void(list<Property*>&)>> searchApartmentsMenu;
    searchApartmentsMenu[1] = ByCost;
    searchApartmentsMenu[2] = ByType;
    searchApartmentsMenu[3] = ByLocation;
    searchApartmentsMenu[4] = ByCommonArea;
    searchApartmentsMenu[5] = ByLivingArea;
    searchApartmentsMenu[6] = ByKitchenArea;
    searchApartmentsMenu[7] = ByRoomsAmount;
    searchApartmentsMenu[8] = ByHouseType;
    searchApartmentsMenu[9] = ByCeilingHeight;
    searchApartmentsMenu[10] = ByBuildingYear;
    searchApartmentsMenu[11] = WithBalcony;
    searchApartmentsMenu[12] = WithPhone;
    searchApartmentsMenu[13] = ByRepair;
    return searchApartmentsMenu;
}

void Search(std::map<int, list<Property*>> property) {
    auto searchMenu = CreateSearchMenu();
    int selection = 0;
    while (true) {
        cout << "\n1 - Поиск домов\n2 - Поиск квартир\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        cin.ignore();
        try {
            searchMenu.at(selection)(property[selection]);
        }
        catch (const out_of_range& exception) {
            cout << "Выход из меню поиска" << endl;
        }
    }
}

void SearchHouses(list<Property*>& houses) {
    auto searchHousesMenu = CreateSearchHousesMenu();
    int selection = 0;
    while (true) {
        cout << "\n1 - Поиск по стоимости"
             << "\n2 - Поиск по типу"
             << "\n3 - Поиск по месторасположению"
             << "\n4 - Поиск по общей площади"
             << "\n5 - Поиск по жилой площади"
             << "\n6 - Поиск по площади кухни"
             << "\n7 - Поиск по площади участка"
             << "\n8 - Поиск по количеству уровней"
             << "\n9 - Поиск по материалу стен"
             << "\n10 - Поиск по материалу крыши"
             << "\n11 - Поиск домов с отплением"
             << "\n12 - Поиск домов с электричеством"
             << "\n13 - Поиск домов с газом"
             << "\n14 - Поиск домов с водоснабжением"
             << "\n15 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        cin.ignore();
        try {
            searchHousesMenu.at(selection)(houses);
        }
        catch (const out_of_range& exception) {
            cout << "Выход из меню поиска домов" << endl;
        }
    }
}

void SearchApartments(list<Property*>& apartments) {
    auto searchApartmentsMenu = CreateSearchApartmentsMenu();
    int selection = 0;
    while (true) {
        cout << "\n1 - Поиск по стоимости"
        << "\n2 - Поиск по типу"
        << "\n3 - Поиск по месторасположению"
        << "\n4 - Поиск по общей площади"
        << "\n5 - Поиск по жилой площади"
        << "\n6 - Поиск по площади кухни"
        << "\n7 - Поиск по количеству комнат"
        << "\n8 - Поиск по типу дома"
        << "\n9 - Поиск по высоте потолков"
        << "\n10 - Поиск по году постройки"
        << "\n11 - Поиск квартир с балконом"
        << "\n12 - Поиск квартир с телефоном"
        << "\n13 - Поиск по ремонту"
        << "\n14 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        cin.ignore();
        try {
            searchApartmentsMenu.at(selection)(apartments);
        }
        catch (const out_of_range& exception) {
            cout << "Выход из меню поиска квартир" << endl;
        }
    }
}

void CommonSearchFuncitons::ByCost(std::list<Property*>& property) {
    int matchesAmount = 0;
    double cost = 0.0;
    cout << "Введите стоимость: ";
    cin >> cost;
    cin.ignore();
    for (auto& object : property) {
        if (object->getCost() == cost) {
            object->printInformation();
            ++matchesAmount;
        }
    }
    cout << "Найдено " << matchesAmount << " совпадений" << endl;
}

void CommonSearchFuncitons::ByType(std::list<Property*>& property) {
    int matchesAmount = 0;
    string type;
    cout << "Введите тип: ";
    getline(cin, type);
    for (auto& object : property) {
        if (object->getType() == type) {
            object->printInformation();
            ++matchesAmount;
        }
    }
    cout << "Найдено " << matchesAmount << " совпадений" << endl;
}

void CommonSearchFuncitons::ByLocation(std::list<Property*>& property) {
    int matchesAmount = 0;
    string location;
    cout << "Введите месторасположение: ";
    getline(cin, location);
    for (auto& object : property) {
        if (object->getLocation() == location) {
            object->printInformation();
            ++matchesAmount;
        }
    }
    cout << "Найдено " << matchesAmount << " совпадений" << endl;
}

void CommonSearchFuncitons::ByCommonArea(std::list<Property*>& property) {
    int matchesAmount = 0;
    double commonArea;
    cout << "Введите общую площадь: ";
    cin >> commonArea;
    cin.ignore();
    for (auto& object : property) {
        if (object->getArea().getCommon() == commonArea) {
            object->printInformation();
            ++matchesAmount;
        }
    }
    cout << "Найдено " << matchesAmount << " совпадений" << endl;
}

void CommonSearchFuncitons::ByLivingArea(std::list<Property*>& property) {
    int matchesAmount = 0;
    double livingArea;
    cout << "Введите жилую площадь: ";
    cin >> livingArea;
    cin.ignore();
    for (auto& object : property) {
        if (object->getArea().getLiving() == livingArea) {
            object->printInformation();
            ++matchesAmount;
        }
    }
    cout << "Найдено " << matchesAmount << " совпадений" << endl;
}

void CommonSearchFuncitons::ByKitchenArea(std::list<Property*>& property) {
    int matchesAmount = 0;
    double kitchenArea;
    cout << "Введите площадь кухни: ";
    cin >> kitchenArea;
    cin.ignore();
    for (auto& object : property) {
        if (object->getArea().getKitchen() == kitchenArea) {
            object->printInformation();
            ++matchesAmount;
        }
    }
    cout << "Найдено " << matchesAmount << " совпадений" << endl;
}

void HouseSearchFucntions::ByLandArea(std::list<Property*>& houses) {
    
}

void HouseSearchFucntions::ByLevelsAmount(std::list<Property*>& houses) {
    
}

void HouseSearchFucntions::ByWallsMaterial(std::list<Property*>& houses) {
    
}

void HouseSearchFucntions::ByRoofMaterial(std::list<Property*>& houses) {
    
}

void HouseSearchFucntions::WithHeating(std::list<Property*>& houses) {
    
}

void HouseSearchFucntions::WithElectricity(std::list<Property*>& houses) {
    
}

void HouseSearchFucntions::WithGas(std::list<Property*>& houses) {
    
}

void HouseSearchFucntions::WithWaterSupply(std::list<Property*>& houses) {
    
}

void ApartmentSearchFunctions::ByRoomsAmount(std::list<Property*>& apartments) {
    
}

void ApartmentSearchFunctions::ByHouseType(std::list<Property*>& apartments) {
    
}

void ApartmentSearchFunctions::ByCeilingHeight(std::list<Property*>& apartments) {
    
}

void ApartmentSearchFunctions::ByBuildingYear(std::list<Property*>& apartments) {
    
}

void ApartmentSearchFunctions::WithBalcony(std::list<Property*>& apartments) {
    
}

void ApartmentSearchFunctions::WithPhone(std::list<Property*>& apartments) {
    
}

void ApartmentSearchFunctions::ByRepair(std::list<Property*>& apartments) {
    
}
