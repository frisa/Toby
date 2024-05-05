#include "pcinfo.h"
#include <unistd.h>

QString PCInfo::getHostname() const
{
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == 0)
    {
        return QString(hostname);
    }
    return QString();
}

PCInfo::PCInfo(QObject *parent)
    : QObject(parent)
{
}
