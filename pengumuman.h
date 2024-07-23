#ifndef PENGUMUMAN_H
#define PENGUMUMAN_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class pengumuman;
}

class pengumuman : public QDialog
{
    Q_OBJECT

public:
    explicit pengumuman(QWidget *parent = nullptr);
    void loadDataPENGUMUMAN();
    void simpanPENGUMUMAN(QString id_pengumuman, QString judul, QString isi, QString tgl_pengumuman);
    void ubahPENGUMUMAN(QString id_pengumuman, QString judul, QString isi, QString tgl_pengumuman);
    ~pengumuman();


private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tablePENGUMUMAN_activated(const QModelIndex &index);


private:
    Ui::pengumuman *ui;
    QSqlDatabase koneksi;
    QSqlQueryModel *crudModel;
    void loadTableData();
};


#endif // PENGUMUMAN_H
