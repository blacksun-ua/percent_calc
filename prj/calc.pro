#-------------------------------------------------
#
# Project created by QtCreator 2013-08-10T13:08:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calc
TEMPLATE = app


SOURCES += ../src/main.cpp \
    ../src/main_window.cpp \
    ../src/credit_calculator.cpp \
    ../src/deposit_calculator.cpp \
    ../src/credit_calculator_impl.cpp \
    ../src/money.cpp

HEADERS  += \
    ../src/main_window.h \
    ../src/credit_calculator.h \
    ../src/deposit_calculator.h \
    ../src/credit_calculator_impl.h \
    ../src/money.h

FORMS    += \
    ../src/new_deposit_account.ui \
    ../src/new_credit_account.ui \
    ../src/main_window.ui \
    ../src/deposit_calculator.ui \
    ../src/credit_calculator.ui
