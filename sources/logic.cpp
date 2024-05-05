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
    m_parameter1 = "GS05 243567";
    m_parameter2 = "0687B7D4-7C36-4048-8072-B2990BCC7FB4";
    m_number1 = 10;
}

//#include "logic.moc"
