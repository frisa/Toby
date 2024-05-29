#include "sensor.hpp"

QString SensorModel::getIp() const
{
    return m_ip;
}

void SensorModel::setIp(const QString &value)
{
    m_ip = value;
    emit connectionChanged();
}

QString SensorModel::getPort() const
{
    return m_port;
}

void SensorModel::setPort(const QString &value)
{
    m_port = value;
    emit connectionChanged();
}

QString SensorModel::getLatitude() const
{
    return m_latitude;
}

void SensorModel::setLatitude(const QString &value)
{
    m_latitude = value;
    emit connectionChanged();
}

QString SensorModel::getLongitude() const
{
    return m_longitude;
}

void SensorModel::setLongitude(const QString &value)
{
    m_longitude = value;
    emit connectionChanged();
}

Q_INVOKABLE void SensorModel::Send()
{
    emit connectionChanged();
}

SensorModel::SensorModel(const QString &ip, const QString &port, const QString &latitude, const QString &longitude, QObject *parent)
{
    m_ip = ip;
    m_port = port;
    m_latitude = latitude;
    m_longitude = longitude;
}

SensorModel::SensorModel(QObject *parent)
{
    m_ip = "";
    m_port = "";
    m_latitude = "";
    m_longitude = "";
}
