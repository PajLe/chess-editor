#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_Chessboard_triggered()
{
    QString fname = QFileDialog::getOpenFileName(this, this->windowTitle(), QDir::currentPath(), "Text Files (*.txt);;All Files (*.*)");
    ui->centralwidget->getCDoc()->load(fname);
}

void MainWindow::on_actionSave_Chessboard_triggered()
{
    QString fname = QFileDialog::getSaveFileName(this, this->windowTitle(), QDir::currentPath(), "Text Files (*.txt);;All Files (*.*)");
    ui->centralwidget->getCDoc()->save(fname);
}
