#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    ui->graphicsView->setVisible(false);
    ui->puntaje->setVisible(false);
    juego = new game;
    connect(juego, &game::updatePuntajeSignal, this, &MainWindow::updatePuntaje);
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
    ui->puntaje->setVisible(true);
}

void MainWindow::updatePuntaje(const QString& puntaje)
{
    ui->puntaje->setText(puntaje);
}
