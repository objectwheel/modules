#ifndef ANDROID_H
#define ANDROID_H

#include <QObject>

class QJSValue;
class Android : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Android)

public:
    enum PermissionResult {
        Granted,
        Denied
    };
    Q_ENUM(PermissionResult)

public:
    explicit Android(QObject* parent = nullptr);

    int androidSdkVersion() const;
    bool shouldShowRequestPermissionRationale(const QString& permission) const;
    PermissionResult checkPermission(const QString& permission) const;
    QJSValue requestPermissionsSync(const QStringList& permissions, int timeoutMs = INT_MAX) const;
    void requestPermissions(const QStringList& permissions, const QJSValue& callbackFunc) const;
};

#endif // ANDROID_H
