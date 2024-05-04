#include "logger.h"
#include <iostream>

void Logger::setLog(const QString &value)
{
    m_log = m_log + "\n" + value;
    emit logChanged();
}

Logger::Logger(QObject *parent): QObject(parent)
{
    Q_UNUSED(parent);
    m_log = "Logger started\nApplication started\n";
    emit logChanged();
}

QString Logger::getLog() const
{
    return m_log;
}
