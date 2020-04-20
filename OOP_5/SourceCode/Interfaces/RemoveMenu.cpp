#include "RemoveMenu.hpp"

using namespace std;

void Remove(map<int, list<Property*>>& property) {
    auto selection = 0;
    while (true) {
        cout << "\n1 - Удалить дом"
             << "\n2 - Удалить квартиру"
             << "\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        cin.ignore();
        switch (selection) {
            case 1:
                RemoveProperty(property[HOUSES]);
                break;
            case 2:
                RemoveProperty(property[APARTMENTS]);
                break;
            case 3: default:
                cout << "Выход из меню удаления" << endl;
                return;
        }
    }
}

void RemoveProperty(std::list<Property*>& property) {
    auto index = 0;
    cout << "Введите индекс объекта для удаления: ";
    cin >> index;
    cin.ignore();
    if (index < 0 || index >= property.size()) {
        cout << "Ошибка: выход за границы диапазона" << endl;
    }
    else {
        property.erase(next(property.begin(), index));
    }
}
