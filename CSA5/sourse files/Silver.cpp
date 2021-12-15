#include "Silver.h"

//------------------------------------------------------------------------------
// Конструктор для случайной генерации карты по заданному размеру карты.
Silver::Silver(int mapSize) {
    int treasureCoordinates = rand() % mapSize;
    map_ = new bool[mapSize];
    for (int i = 0; i < mapSize; ++i) {
        map_[i] = i == treasureCoordinates ? true : false;
    }
    searchResults_ = new bool[mapSize];
    mapSize_ = mapSize;
    currentPlaceCoordinate_ = -1;
}

//------------------------------------------------------------------------------
// Конструктор для создания карты из файла.
Silver::Silver(std::ifstream& ifst) {
    bool mapHasTreasure = false;
    bool k;
    std::vector<bool> vectorMap;
    while (!ifst.eof()) {
        ifst >> k;
        if (mapHasTreasure && k) {
            throw std::invalid_argument("Map has two or more treasure!");
        }
        mapHasTreasure = mapHasTreasure || k;
        vectorMap.push_back(k);
    }

    if (!mapHasTreasure) {
        throw std::invalid_argument("Map does not have treasure!");
    }

    mapSize_ = vectorMap.size();
    map_ = new bool[mapSize_];

    for (int i = 0; i < mapSize_; ++i) {
        map_[i] = vectorMap[i];
    }

    searchResults_ = new bool[mapSize_];

    currentPlaceCoordinate_ = -1;
}

//------------------------------------------------------------------------------
// Метод для получения следующего участка для поиска на карте.
int Silver::GetNextPlaceCoordinates() {
    std::lock_guard<std::mutex> locked(place_mutex);
    if (currentPlaceCoordinate_ + 1 < mapSize_) {
        return ++currentPlaceCoordinate_;
    }
    throw std::out_of_range("Map explored");
}

//------------------------------------------------------------------------------
// Метод для получения карты.
bool* Silver::GetMap() {
    return map_;
}

//------------------------------------------------------------------------------
// Метод для сохранения результатов поиска.
void Silver::SaveSearchResult(bool result, int coordinates) {
    searchResults_[coordinates] = result;
}

//------------------------------------------------------------------------------
// Метод для получения координат сокровища после окончания поиска.
int Silver::GetTreasureCoordinates() {
    for(int i = 0; i<mapSize_; ++i){
        if(searchResults_[i]){
            return i;
        }
    }
    return -1;
}

//------------------------------------------------------------------------------
// Метод для получения размера карты.
int Silver::GetMapSize() {
    return mapSize_;
}

//------------------------------------------------------------------------------
// Метод для сохранения результатов поиска в файл.
void Silver::SaveResultToFile(std::ofstream& ofst) {
    ofst << "Treasure coordinates: " << GetTreasureCoordinates() << std::endl;
    ofst << "Map:" << std::endl;
    for (int i = 0; i < mapSize_; i++) {
        ofst << i << ": " << map_[i] << std::endl;
    }
}