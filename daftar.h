#ifndef DAFTAR_H
#define DAFTAR_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class daftar;
}

class daftar : public QDialog
{
    Q_OBJECT

public:
    explicit daftar(QWidget *parent = nullptr);
    void loadDataDAFTAR();
    void simpanDAFTAR(QString id, QString nis, QString nama, QString tempat, QString tgl_lahir, QString agama, QString telpon, QString alamat, QString email, QString upload, QString foto, QString status);
    void ubahDAFTAR(QString id, QString nis, QString nama, QString tempat, QString tgl_lahir, QString agama, QString telpon, QString alamat, QString email, QString upload, QString foto, QString status);
    ~daftar();


private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableDAFTAR_activated(const QModelIndex &index);


private:
    Ui::daftar *ui;
    QSqlDatabase koneksi;
    QSqlQueryModel *crudModel;
    void loadTableData();
};

#endif // DAFTAR_H
