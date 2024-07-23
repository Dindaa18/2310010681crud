#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pushButton_2_clicked()
{
    uiPMBYRN = new pembayaran(this);
    uiPMBYRN->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    uiPNGMMN = new pengumuman(this);
    uiPNGMMN->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    uiUSR = new user(this);
    uiUSR->show();
}


void MainWindow::on_pushButton_1_clicked()
{
    uiDFTR = new daftar(this);
    uiDFTR->show();
}

