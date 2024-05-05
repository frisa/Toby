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

int Logic::getNumber1() const
{
    return m_number1;
}

void Logic::setNumber1(const int &value)
{
    m_number1 = value;
    emit numberChanged1();
}

Logic::Logic(QObject *parent)
{
    m_parameter1 = "value 1";
    m_parameter2 = "value 2";
    m_number1 = 42;
}

//#include "logic.moc"
