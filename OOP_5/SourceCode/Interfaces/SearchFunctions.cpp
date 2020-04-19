#include "SearchFunctions.hpp"

using namespace std;
using namespace CommonSearchFuncitons;
using namespace HouseSearchFucntions;
using namespace ApartmentSearchFunctions;

map<int, function<void(list<Property*>&)>> CreateSearchMenu() {
    map<int, function<void(list<Property*>&)>> searchMenu;
    searchMenu[1] = SearchHouses;
    searchMenu[2] = SearchApartments;
    return searchMenu;
}

map<int, function<void(list<Property*>&)>> CreateSearchHousesMenu() {
    map<int, function<void(list<Property*>&)>> searchHousesMenu;
    return searchHousesMenu;
}

map<int, function<void(list<Property*>&)>> CreateSearchApartmentsMenu() {
    map<int, function<void(list<Property*>&)>> searchApartmentsMenu;
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

}

void SearchApartments(list<Property*>& apartments) {
    
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
