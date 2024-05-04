#include "logic.h"

QString Logic::getParameter1() const
{
    return m_parameter1;
}

void Logic::setParameter1(const QString &value)
{
    m_parameter1 = value;
    emit parameterChanged1();
}

QString Logic::getParameter2() const
{
    return m_parameter2;
}

void Logic::setParameter2(const QString &value)
{
    m_parameter2 = value;
    emit parameterChanged2();
}

Logic::Logic(QObject *parent)
{
    m_parameter1 = "Hello 1 from Logic!";
    m_parameter2 = "Hello 2 from Logic!";
}

//#include "logic.moc"
