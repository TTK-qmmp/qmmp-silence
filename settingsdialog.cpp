#include "settingsdialog.h"
#include "silenceplugin.h"

#include <QSettings>
#include <QAbstractButton>

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
{
    m_ui.setupUi(this);
#ifdef Q_OS_UNIX
    for(QAbstractButton *button : m_ui.buttonBox->buttons())
    {
        button->setFocusPolicy(Qt::NoFocus);
    }
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    QSettings settings;
#else
    QSettings settings(Qmmp::configFile(), QSettings::IniFormat);
#endif
    m_ui.value->setValue(settings.value("Silence/threshold", -40).toDouble());
}

void SettingsDialog::accept()
{
    const double value = m_ui.value->value();
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    QSettings settings;
#else
    QSettings settings(Qmmp::configFile(), QSettings::IniFormat);
#endif
    settings.setValue("Silence/threshold", value);

    if(SilencePlugin::instance())
    {
        SilencePlugin::instance()->setThreshold(value);
    }
    QDialog::accept();
}
