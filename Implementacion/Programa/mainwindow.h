#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include <QMessageBox>
#define weight 1201
#define hight 500
//22
//12
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_play_button_clicked();

private:
    Ui::MainWindow *ui;
    game *juego;
};
#endif // MAINWINDOW_H
