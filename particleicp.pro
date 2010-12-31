######################################################################
# Automatically generated by qmake (2.01a) ?? ???. 3 07:36:57 2010
######################################################################

CONFIG += QtSvg qwt debug silent warn_on
TEMPLATE = app
TRANSLATIONS += translations/particleicp_ru_RU.ts \
				translations/particleicp_fr_FR.ts
TARGET =
DEPENDPATH += . src ui src/histogram src/math src/reuseable src/spectrum
INCLUDEPATH += . src src/reuseable src/spectrum src/histogram src/math

# Input
HEADERS += src/editmenu.h \
		   src/jycomposer.h \
           src/jyparser.h \
           src/mainwindow.h \
           src/parsersettingsdialog.h \
           src/histogram/histogramwindow.h \
           src/histogram/hnywindow.h \
           src/math/edittable.h \
           src/reuseable/dmenu.h \
           src/reuseable/dmenu_p.h \
		   src/reuseable/exportplotimage.h \
           src/reuseable/falgorithms.h \
           src/reuseable/history.h \
		   src/reuseable/plotrect.h \
           src/reuseable/rangebox.h \
		   src/reuseable/rescaledialog.h \
           src/reuseable/selectrecentmenu.h \
           src/reuseable/selectrecentmenu_p.h \
           src/reuseable/settings.h \
           src/reuseable/vectortable.h \
           src/reuseable/windowmenu.h \
           src/reuseable/windowmenu_p.h \
		   src/signals/signalswindow.h \
           src/spectrum/curvesettings.h \
           src/spectrum/spectrumsettings.h \
           src/spectrum/spectrumsettingswizard.h \
           src/spectrum/spectrumwindow.h
FORMS += ui/curvesettings.ui \
         ui/mainwindow.ui \
		 ui/histogram.ui \
		 ui/hny.ui \
         ui/parsersettingsdialog.ui \
		 ui/rescaledialog.ui \
		 ui/signalswindow.ui \
         ui/spectrumsettings.ui \
		 ui/spectrumwindow.ui
SOURCES += src/editmenu.cpp \
		   src/jycomposer.cpp \
           src/jyparser.cpp \
           src/main.cpp \
           src/mainwindow.cpp \
           src/parsersettingsdialog.cpp \
           src/histogram/histogramwindow.cpp \
           src/histogram/hnywindow.cpp \
           src/math/correcttable.cpp \
           src/math/cuttable.cpp \
           src/math/filtertable.cpp \
           src/reuseable/dmenu.cpp \
           src/reuseable/dmenu_p.cpp \
		   src/reuseable/exportplotimage.cpp \
           src/reuseable/history.cpp \
		   src/reuseable/plotrect.cpp \
           src/reuseable/rangebox.cpp \
		   src/reuseable/rescaledialog.cpp \
           src/reuseable/selectrecentmenu.cpp \
           src/reuseable/selectrecentmenu_p.cpp \
           src/reuseable/settings.cpp \
           src/reuseable/vectortable.cpp \
           src/reuseable/windowmenu.cpp \
           src/reuseable/windowmenu_p.cpp \
		   src/signals/signalswindow.cpp \
           src/spectrum/curvesettings.cpp \
           src/spectrum/spectrumsettings.cpp \
           src/spectrum/spectrumsettingswizard.cpp \
           src/spectrum/spectrumwindow.cpp

LIBS += -lgmp
