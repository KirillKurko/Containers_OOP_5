#include "EditMenu.hpp"

using namespace std;
using namespace CommonEditFuncitons;

map<int, function<void(list<Property*>&)>> CreateEditMenu() {
    map<int, function<void(list<Property*>&)>> editMenu;
    editMenu[1] = EditHouses;
    editMenu[2] = EditApartments;
    return editMenu;
}

map<int, function<void(Property*)>> CreateEditHouseMenu() {
    using namespace HouseEditFunctions;
    map<int, function<void(Property*)>> editHouseMenu;
    editHouseMenu[1] = EditCost;
    editHouseMenu[2] = EditType;
    editHouseMenu[3] = EditLocation;
    editHouseMenu[4] = EditCommonArea;
    editHouseMenu[5] = EditLivingArea;
    editHouseMenu[6] = EditKitchenArea;
    editHouseMenu[7] = EditAdditionalInformation;
    editHouseMenu[8] = EditNotes;
    editHouseMenu[9] = EditLandArea;
    editHouseMenu[10] = EditLevelsAmount;
    editHouseMenu[11] = EditWallsMaterial;
    editHouseMenu[12] = EditRoofMaterial;
    editHouseMenu[13] = EditHeating;
    editHouseMenu[14] = EditElectricity;
    editHouseMenu[15] = EditGas;
    editHouseMenu[16] = EditWaterSupply;
    return editHouseMenu;
}

map<int, function<void(Property*)>> CreateEditApartmentMenu() {
    using namespace ApartmentEditFunctions;
    map<int, function<void(Property*)>> editApartmentMenu;
    editApartmentMenu[1] = EditCost;
    editApartmentMenu[2] = EditType;
    editApartmentMenu[3] = EditLocation;
    editApartmentMenu[4] = EditCommonArea;
    editApartmentMenu[5] = EditLivingArea;
    editApartmentMenu[6] = EditKitchenArea;
    editApartmentMenu[7] = EditAdditionalInformation;
    editApartmentMenu[8] = EditNotes;
    editApartmentMenu[9] = EditRoomsAmount;
    editApartmentMenu[10] = EditHouseType;
    editApartmentMenu[11] = EditCeilingHeight;
    editApartmentMenu[12] = EditBuildingYear;
    editApartmentMenu[13] = EditBalcony;
    editApartmentMenu[14] = EditPhone;
    editApartmentMenu[15] = EditRepair;
    return editApartmentMenu;
}

void Edit(map<int, list<Property*>>& property) {
    auto editMenu = CreateEditMenu();
    auto selection = 0;
    while (true) {
        cout << "\n1 - Редактировать дома"
             << "\n2 - Редактировать квартиры"
             << "\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        cin.ignore();
        try {
            editMenu.at(selection)(property[selection]);
        }
        catch (const out_of_range& exception) {
            cout << "Выход из меню редактирования" << endl;
            return;
        }
    }
}

void EditHouses(list<Property*>& houses) {
    auto index = 0;
    auto selection = 0;
    while (true) {
        cout << "\n1 - Редактировать дом по индексу\n2 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        cin.ignore();
        switch (selection) {
            case 1:
                cout << "Введите индекс дома для редактирования: ";
                cin >> index;
                cin.ignore();
                if (index < 0 or index >= houses.size()) {
                    cout << "Ошибка: выход за границы диапазона" << endl;
                }
                else {
                    EditHouse(*(next(houses.begin(), index)));
                }
                break;
            case 2: default:
                cout << "Выход из меню редактирования дома" << endl;
                return;
        }
    }
}

void EditApartments(list<Property*>& apartments) {
    auto index = 0;
    auto selection = 0;
    while (true) {
        cout << "\n1 - Редактировать квартиру по индексу\n2 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        cin.ignore();
        switch (selection) {
            case 1:
                cout << "Введите индекс квартиры для редактирования: ";
                cin >> index;
                cin.ignore();
                if (index < 0 or index >= apartments.size()) {
                    cout << "Ошибка: выход за границы диапазона" << endl;
                }
                else {
                    EditApartment(*(next(apartments.begin(), index)));
                }
                break;
            case 2: default:
                cout << "Выход из меню редактирования квартиры" << endl;
                return;
        }
    }
}

void EditHouse(Property* house) {
    auto editHouseMenu = CreateEditHouseMenu();
    auto selection = 0;
    while (true) {
        cout << "\n1 - Редактировать стоимость"
             << "\n2 - Редактировать тип"
             << "\n3 - Редактировать месторасположение"
             << "\n4 - Редактировать общую площадь"
             << "\n5 - Редактировать жилую площадь"
             << "\n6 - Редактировать площадь кухни"
             << "\n7 - Редактировать допольнительную информацию"
             << "\n8 - Редактировать примечания"
             << "\n9 - Редактировать площадь участка"
             << "\n10 - Редактировать количество уровней"
             << "\n11 - Редактировать материал стен"
             << "\n12 - Редактировать материал крыши"
             << "\n13 - Редактировать отопление"
             << "\n14 - Редактировать электричество"
             << "\n15 - Редактировать газ"
             << "\n16 - Редактировать водоснабжение"
             << "\n17 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        cin.ignore();
        try {
            editHouseMenu.at(selection)(house);
        }
        catch (const out_of_range& exception) {
            cout << "Редактирование дома завершено" << endl;
            return;
        }
    }
}

void EditApartment(Property* apartment) {
    auto editApartmentMenu = CreateEditApartmentMenu();
    auto selection = 0;
    while (true) {
        cout << "\n1 - Редактировать стоимость"
        << "\n2 - Редактировать тип"
        << "\n3 - Редактировать месторасположение"
        << "\n4 - Редактировать общую площадь"
        << "\n5 - Редактировать жилую площадь"
        << "\n6 - Редактировать площадь кухни"
        << "\n7 - Редактировать допольнительную информацию"
        << "\n8 - Редактировать примечания"
        << "\n9 - Редактировать количество комнат"
        << "\n10 - Редактировать тип дома"
        << "\n11 - Редактировать высоту потолков"
        << "\n12 - Редактировать год постройки"
        << "\n13 - Редактировать балкон"
        << "\n14 - Редактировать телефон"
        << "\n15 - Редактировать ремонт"
        << "\n16 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        cin.ignore();
        try {
            editApartmentMenu.at(selection)(apartment);
        }
        catch (const out_of_range& exception) {
            cout << "Редактирование квартиры завершено" << endl;
            return;
        }
    }
}

void CommonEditFuncitons::EditCost(Property* property) {
    double cost = 0.0;
    cout << "Введите новое значение стоимости: ";
    cin >> cost;
    cin.ignore();
    property->setCost(cost);
}

void CommonEditFuncitons::EditType(Property* property) {
    string type;
    cout << "Введите новое значение типа: ";
    getline(cin, type);
    property->setType(type);
}

void CommonEditFuncitons::EditLocation(Property* property) {
    string location;
    cout << "Введите новое значение месторасположения: ";
    getline(cin, location);
    property->setLocation(location);
}

void CommonEditFuncitons::EditCommonArea(Property* property) {
    auto area = property->getArea();
    double commonArea = 0.0;
    cout << "Введите новое значение общей площади: ";
    cin >> commonArea;
    cin.ignore();
    area.setCommon(commonArea);
    property->setArea(area);
}

void CommonEditFuncitons::EditLivingArea(Property* property) {
    auto area = property->getArea();
    double livingArea = 0.0;
    cout << "Введите новое значение жилой площади: ";
    cin >> livingArea;
    cin.ignore();
    area.setLiving(livingArea);
    property->setArea(area);
}

void CommonEditFuncitons::EditKitchenArea(Property* property) {
    auto area = property->getArea();
    double kitchenArea = 0.0;
    cout << "Введите новое значение площади кухни: ";
    cin >> kitchenArea;
    cin.ignore();
    area.setKitchen(kitchenArea);
    property->setArea(area);
}

void CommonEditFuncitons::EditAdditionalInformation(Property* property) {
    string additionalInformation;
    cout << "Введите новое значение допольнительной информации: ";
    getline(cin, additionalInformation);
    property->setAdditionalInformation(additionalInformation);
}

void CommonEditFuncitons::EditNotes(Property* property) {
    string notes;
    cout << "Введите новое значение примечаний: ";
    getline(cin, notes);
    property->setNotes(notes);
}


void HouseEditFunctions::EditLandArea(Property* house) {
    double landArea = 0.0;
    cout << "Введите новое значение площади участка: ";
    cin >> landArea;
    cin.ignore();
    ToHouse(house).setLandArea(landArea);
}

void HouseEditFunctions::EditLevelsAmount(Property* house) {
    auto levelsAmount = 0;
    cout << "Введите новое значение количества уровней: ";
    cin >> levelsAmount;
    cin.ignore();
    ToHouse(house).setLevelsAmount(levelsAmount);
}

void HouseEditFunctions::EditWallsMaterial(Property* house) {
    string wallsMaterial;
    cout << "Введите новое значение материала стен: ";
    getline(cin, wallsMaterial);
    ToHouse(house).setWallsMaterial(wallsMaterial);
}

void HouseEditFunctions::EditRoofMaterial(Property* house) {
    string roofMaterial;
    cout << "Введите новое значение материала крыши: ";
    getline(cin, roofMaterial);
    ToHouse(house).setRoofMaterial(roofMaterial);
}

void HouseEditFunctions::EditHeating(Property* house) {
    bool heating = false;
    cout << "Введите новое значение отопления: ";
    cin >> heating;
    cin.ignore();
    ToHouse(house).setHeating(heating);
}

void HouseEditFunctions::EditElectricity(Property* house) {
    bool electricity = false;
    cout << "Введите новое значение электричества: ";
    cin >> electricity;
    cin.ignore();
    ToHouse(house).setElectricity(electricity);
}

void HouseEditFunctions::EditGas(Property* house) {
    bool gas = false;
    cout << "Введите новое значение газа: ";
    cin >> gas;
    cin.ignore();
    ToHouse(house).setGas(gas);
}

void HouseEditFunctions::EditWaterSupply(Property* house) {
    bool waterSupply = false;
    cout << "Введите новое значение водоснабжения: ";
    cin >> waterSupply;
    cin.ignore();
    ToHouse(house).setWaterSupply(waterSupply);
}

void ApartmentEditFunctions::EditRoomsAmount(Property* apartment) {
    auto roomsAmount = 0;
    cout << "Введите новое значение количества комнат: ";
    cin >> roomsAmount;
    cin.ignore();
    ToApartment(apartment).setRoomsAmount(roomsAmount);
}

void ApartmentEditFunctions::EditHouseType(Property* apartment) {
    string houseType;
    cout << "Введите новое значение типа дома: ";
    getline(cin, houseType);
    ToApartment(apartment).setHouseType(houseType);
}

void ApartmentEditFunctions::EditCeilingHeight(Property* apartment) {
    double ceilingHeight = 0.0;
    cout << "Введите новое значение высоты потолков: ";
    cin >> ceilingHeight;
    cin.ignore();
    ToApartment(apartment).setCeilingHeight(ceilingHeight);
}

void ApartmentEditFunctions::EditBuildingYear(Property* apartment) {
    auto buildingYear = 0;
    cout << "Введите новое значение года постройки: ";
    cin >> buildingYear;
    cin.ignore();
    ToApartment(apartment).setBulidingYear(buildingYear);
}

void ApartmentEditFunctions::EditBalcony(Property* apartment) {
    bool balcony = false;
    cout << "Введите новое значение балкона: ";
    cin >> balcony;
    cin.ignore();
    ToApartment(apartment).setBalcony(balcony);
}

void ApartmentEditFunctions::EditPhone(Property* apartment) {
    bool phone = false;
    cout << "Введите новое значение телефона: ";
    cin >> phone;
    cin.ignore();
    ToApartment(apartment).setPhone(phone);
}

void ApartmentEditFunctions::EditRepair(Property* apartment) {
    string repair;
    cout << "Введите новое значение ремонта: ";
    getline(cin, repair);
    ToApartment(apartment).setRepair(repair);
}
