#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    juego = new game;

    juego->setSceneRect(0, 0, ui->graphicsView->width() - 2, ui->graphicsView->height() - 2);
    cout << ui->graphicsView->width() - 2 << endl;
    cout << ui->graphicsView->height() - 2 << endl;
    ui->graphicsView->setScene(juego);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete juego;
}
