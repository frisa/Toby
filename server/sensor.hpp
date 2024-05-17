#include <QObject>
#include <QString>

class Sensor: public QObject
{
    Q_OBJECT
    QString getIp() const;
    void setIp(const QString &value);

    QString getPort() const;
    void setPort(const QString &value);

    QString getLatitude() const;
    void setLatitude(const QString &value);

    QString getLongitude() const;
    void setLongitude(const QString &value);
public:
    Q_INVOKABLE void Send();

    Q_PROPERTY(QString ip READ getIp WRITE setIp NOTIFY connectionChanged)
    Q_PROPERTY(QString port READ getPort WRITE setPort NOTIFY connectionChanged)
    Q_PROPERTY(QString latitude READ getLatitude WRITE setLatitude NOTIFY connectionChanged)
    Q_PROPERTY(QString longitude READ getLongitude WRITE setLongitude NOTIFY connectionChanged)
public:
    explicit Sensor(QObject *parent = nullptr);
signals:
    void connectionChanged();
private:
    QString m_ip;
    QString m_port;
    QString m_latitude;
    QString m_longitude;
};