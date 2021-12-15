#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include "Logger.h"
#include "Silver.h"

//------------------------------------------------------------------------------
// Функция для мывода ошибки в случае некорректной команды.
void errMessageIncorrectComand() {
    std::cout << "incorrect command line!\n"
                 "  Waited:\n"
                 "     command -p pirateGroupCount -f infile outfile\n"
                 "  Or:\n"
                 "     command -p pirateGroupCount -n number outfile\n";
}

//------------------------------------------------------------------------------
// Функция для мывода ошибки в случае некорректной параметра.
void errMessageIncorrectQialifier() {
    std::cout << "incorrect qualifier value!\n"
                 "  Waited:\n"
                 "     command -p pirateGroupCount -f infile outfile\n"
                 "  Or:\n"
                 "     command -p pirateGroupCount -n number outfile\n";
}

//------------------------------------------------------------------------------
// Функция для запуска потока группы пиратов.
void PirateGroupWork(int pirateNumber, Silver* silver, Logger* logger) {
    logger->LogPirateGroupAction(pirateNumber, "started");
    try{
        while (true) {
            // Получение новых координат для поиска.
            int coordinates = silver->GetNextPlaceCoordinates();
            logger->LogPirateGroupAction(pirateNumber, "got new coordinates from Silver: " + std::to_string(coordinates));

            logger->LogPirateGroupAction(pirateNumber, "starting search on " + std::to_string(coordinates));
            bool* map = silver->GetMap();
            // Каждая группа пиратов выполняет поиск за 50 милисекунд(время засыпания потока).
            std::this_thread::sleep_for(std::chrono::milliseconds(50));

            // Сохраниние результатов поиска.
            silver->SaveSearchResult(map[coordinates], coordinates);
            logger->LogPirateGroupAction(pirateNumber, "saved results from " + std::to_string(coordinates));
        }
    }
    catch (std::out_of_range ex) {
        // Если в портфеле задач не осталось заданий будет выброшено исключение. На этом потом завершиет работу.
        logger->LogPirateGroupAction(pirateNumber, "ended work");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 6) {
        errMessageIncorrectComand();
        return 1;
    }

    std::cout << "Start" << std::endl;

    if (strcmp(argv[1], "-p")) {
        errMessageIncorrectComand();
        return 3;
    }

    int pirateGroupCount = 0;
    try {
        pirateGroupCount = atoi(argv[2]);
        if (pirateGroupCount < 1 || pirateGroupCount > 1000) {
            std::cout << "Pirates count must be from 1 to 1000";
            return 3;
        }
    }
    catch (const std::exception& e) {
        errMessageIncorrectComand();
        return 3;
    }

    std::cout << "Map is creating" << std::endl;
    Silver* silver;
    if (!strcmp(argv[3], "-f")) {
        std::ifstream ifst(argv[4]);
        try {
            silver = new Silver(ifst);
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
            std::cout << "Fix data model and try again";
            return 3;
        }
    }
    else if (!strcmp(argv[3], "-n")) {
        auto size = atoi(argv[4]);
        if ((size < 1) || (size > 10000)) {
            std::cout << "Incorrect size of map = "
                      << size
                      << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // Системные часы в качестве инициализатора.
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел.
        silver = new Silver(size);
    }
    else {
        errMessageIncorrectQialifier();
        return 2;
    }


    std::cout << "Map is created. Map size is " << silver->GetMapSize() << std::endl;

    // Логер для блокировки одновременной записи в консоль.
    Logger* logger = new Logger();

    std::cout << "Search is sorting" << std::endl;

    clock_t start = clock();

    // Создание потоков.
    std::vector<std::thread> threads;
    for (int i = 0; i < pirateGroupCount; ++i) {
        threads.emplace_back(std::thread(PirateGroupWork, i, silver, logger));
    }

    // Ожидание завершения всех потоков.
    for (std::thread& th : threads) {
        th.join();
    }

    // Логирование результатов.
    logger->Log("Treasure coordinates are " + std::to_string(silver->GetTreasureCoordinates()));
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    std::ofstream ofst(argv[5]);
    std::cout << "Search time: " << elapsed << std::endl;
    ofst << "Search time: " << elapsed << std::endl;
    std::cout << "Count of pirates group: " << pirateGroupCount << std::endl;
    ofst << "Count of pirates group: " << pirateGroupCount << std::endl;

    silver->SaveResultToFile(ofst);
    return 0;
}
