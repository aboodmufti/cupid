#-------------------------------------------------
#
# Project created by QtCreator 2015-10-27T13:38:36
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cupid_newUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    adminloginpage.cpp \
    adminmainpage.cpp \
    createprojectpage.cpp \
    editprofilepage.cpp \
    editprojectpage.cpp \
    projectpage.cpp \
    studentloginpage.cpp \
    studentprofilepage.cpp \
    studentprojectspage.cpp \
    welcomepage.cpp \
    adminstudentprofilepage.cpp \
    StorageSubsystem/Administrator.cpp \
    StorageSubsystem/Project.cc \
    StorageSubsystem/storage.cpp \
    StorageSubsystem/Student.cpp \
    StorageSubsystem/StudentProfile.cc \
    StorageSubsystem/Team.cpp \
    StorageSubsystem/User.cpp

HEADERS  += mainwindow.h \
    adminloginpage.h \
    adminmainpage.h \
    createprojectpage.h \
    editprofilepage.h \
    editprojectpage.h \
    projectpage.h \
    studentloginpage.h \
    studentprofilepage.h \
    studentprojectspage.h \
    welcomepage.h \
    adminstudentprofilepage.h \
    old/Administrator.h \
    StorageSubsystem/User.h \
    StorageSubsystem/Administrator.h \
    StorageSubsystem/EntityDef.h \
    StorageSubsystem/Project.h \
    StorageSubsystem/storage.h \
    StorageSubsystem/Student.h \
    StorageSubsystem/StudentProfile.h \
    StorageSubsystem/Team.hpp

FORMS    += mainwindow.ui \
    adminloginpage.ui \
    adminmainpage.ui \
    createprojectpage.ui \
    editprofilepage.ui \
    editprojectpage.ui \
    projectpage.ui \
    studentloginpage.ui \
    studentprofilepage.ui \
    studentprojectspage.ui \
    welcomepage.ui \
    adminstudentprofilepage.ui

OTHER_FILES += \
    cupid_newUI.pro.user
