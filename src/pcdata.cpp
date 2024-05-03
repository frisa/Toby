#include <../inc/pcdata.h>

PCData::PCData(QObject *parent)
{
    m_data << "Name1" << "Name2" << "Name3";
    m_data << "Value1" << "Value2" << "Value3";
}

int PCData::rowCount(const QModelIndex &parent) const
{
    return m_data.count();
}

QVariant PCData::data(const QModelIndex &index, int role) const
{
    return m_data[index.row()];
}

QHash<int, QByteArray> PCData::roleNames() const
{
    return QHash<int, QByteArray>();
}
