#ifndef USER_H
#define USER_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class user;
}

class user : public QDialog
{
    Q_OBJECT

public:
    explicit user(QWidget *parent = nullptr);
    void loadDataUSER();
    void simpanUSER(QString id, QString nama, QString username, QString password, QString level);
    void ubahUSER(QString id, QString nama, QString username, QString password, QString level);
    ~user();


private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableUSER_activated(const QModelIndex &index);

    void on_pushButton_5_clicked();

private:
    Ui::user *ui;
    QSqlDatabase koneksi;
    QSqlQueryModel *crudModel;
    void loadTableData();
};

#endif // USER_H
