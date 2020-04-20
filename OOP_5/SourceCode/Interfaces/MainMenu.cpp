#include "MainMenu.hpp"

using namespace std;

map<int, function<void(map<int, list<Property*>>&)>> CreateMainMenu() {
    map<int, function<void(map<int, list<Property*>>&)>> mainMenu;
    mainMenu[1] = CreateFunctions::Add;
    mainMenu[2] = Remove;
    mainMenu[3] = Edit;
    mainMenu[4] = View;
    mainMenu[5] = Search;
    mainMenu[6] = Sort;
    return mainMenu;
}

void MainMenu(map<int, list<Property*>>& property) {
    auto mainMenu = CreateMainMenu();
    int selection = 0;
    while (true) {
        cout << "\n1 - Добавление"
        << "\n2 - Удаление"
        << "\n3 - Редактирование"
        << "\n4 - Просмотр"
        << "\n5 - Поиск"
        << "\n6 - Сортировка"
        << "\n7 - Завершить работу" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        try {
            mainMenu.at(selection)(property);
        }
        catch (const out_of_range& exception) {
            cout << "Завершение работы" << endl;
            throw 0;
        }
    }
}
