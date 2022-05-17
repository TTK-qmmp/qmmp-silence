include($$PWD/../../plugins.pri)

TARGET = $$PLUGINS_PREFIX/Effect/silence

HEADERS += silenceplugin.h \
           effectsilencefactory.h \
           settingsdialog.h

SOURCES += silenceplugin.cpp \
           effectsilencefactory.cpp \
           settingsdialog.cpp

FORMS += settingsdialog.ui

unix{
    target.path = $$PLUGIN_DIR/Effect
    INSTALLS += target
}
