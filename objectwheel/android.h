#ifndef ANDROID_H
#define ANDROID_H

#include <QObject>
#include <QJSValue>

class QQmlEngine;
class Android : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Android)

public:
    enum PermissionResult {
        AccessGranted,
        AccessDenied
    };
    Q_ENUM(PermissionResult)

public:
    explicit Android(QQmlEngine* engine, QObject* parent = nullptr);

public slots:
    int androidSdkVersion() const;
    bool shouldShowRequestPermissionRationale(const QString& permission) const;
    PermissionResult checkPermission(const QString& permission) const;
    QJSValue requestPermissionsSync(const QStringList& permissions, int timeoutMs = INT_MAX) const;
    void requestPermissions(const QStringList& permissions, const QJSValue& callbackFunc) const;

private:
    QQmlEngine* m_engine;
};

#endif // ANDROID_H
