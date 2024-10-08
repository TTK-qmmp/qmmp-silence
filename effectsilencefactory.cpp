#include "effectsilencefactory.h"
#include "silenceplugin.h"
#include "settingsdialog.h"

#include <QMessageBox>

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
const EffectProperties EffectSilenceFactory::properties() const
#else
EffectProperties EffectSilenceFactory::properties() const
#endif
{
    EffectProperties properties;
    properties.name = tr("Silence Removal Plugin");
    properties.shortName = "silence";
    properties.hasSettings = true;
    properties.hasAbout = true;
    return properties;
}

Effect *EffectSilenceFactory::create()
{
    return new SilencePlugin();
}

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
void EffectSilenceFactory::showSettings(QWidget *parent)
{
    (new SettingsDialog(parent))->show();
}
#else
QDialog *EffectSilenceFactory::createSettings(QWidget *parent)
{
    return new SettingsDialog(parent);
}
#endif

void EffectSilenceFactory::showAbout(QWidget *parent)
{
     QMessageBox::about(parent, tr("About Silence Removal Effect Plugin"),
                        tr("Qmmp Silence Removal Effect Plugin") + "\n" +
                        tr("Written by: Greedysky <greedysky@163.com>"));
}

QString EffectSilenceFactory::translation() const
{
    return QString();
}
