#include <QObject>
#include <QString>

class Logic: public QObject
{
    Q_OBJECT

    QString getParameter1() const;
    void setParameter1(const QString &value);

    QString getParameter2() const;
    void setParameter2(const QString &value);

    Q_PROPERTY(QString parameter1 READ getParameter1 WRITE setParameter1 NOTIFY parameterChanged1)
    Q_PROPERTY(QString parameter2 READ getParameter2 WRITE setParameter2 NOTIFY parameterChanged2)
public:
    explicit Logic(QObject *parent = nullptr);
signals:
    void parameterChanged1();
    void parameterChanged2();
private:
    QString m_parameter1;
    QString m_parameter2;
};