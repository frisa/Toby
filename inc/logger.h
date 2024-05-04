#include <QObject>
#include <string>

class Logger : public QObject
{
    Q_OBJECT
public:
     Q_PROPERTY(QString log READ getLog WRITE setLog NOTIFY logChanged)
    explicit Logger(QObject *parent = nullptr);
    QString getLog() const;
    void setLog(const QString &value);

signals:
    void logChanged();
private:
    QString m_log;
};