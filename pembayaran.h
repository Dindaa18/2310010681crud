#ifndef PEMBAYARAN_H
#define PEMBAYARAN_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class pembayaran;
}

class pembayaran : public QDialog
{
    Q_OBJECT

public:
    explicit pembayaran(QWidget *parent = nullptr);
    void loadDatapembayaran();
    void simpanPEMBAYARAN(QString id_pembayaran, QString nis, QString tgl_pembayaran, QString status);
    void ubahPEMBAYARAN(QString id_pembayaran, QString nis, QString tgl_pembayaran, QString status);
    ~pembayaran();


private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tablePEMBAYARAN_activated(const QModelIndex &index);


private:
    Ui::pembayaran *ui;
    QSqlDatabase koneksi;
    QSqlQueryModel *crudModel;
    void loadTableData();
};

#endif // PEMBAYARAN_H
