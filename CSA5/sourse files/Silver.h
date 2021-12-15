#ifndef UNTITLED19_SILVER_H
#define UNTITLED19_SILVER_H

#include <mutex>
#include <fstream>
#include <cstdlib>
#include <vector>

// Класс пирата сильвера, который командует поиском.
// Он хранит карту и результаты поиска, а также раздает задания в виде координат для посика.
class Silver {
public:
    // Конструктор для случайной генерации карты по заданному размеру карты.
    Silver(int mapSize);

    // Конструктор для создания карты из файла.
    Silver(std::ifstream& ifst);

    // Метод для получения следующего участка для поиска на карте.
    int GetNextPlaceCoordinates();

    // Метод для получения карты.
    bool* GetMap();

    // Метод для сохранения результатов поиска.
    void SaveSearchResult(bool result, int coordinates);

    // Метод для получения координат сокровища после окончания поиска.
    int GetTreasureCoordinates();

    // Метод для получения размера карты.
    int GetMapSize();

    // Метод для сохранения результатов поиска в файл.
    void SaveResultToFile(std::ofstream& ofst);

private:
    // Массив для хранения карты сокровищ.
    bool* map_;

    // Размер карты.
    int mapSize_;

    // Массив для сохранения результатов поиска.
    bool* searchResults_;

    // Переменная, которая хранит текущий исследуемый участок острова.
    int currentPlaceCoordinate_;

    // Мьютекс для блокировки получения координат следующего участка на карте одновременно несколькими потоками.
    std::mutex place_mutex;
};


#endif //UNTITLED19_SILVER_H
