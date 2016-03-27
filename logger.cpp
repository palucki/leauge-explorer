#include "logger.h"
#include <iostream>
#include <fstream>
#include <QString>
#include <QDebug>
#include <ctime>
#include <sstream>
#include <iomanip>

Logger::Logger()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::stringstream ss;
    ss << "logs/SqlServer_"
       << ltm->tm_year+1900 << "_"
       << std::setfill('0') << std::setw(2)
       << ltm->tm_mon+1  << "_"
       << std::setfill('0') << std::setw(2)
       << ltm->tm_mday << "-"
       << std::setfill('0') << std::setw(2)
       << ltm->tm_hour << "-"
       << std::setfill('0') << std::setw(2)
       << ltm->tm_min  << "-"
       << std::setfill('0') << std::setw(2)
       << ltm->tm_sec << ".log";
    logFileName = ss.str();
}

Logger &Logger::getInstance()
{
    static Logger instance;
    return instance;
}

Logger::~Logger()
{
}

void Logger::log(QString executedQuery, QString file, int line)
{
    std::ofstream logFile;
    logFile.open(logFileName, std::ios::out | std::ios::app);
    if(logFile.is_open())
    {
        logFile << file.toStdString() << ":" << line << " ";
        logFile << executedQuery.toStdString() << std::endl;
    }
    else
        qDebug() << "Can't open file:" << QString::fromStdString(logFileName);
}

