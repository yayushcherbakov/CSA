#include "Logger.h"

//------------------------------------------------------------------------------
// Метод записи сообщения в консоль с lock_guard для защиты от одновременной записи нескольких потоков.
void Logger::Log(std::string message) {
    std::lock_guard<std::mutex> locked(report_mutex);
    std::cout << message << std::endl;
}

//------------------------------------------------------------------------------
// Метод записи события пиратской группы в консоль с lock_guard для защиты от одновременной записи нескольких потоков.
void Logger::LogPirateGroupAction(int group, std::string action) {
    std::lock_guard<std::mutex> locked(report_mutex);
    std::cout << "Pirate group " << std::to_string(group) <<" " << action << std::endl;
}