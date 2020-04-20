#include "EditMenu.hpp"

using namespace std;
using namespace CommonEditFuncitons;

map<int, function<void(list<Property*>&)>> CreateEditMenu() {
    map<int, function<void(list<Property*>&)>> editMenu;
    editMenu[1] = EditHouses;
    editMenu[2] = EditApartments;
    return editMenu;
}

map<int, function<void(Property&)>> CreateEditHouseMenu() {
    using namespace HouseEditFunctions;
    map<int, function<void(Property&)>> editHouseMenu;
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

map<int, function<void(Property&)>> CreateEditApartmentMenu() {
    using namespace ApartmentEditFunctions;
    map<int, function<void(Property&)>> editApartmentMenu;
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
                cout << "Введите индекс дома для редатирования: ";
                cin >> index;
                cin.ignore();
                if (index < 0 or index >= houses.size()) {
                    cout << "Ошибка: выход за границы диапазона" << endl;
                }
                else {
                    EditHouse(ToHouse(*(next(houses.begin(), index))));
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
                cout << "Введите индекс квартиры для редатирования: ";
                cin >> index;
                cin.ignore();
                if (index < 0 or index >= apartments.size()) {
                    cout << "Ошибка: выход за границы диапазона" << endl;
                }
                else {
                    EditApartment(ToApartment(*(next(apartments.begin(), index))));
                }
                break;
            case 2: default:
                cout << "Выход из меню редактирования квартиры" << endl;
                return;
        }
    }
}

void EditHouse(House& house) {
    
}

void EditApartment(Apartment& apartment) {
    
}

void CommonEditFuncitons::EditCost(Property& property) {
    
}

void CommonEditFuncitons::EditType(Property& property) {
    
}

void CommonEditFuncitons::EditLocation(Property& property) {
    
}

void CommonEditFuncitons::EditCommonArea(Property& property) {
    
}

void CommonEditFuncitons::EditLivingArea(Property& property) {
    
}

void CommonEditFuncitons::EditKitchenArea(Property& property) {
    
}

void CommonEditFuncitons::EditAdditionalInformation(Property& property) {
    
}

void CommonEditFuncitons::EditNotes(Property& property) {
    
}


void HouseEditFunctions::EditLandArea(Property& house) {
    
}

void HouseEditFunctions::EditLevelsAmount(Property& house) {
    
}

void HouseEditFunctions::EditWallsMaterial(Property& house) {
    
}

void HouseEditFunctions::EditRoofMaterial(Property& house) {
    
}

void HouseEditFunctions::EditHeating(Property& house) {
    
}

void HouseEditFunctions::EditElectricity(Property& house) {
    
}

void HouseEditFunctions::EditGas(Property& house) {
    
}

void HouseEditFunctions::EditWaterSupply(Property& house) {
    
}

void ApartmentEditFunctions::EditRoomsAmount(Property& apartment) {
    
}

void ApartmentEditFunctions::EditHouseType(Property& apartment) {
    
}

void ApartmentEditFunctions::EditCeilingHeight(Property& apartment) {
    
}

void ApartmentEditFunctions::EditBuildingYear(Property& apartment) {
    
}

void ApartmentEditFunctions::EditBalcony(Property& apartment) {
    
}

void ApartmentEditFunctions::EditPhone(Property& apartment) {
    
}

void ApartmentEditFunctions::EditRepair(Property& apartment) {
    
}
