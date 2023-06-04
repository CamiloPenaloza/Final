#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setVisible(false);
    juego = new game;
    juego->setSceneRect(0, 0, ui->graphicsView->width() - 2, ui->graphicsView->height() - 2);
    ui->graphicsView->setScene(juego);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete juego;
}

void MainWindow::on_play_button_clicked()
{
    juego->gameStarted = true;
    ui->graphicsView->setVisible(true);
    ui->menu->setVisible(false);
}

