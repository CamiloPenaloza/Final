/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QGroupBox *menu;
    QPushButton *play_button;
    QLabel *puntaje;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, -10, 1280, 720));
        menu = new QGroupBox(centralwidget);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(0, -10, 1280, 720));
        menu->setStyleSheet(QString::fromUtf8("background-image: url(:/sprites/menu.png)"));
        play_button = new QPushButton(menu);
        play_button->setObjectName("play_button");
        play_button->setGeometry(QRect(590, 470, 111, 41));
        play_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: none;\n"
"    background-color: #4CAF50; /* Color de fondo */\n"
"    border: none; /* Sin borde */\n"
"    color: white; /* Color del texto */\n"
"    font-size: 16px; /* Tama\303\261o de fuente */\n"
"    padding: 10px 20px; /* Espaciado interno */\n"
"    cursor: pointer; /* Cambia el cursor al pasar el rat\303\263n */\n"
"    border-radius: 5px; /* Bordes redondeados */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #45a049; /* Color de fondo al pasar el rat\303\263n */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3e8e41; /* Color de fondo al presionar */\n"
"}\n"
""));
        puntaje = new QLabel(centralwidget);
        puntaje->setObjectName("puntaje");
        puntaje->setGeometry(QRect(20, 10, 71, 31));
        puntaje->setStyleSheet(QString::fromUtf8("#puntaje {\n"
"	background-color: rgb(0, 0, 0);\n"
"	padding: 5px 10px;\n"
"	color: rgb(255, 255, 255);\n"
"	qproperty-alignment: 'AlignCenter';\n"
"    border-radius: 10px;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"}\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menu->raise();
        graphicsView->raise();
        puntaje->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        menu->setTitle(QString());
        play_button->setText(QCoreApplication::translate("MainWindow", "JUGAR", nullptr));
        puntaje->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>500</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
