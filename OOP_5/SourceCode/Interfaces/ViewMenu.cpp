#include "ViewMenu.hpp"

using namespace std;

void View(map<int, list<Property*>>& property) {
    int seleciton = 0;
    while (true) {
        cout << "\n1 - Просмотреть дома"
        << "\n2 - Просмотреть квартиры"
        << "\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> seleciton;
        switch (seleciton) {
            case 1:
                ViewProperty(property.at(HOUSES));
                break;
            case 2:
                ViewProperty(property.at(APARTMENTS));
                break;
            case 3: default:
                cout << "Выход из меню просмотра" << endl;
                return;
        }
    }
}

void ViewProperty(list<Property*>& property) {
    for (auto& object : property) {
        object->printInformation();
    }
}
