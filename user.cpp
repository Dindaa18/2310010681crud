#include "user.h"
#include "ui_user.h"
#include <QMessageBox>
#include <QSqlQuery>

    void user::ubahUSER(QString id, QString nama, QString username, QString password, QString level) {
    // Implementasi dari metode ini
    // Misalnya, memperbarui data pengguna di database atau struktur data Anda
}

void user::simpanUSER(QString id, QString nama, QString username, QString password, QString level) {
    // Implementasi dari metode ini
    // Misalnya, memperbarui data pengguna di database atau struktur data Anda
}

user::user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user)
{
    ui->setupUi(this);

    koneksi=QSqlDatabase::addDatabase("QODBC");
    koneksi.setDatabaseName("Driver={MySQL ODBC 8.4 Unicode Driver};Database=2310010681");
    koneksi.setHostName("127.0.0.1");
    koneksi.setUserName("root");
    koneksi.setPassword("");
    koneksi.setPort(3306);

    if (!koneksi.open()){
        QMessageBox::information(this,"Salah",koneksi.lastError().text());
        return;
    }

    user::loadDataUSER();
    ui->cmblevel->addItem("1");
    ui->cmblevel->addItem("2");
    ui->cmblevel->addItem("3");

}

user::~user()
{
    delete ui;
}

void user::on_pushButton_1_clicked()
{
    if(ui->editiduser->text().isEmpty()){
        QMessageBox::information(this,"Warning", "Id User Belum Di Isi");
        ui->editiduser->setFocus();
    }else if(ui->editnamauser->text().isEmpty()){
        QMessageBox::information(this,"Warning", "Nama User Belum Di Isi");
        ui->editnamauser->setFocus();
    }else if(ui->editpassword->text().isEmpty()){
        QMessageBox::information(this,"Warning", "Password User Belum Di Isi");
        ui->editpassword->setFocus();
    }else{
        QSqlQuery duplikat;
        duplikat.prepare("SELECT * FROM user WHERE id = :id");
        duplikat.bindValue(":id", ui->editiduser->text());
        duplikat.exec();
        if (duplikat.next()){
            QMessageBox::information(this,"Warning","ID User Sudah Terdaftar");
            ui->editiduser->setText(duplikat.value(0).toString());
            ui->editnamauser->setText(duplikat.value(1).toString());
            ui->editusername->setText(duplikat.value(2).toString());
            ui->editpassword->setText(duplikat.value(3).toString());
            ui->cmblevel->setCurrentText(duplikat.value(4).toString());
        }else{
            QSqlQuery query;
            query.prepare("INSERT INTO user (id, nama, username, password, level) VALUES (:id, :nama, :username, :password, :level)");
            query.bindValue(":id", ui->editiduser->text());
            query.bindValue(":nama", ui->editnamauser->text());
            query.bindValue(":username", ui->editusername->text());
            query.bindValue(":password", ui->editpassword->text());
            query.bindValue(":level", ui->cmblevel->currentText());

            if (query.exec()) {
                QMessageBox::information(this, "Success", "Data berhasil disimpan.");
                ui->editiduser->clear();
                ui->editnamauser->clear();
                ui->editusername->clear();
                ui->editpassword->clear();
                ui->cmblevel->setCurrentIndex(0);
                user::loadDataUSER(); // Panggil fungsi untuk memuat ulang data jika diperlukan
            } else {
                QMessageBox::warning(this, "Error", "Gagal menyimpan data: " + query.lastError().text());
            }
        }
    }
}



void user::on_pushButton_2_clicked()
{
    int baris = ui->tableUSER->selectionModel()->currentIndex().row();

    if (baris < 0) {
        QMessageBox::information(this, "Warning", "Silakan Pilih Data Terlebih Dahulu untuk Proses Edit");
        return;
    }

    QString id = ui->editiduser->text();
    QString nama = ui->editnamauser->text();
    QString username = ui->editusername->text();
    QString password = ui->editpassword->text();
    QString level = ui->cmblevel->currentText();

    if (id.isEmpty() || nama.isEmpty() || password.isEmpty()) {
        QMessageBox::information(this, "Warning", "Silakan Isi Semua Data yang Diperlukan untuk Proses Edit");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE user SET nama = :nama, username = :username, password = :password, level = :level WHERE id = :id");
    query.bindValue(":nama", nama);
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":level", level);
    query.bindValue(":id", id);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Data berhasil diubah.");
        ui->editiduser->clear();
        ui->editnamauser->clear();
        ui->editusername->clear();
        ui->editpassword->clear();
        ui->cmblevel->setCurrentIndex(0);

        user::loadDataUSER(); // Panggil fungsi untuk memuat ulang data jika diperlukan
    } else {
        QMessageBox::warning(this, "Error", "Gagal mengubah data: " + query.lastError().text());
    }
}



void user::on_pushButton_3_clicked()
{
    if(ui->editiduser->text().isEmpty() && ui->editnamauser->text().isEmpty() && ui->editpassword->text().isEmpty())
    {
        QMessageBox::information(this,"Warning","Silakan Pilih Data Yang Akan Dihapus");
        return;
    }else{
        QSqlQuery hapus;
        hapus.prepare("DELETE FROM user WHERE id= :IDUSER");
        hapus.bindValue(":IDUSER",ui->editiduser->text());
        hapus.exec();

        user::loadDataUSER();
    }
}


void user::on_pushButton_4_clicked()
{
    ui->editiduser->setText("");
    ui->editnamauser->setText("");
    ui->editusername->setText("");
    ui->editpassword->setText("");
}

void user::on_tableUSER_activated(const QModelIndex &index)
{
    int baris = ui->tableUSER->selectionModel()->currentIndex().row();
    ui->editiduser->setText(ui->tableUSER->model()->index(baris,0).data().toString());
    ui->editnamauser->setText(ui->tableUSER->model()->index(baris,1).data().toString());
    ui->editusername->setText(ui->tableUSER->model()->index(baris,2).data().toString());
    ui->editpassword->setText(ui->tableUSER->model()->index(baris,3).data().toString());
    ui->cmblevel->setCurrentText(ui->tableUSER->model()->index(baris,4).data().toString());

}

void user::loadDataUSER(){

    crudModel =new QSqlQueryModel(this);
    crudModel->setQuery("SELECT*FROM user");
    crudModel->setHeaderData(0,Qt::Horizontal,QObject::tr("ID USER"));
    crudModel->setHeaderData(1,Qt::Horizontal,QObject::tr("NAMA"));
    crudModel->setHeaderData(2,Qt::Horizontal,QObject::tr("USERNAME"));
    crudModel->setHeaderData(3,Qt::Horizontal,QObject::tr("PASSWORD"));
    crudModel->setHeaderData(4,Qt::Horizontal,QObject::tr("LEVEL"));
    ui->tableUSER->setModel(crudModel);
    ui->tableUSER->setColumnWidth(0,110);
    ui->tableUSER->setColumnWidth(0,200);
    ui->tableUSER->setColumnWidth(0,120);
    ui->tableUSER->setColumnWidth(0,200);
    ui->tableUSER->setColumnWidth(0,120);
    ui->tableUSER->show();
}
