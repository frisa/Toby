#include <QObject>
#include <QString>

class Logic: public QObject
{
    Q_OBJECT

    QString getParameter1() const;
    void setParameter1(const QString &value);

    QString getParameter2() const;
    void setParameter2(const QString &value);

    int getNumber1() const;
    void setNumber1(const int &value);

    double getLatitude() const;
    double getLongitude() const;
public:
    void setLatitude(double value);
    void setLongitude(double value);

    Q_PROPERTY(QString parameter1 READ getParameter1 WRITE setParameter1 NOTIFY parameterChanged1)
    Q_PROPERTY(QString parameter2 READ getParameter2 WRITE setParameter2 NOTIFY parameterChanged2)
    Q_PROPERTY(int number1 READ getNumber1 WRITE setNumber1 NOTIFY numberChanged1)

    Q_PROPERTY(double latitude READ getLatitude WRITE setLatitude NOTIFY positionChanged)
    Q_PROPERTY(double longitude READ getLongitude WRITE setLongitude NOTIFY positionChanged)
public:
    explicit Logic(QObject *parent = nullptr);
    Q_INVOKABLE void getSensorDataCmd();
signals:
    void parameterChanged1();
    void parameterChanged2();
    void numberChanged1();
    void positionChanged();
    void getSensorData();
private:
    QString m_parameter1;
    QString m_parameter2;
    int m_number1;
    double m_latitude;
    double m_longitude;
};