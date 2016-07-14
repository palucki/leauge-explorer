#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <string>
#include <iostream>

class Logger
{
public:
    static Logger& getInstance();
    ~Logger();
    void logQuery(QString executedQuery, QString file, int line);

private:
    Logger();
    std::string logFileName;
};

#endif // LOGGER_H
