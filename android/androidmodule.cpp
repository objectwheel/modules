#include <android.h>
#include <QQmlEngine>
#include <QQmlExtensionPlugin>

class AndroidModule final : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_DISABLE_COPY(AndroidModule)
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    AndroidModule(QObject* parent = nullptr) : QQmlExtensionPlugin(parent) {}

    void registerTypes(const char* uri) override
    {
        Q_ASSERT(QLatin1String(uri) == QLatin1String("Objectwheel.Android"));

        const int major = OW_MODULE_VERSION_MAJOR;
        const int minor = OW_MODULE_VERSION_MINOR;

        // 1.0 types
        qmlRegisterSingletonType<Android>(uri, major, minor, Android::staticMetaObject.className(),
                                          [] (QQmlEngine* e, QJSEngine*) -> QObject* {
            return new Android(e, e);
        });

        qmlRegisterModule(uri, major, minor);
    }
};

#include "androidmodule.moc"
