#ifndef UNTITLED19_LOGGER_H
#define UNTITLED19_LOGGER_H

#include <iostream>
#include <mutex>
#include <string>

//------------------------------------------------------------------------------
// Класс для записи сообщений в консоль с защитой от одновременной записи несколькими потоками.
class Logger {
public:
    // Метод записи сообщения в консоль.
    void Log(std::string message);

    // Метод записи события пиратской группы в консоль.
    void LogPirateGroupAction(int group, std::string action);

private:
    // Мьютекс для блокировки одновеременной записи в консоль.
    std::mutex report_mutex;
};


#endif //UNTITLED19_LOGGER_H
