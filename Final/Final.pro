#-------------------------------------------------
#
# Project created by QtCreator 2015-12-03T19:29:34
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Final
TEMPLATE = app


SOURCES += main.cpp\
    Algorithm/algorithmmanager.cpp \
    Algorithm/algorithmsummary.cpp \
    StorageSubsystem/Administrator.cpp \
    StorageSubsystem/Project.cc \
    StorageSubsystem/storage.cpp \
    StorageSubsystem/Student.cpp \
    StorageSubsystem/StudentProfile.cc \
    StorageSubsystem/Team.cpp \
    StorageSubsystem/User.cpp \
    ProfileSubsystem/editprofilepage.cpp \
    ProfileSubsystem/profilemanager.cpp \
    ProfileSubsystem/studentloginpage.cpp \
    ProfileSubsystem/studentprofilepage.cpp \
    ProfileSubsystem/studentprojectspage.cpp \
    ProjectSubsystem/adminmainpage.cpp \
    ProjectSubsystem/adminstudentprofilepage.cpp \
    ProjectSubsystem/createprojectpage.cpp \
    ProjectSubsystem/editprojectpage.cpp \
    ProjectSubsystem/projectmanager.cpp \
    ProjectSubsystem/projectpage.cpp \
    welcomepage.cpp \
    ProjectSubsystem/adminloginpage.cpp \
    mainwindow.cpp


HEADERS  += \
    Algorithm/algorithmmanager.h \
    Algorithm/algorithmsummary.h \
    StorageSubsystem/Administrator.h \
    StorageSubsystem/EntityDef.h \
    StorageSubsystem/Project.h \
    StorageSubsystem/storage.h \
    StorageSubsystem/Student.h \
    StorageSubsystem/StudentProfile.h \
    StorageSubsystem/Team.h \
    StorageSubsystem/Team.hpp \
    StorageSubsystem/User.h \
    ProfileSubsystem/editprofilepage.h \
    ProfileSubsystem/profilemanager.h \
    ProfileSubsystem/studentloginpage.h \
    ProfileSubsystem/studentprofilepage.h \
    ProfileSubsystem/studentprojectspage.h \
    ProjectSubsystem/adminmainpage.h \
    ProjectSubsystem/adminstudentprofilepage.h \
    ProjectSubsystem/createprojectpage.h \
    ProjectSubsystem/editprojectpage.h \
    ProjectSubsystem/projectmanager.h \
    ProjectSubsystem/projectpage.h \
    welcomepage.h \
    ProjectSubsystem/adminloginpage.h \
    mainwindow.h


FORMS    += \
    Algorithm/algorithmsummary.ui \
    ProfileSubsystem/adminstudentprofilepage.ui \
    ProfileSubsystem/editprofilepage.ui \
    ProfileSubsystem/studentloginpage.ui \
    ProfileSubsystem/studentprofilepage.ui \
    ProfileSubsystem/studentprojectspage.ui \
    ProjectSubsystem/adminmainpage.ui \
    ProjectSubsystem/adminstudentprofilepage.ui \
    ProjectSubsystem/createprojectpage.ui \
    ProjectSubsystem/editprojectpage.ui \
    ProjectSubsystem/projectpage.ui \
    welcomepage.ui \
    ProjectSubsystem/adminloginpage.ui \
    mainwindow.ui


OTHER_FILES += \
    StorageSubsystem/cupid_DB.db
