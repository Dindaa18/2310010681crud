#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <daftar.h>
#include <pembayaran.h>
#include <pengumuman.h>
#include <user.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_1_clicked();

private:
    Ui::MainWindow *ui;
    daftar *uiDFTR;
    pembayaran *uiPMBYRN;
    pengumuman *uiPNGMMN;
    user *uiUSR;
};
#endif // MAINWINDOW_H
