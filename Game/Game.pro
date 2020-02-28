TEMPLATE = app
TARGET = TheGame

QT += core gui widgets

CONFIG += c++14

SOURCES += \
    main.cpp \
    tiles/water.cpp \
    tiles/cornfield.cpp \
    tiles/rock.cpp \
    buildings/mine.cpp \
    buildings/boat.cpp \
    workers/miner.cpp \
    workers/saboteur.cpp \
    interfaces/gameeventhandler.cpp \
    interfaces/objectmanager.cpp \
    mainwindow.cpp \
    graphics/gamescene.cpp \
    graphics/mapitem.cpp \
    startdialog.cpp \
    guidedialog.cpp

HEADERS += \
    myresourcemaps.hh \
    tiles/water.hh \
    tiles/cornfield.hh \
    tiles/rock.hh \
    buildings/mine.hh \
    buildings/boat.hh \
    workers/miner.hh \
    workers/saboteur.hh \
    interfaces/gameeventhandler.hh \
    interfaces/objectmanager.hh \
    mainwindow.hh \
    graphics/gamescene.hh \
    graphics/mapitem.hh \
    startdialog.hh \
    guidedialog.hh

win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

FORMS += \
    mainwindow.ui \
    startdialog.ui \
    guidedialog.ui

RESOURCES += \
    resources.qrc
