#include "SortFunctions.hpp"

using namespace std;

static Comparators comparators;

map<int, function<void(list<Property*>&)>> CreateSortMenu() {
    map<int, function<void(list<Property*>&)>> sortMenu;
    sortMenu[1] = SortHouses;
    sortMenu[2] = SortApartments;
    return sortMenu;
}

void Sort(map<int, list<Property*>> property) {
    auto sortMenu = CreateSortMenu();
    int selection = 0;
    while (true) {
        cout << "\n1 - Сортировать дома\n2 - Сортировать квартиры\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        try {
            sortMenu.at(selection)(property[selection]);
        }
        catch (const out_of_range& exception) {
            cout << "Выход из меню сортировки" << endl;
        }
    }
}

void SortHouses(list<Property*>& houses) {
    int selection = 0;
    while (true) {
        cout << "\n1 - Сортировка по стоимости"
             << "\n2 - Сортировка по типу"
             << "\n3 - Сортировка по месторасположению"
             << "\n4 - Сортировка по общей площади"
             << "\n5 - Сортировка по жилой площади"
             << "\n6 - Сортировка по площади кухни"
             << "\n7 - Сортировка по площади участка"
             << "\n8 - Сортировка по количеству уровней"
             << "\n9 - Сортировка по материалу стен"
             << "\n10 - Сортировка по материалу крыши"
             << "\n11 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        try {
            houses.sort(comparators.houseComparators.at(selection - 1));
        }
        catch (const out_of_range& exception) {
            cout << "Выход из меню сортировки домов" << endl;
        }
    }
}

void SortApartments(list<Property*>& apartments) {
    int selection = 0;
    while (true) {
        cout << "\n1 - Сортировка по стоимости"
        << "\n2 - Сортировка по типу"
        << "\n3 - Сортировка по месторасположению"
        << "\n4 - Сортировка по общей площади"
        << "\n5 - Сортировка по жилой площади"
        << "\n6 - Сортировка по площади кухни"
        << "\n7 - Сортировка по количеству комнат"
        << "\n8 - Сортировка по типу дома"
        << "\n9 - Сортировка по высоте потолков"
        << "\n10 - Сортировка по году постройки"
        << "\n11 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        try {
            apartments.sort(comparators.apartmentComparators.at(selection - 1));
        }
        catch (const out_of_range& exception) {
            cout << "Выход из меню сортировки квартир" << endl;
        }
    }
}
