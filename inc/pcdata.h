#include <QAbstractListModel>

class PCData : public QAbstractListModel
{
    Q_OBJECT
    QStringList m_data;
public: 
    enum Roles {
        NameRole = Qt::UserRole + 1,
        ValueRole
    };

    PCData(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
};