#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_logo->setStyleSheet("image: url(:/logo/GGStore_LOGO.jpg);");
}

MainWindow::~MainWindow()
{
    delete ui;
}

