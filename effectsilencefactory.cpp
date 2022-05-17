#include "effectsilencefactory.h"
#include "silenceplugin.h"
#include "settingsdialog.h"

#include <QMessageBox>

const EffectProperties EffectSilenceFactory::properties() const
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

void EffectSilenceFactory::showSettings(QWidget *parent)
{
    (new SettingsDialog(parent))->show();
}

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
