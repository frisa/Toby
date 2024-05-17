#include "sensor.hpp"
#include "sensor.grpc.pb.h"

QString Sensor::getIp() const
{
    return m_ip;
}

void Sensor::setIp(const QString &value)
{
    m_ip = value;
    emit connectionChanged();
}

QString Sensor::getPort() const
{
    return m_port;
}

void Sensor::setPort(const QString &value)
{
    m_port = value;
    emit connectionChanged();
}

QString Sensor::getLatitude() const
{
    return m_latitude;
}

void Sensor::setLatitude(const QString &value)
{
    m_latitude = value;
    emit connectionChanged();
}

QString Sensor::getLongitude() const
{
    return m_longitude;
}

void Sensor::setLongitude(const QString &value)
{
    m_longitude = value;
    emit connectionChanged();
}

Sensor::Sensor(QObject *parent)
{
    m_ip = "192.168.0.1";
    m_port = "8080";
    m_latitude = "47.410967";
    m_longitude = "9.6271219";
}
