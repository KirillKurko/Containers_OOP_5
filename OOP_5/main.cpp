#include <iostream>
#include <map>
#include "list"
#include "Headers/Interfaces/MainMenu.hpp"
#include "Headers/Utilities/FileSystemManager.hpp"

using namespace std;

int main() {
    FileSystemManager fileSystemManager;
    map<int, list<Property*>> property;
    fileSystemManager.load(property);
    try {
        MainMenu(property);
    }
    catch (...) {
        fileSystemManager.save(property);
        return 0;
    }
}
