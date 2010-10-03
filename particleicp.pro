######################################################################
# Automatically generated by qmake (2.01a) ?? ???. 4 01:03:56 2010
######################################################################

CONFIG += qt debug
TEMPLATE = app
TARGET = 
DEPENDPATH += . 3rdparty src ui src/reuseable src/spectrumwindow
INCLUDEPATH += . 3rdparty src src/reuseable src/spectrumwindow

# Input
HEADERS += 3rdparty/qtwindowlistmenu.h \
           src/jyparser.h \
           src/mainwindow.h \
           src/parsersettingsdialog.h \
           src/settings.h \
           src/reuseable/abstracttable.h \
           src/reuseable/falgorithms.h \
           src/reuseable/history.h \
           src/reuseable/jytable.h \
           src/reuseable/pointf.h \
           src/reuseable/polygon.h \
           src/reuseable/rofselector.h \
           src/spectrumwindow/dispensationwindow.h \
           src/spectrumwindow/reportwindow.h \
           src/spectrumwindow/spectrumsettingsdialog.h \
           src/spectrumwindow/spectrumwindow.h
FORMS += ui/mainwindow.ui \
         ui/parsersettingsdialog.ui \
         ui/spectrumsettingsdialog.ui
SOURCES += 3rdparty/qtwindowlistmenu.cpp \
           src/jyparser.cpp \
           src/main.cpp \
           src/mainwindow.cpp \
           src/parsersettingsdialog.cpp \
           src/settings.cpp \
           src/reuseable/abstracttable.cpp \
           src/reuseable/falgorithms.cpp \
           src/reuseable/history.cpp \
           src/reuseable/jytable.cpp \
           src/reuseable/pointf.cpp \
           src/reuseable/polygon.cpp \
           src/reuseable/rofselector.cpp \
           src/spectrumwindow/dispensationwindow.cpp \
           src/spectrumwindow/reportwindow.cpp \
           src/spectrumwindow/spectrumsettingsdialog.cpp \
           src/spectrumwindow/spectrumwindow.cpp
LIBS += -lqwt
