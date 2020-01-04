#include <android.h>
#include <QHash>
#include <QQmlEngine>

#if defined(Q_OS_ANDROID)
#include <QtAndroid>
#endif

#if defined(Q_OS_ANDROID)
static QJSValue mapToJSObject(QQmlEngine* engine, const QtAndroid::PermissionResultMap& resultMap)
{
    QJSValue object = engine->newObject();
    foreach (const QString& key, resultMap.keys())
        object.setProperty(key, (Android::PermissionResult) resultMap.value(key));
    return object;
}
#endif

Android::Android(QQmlEngine* engine, QObject* parent) : QObject(parent)
  , m_engine(engine)
{
}

int Android::androidSdkVersion() const
{
#if defined(Q_OS_ANDROID)
    return QtAndroid::androidSdkVersion();
#else
    qWarning("Android.androidSdkVersion: This function is only available Android!");
    return -1;
#endif
}

bool Android::shouldShowRequestPermissionRationale(const QString& permission) const
{
#if defined(Q_OS_ANDROID)
    return QtAndroid::shouldShowRequestPermissionRationale(permission);
#else
    Q_UNUSED(permission)
    qWarning("Android.shouldShowRequestPermissionRationale: This function is only available Android!");
    return false;
#endif
}

Android::PermissionResult Android::checkPermission(const QString& permission) const
{
#if defined(Q_OS_ANDROID)
    return (PermissionResult) QtAndroid::checkPermission(permission);
#else
    Q_UNUSED(permission)
    qWarning("Android.checkPermission: This function is only available Android!");
    return Denied;
#endif
}

QJSValue Android::requestPermissionsSync(const QStringList& permissions, int timeoutMs) const
{
#if defined(Q_OS_ANDROID)
    return mapToJSObject(m_engine, QtAndroid::requestPermissionsSync(permissions, timeoutMs));
#else
    Q_UNUSED(permissions)
    Q_UNUSED(timeoutMs)
    qWarning("Android.requestPermissionsSync: This function is only available Android!");
    return QJSValue();
#endif
}

void Android::requestPermissions(const QStringList& permissions, const QJSValue& callbackFunc) const
{
#if defined(Q_OS_ANDROID)
    const QtAndroid::PermissionResultCallback& callback =
            [=] (const QtAndroid::PermissionResultMap& resultMap) mutable {
        const_cast<QJSValue&>(callbackFunc).call({mapToJSObject(m_engine, resultMap)});
    };
    QtAndroid::requestPermissions(permissions, callback);
#else
    Q_UNUSED(permissions)
    Q_UNUSED(callbackFunc)
    qWarning("Android.requestPermissions: This function is only available Android!");
#endif
}
