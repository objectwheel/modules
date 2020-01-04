#ifndef OBJECTWHEEL_H
#define OBJECTWHEEL_H

#include <QObject>

class Objectwheel : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Objectwheel)

public:
    explicit Objectwheel(QObject* parent = nullptr);

    QString toLocalFile(const QUrl& url) const;
};

#endif // OBJECTWHEEL_H
