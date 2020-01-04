#include <objectwheel.h>
#include <QUrl>

Objectwheel::Objectwheel(QObject* parent) : QObject(parent)
{
}

QString Objectwheel::toLocalFile(const QUrl& url) const
{
    return url.toLocalFile();
}
