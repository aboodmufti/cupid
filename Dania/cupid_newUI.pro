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
    database/storage.cpp \
    entity/Administrator.cpp \
    entity/Project.cc \
    entity/Student.cpp \
    entity/StudentProfile.cc \
    entity/User.cpp \
    adminstudentprofilepage.cpp \
    ProfileSubsystem/profilemanager.cpp \
    ProfileSubsystem/adminstudentprofilepage.cpp \
    ProfileSubsystem/editprofilepage.cpp \
    ProfileSubsystem/studentprofilepage.cpp \
    StorageSubsystem/Administrator.cpp \
    StorageSubsystem/Project.cc \
    StorageSubsystem/storage.cpp \
    StorageSubsystem/Student.cpp \
    StorageSubsystem/StudentProfile.cc \
    StorageSubsystem/Team.cpp \
    StorageSubsystem/User.cpp \
    ProfileSubsystem/studentloginpage.cpp \
    ProfileSubsystem/welcomepage.cpp \
    ProfileSubsystem/studentprojectspage.cpp

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
    database/storage.h \
    entity/Administrator.h \
    entity/Project.h \
    entity/Student.h \
    entity/StudentProfile.h \
    entity/User.h \
    entity/EntityDef.h \
    adminstudentprofilepage.h \
    ProfileSubsystem/profilemanager.h \
    ProfileSubsystem/adminstudentprofilepage.h \
    ProfileSubsystem/editprofilepage.h \
    ProfileSubsystem/studentprofilepage.h \
    StorageSubsystem/Administrator.h \
    StorageSubsystem/EntityDef.h \
    StorageSubsystem/Project.h \
    StorageSubsystem/storage.h \
    StorageSubsystem/Student.h \
    StorageSubsystem/StudentProfile.h \
    StorageSubsystem/Team.hpp \
    StorageSubsystem/User.h \
    ProfileSubsystem/studentloginpage.h \
    ProfileSubsystem/welcomepage.h \
    ProfileSubsystem/studentprojectspage.h

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
    adminstudentprofilepage.ui \
    ProfileSubsystem/adminstudentprofilepage.ui \
    ProfileSubsystem/editprofilepage.ui \
    ProfileSubsystem/studentprofilepage.ui \
    ProfileSubsystem/studentloginpage.ui \
    ProfileSubsystem/welcomepage.ui \
    ProfileSubsystem/studentprojectspage.ui

OTHER_FILES += \
    cupid_newUI.pro.user
