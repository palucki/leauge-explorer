#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <string>

class Logger
{
public:
    static Logger& getInstance();
    ~Logger();
    void log(QString executedQuery, QString file, int line);
private:
    Logger();
    std::string logFileName;
};

#endif // LOGGER_H
