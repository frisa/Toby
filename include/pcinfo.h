#include <QObject>
#include <QString>

class PCInfo: public QObject
{
    Q_OBJECT
    QString getHostname() const;
    Q_PROPERTY(QString hostname READ getHostname NOTIFY hostnameChanged)
public:
    explicit PCInfo(QObject *parent = nullptr);
signals:
    void hostnameChanged();

};