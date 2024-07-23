#include "pembayaran.h"
#include "ui_pembayaran.h"
#include <QMessageBox>
#include <QSqlQuery>

void pembayaran::ubahPEMBAYARAN(QString id_pembayaran, QString nis, QString tgl_pembayaran, QString status) {
    // Implementasi dari metode ini
    // Misalnya, memperbarui data pengguna di database atau struktur data Anda
}

void pembayaran::simpanPEMBAYARAN(QString id_pembayaran, QString nis, QString tgl_pembayaran, QString status) {
    // Implementasi dari metode ini
    // Misalnya, memperbarui data pengguna di database atau struktur data Anda
}

pembayaran::pembayaran(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pembayaran)
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

    pembayaran::loadDatapembayaran();
    ui->cmbstatus->addItem("Lunas");
    ui->cmbstatus->addItem("Cicil");

}

pembayaran::~pembayaran()
{
    delete ui;
}

void pembayaran::on_pushButton_1_clicked()
{
    // Validasi semua input
    if(ui->editidpembayaran->text().isEmpty()){
        QMessageBox::information(this,"Warning", "Id pembayaran Belum Di Isi");
        ui->editidpembayaran->setFocus();
    } else if(ui->editnis->text().isEmpty()){
        QMessageBox::information(this,"Warning", "NIS Belum Di Isi");
        ui->editnis->setFocus();
    } else if(ui->dateeditbayar->date().isNull()){
        QMessageBox::information(this,"Warning", "Tanggal Pembayaran Belum Di Isi");
        ui->dateeditbayar->setFocus();
    } else if(ui->cmbstatus->currentIndex() < 0){
        QMessageBox::information(this,"Warning", "Status Pembayaran Belum Dipilih");
        ui->cmbstatus->setFocus();
    } else {
        // Cek duplikat id_pembayaran
        QSqlQuery duplikat;
        duplikat.prepare("SELECT * FROM pembayaran WHERE id_pembayaran = :id");
        duplikat.bindValue(":id", ui->editidpembayaran->text());
        duplikat.exec();
        if (duplikat.next()){
            QMessageBox::information(this,"Warning","ID pembayaran Sudah Terdaftar");
            ui->editidpembayaran->setText(duplikat.value(0).toString());
            ui->editnis->setText(duplikat.value(1).toString());
            ui->dateeditbayar->setDate(duplikat.value(2).toDate());
            ui->cmbstatus->setCurrentText(duplikat.value(3).toString());
        } else {
            // Simpan data baru
            QSqlQuery query;
            query.prepare("INSERT INTO pembayaran (id_pembayaran, nis, tgl_pembayaran, status) VALUES (:id, :nis, :tgl_pembayaran, :status)");
            query.bindValue(":id", ui->editidpembayaran->text());
            query.bindValue(":nis", ui->editnis->text());
            query.bindValue(":tgl_pembayaran", ui->dateeditbayar->date().toString("yyyy-MM-dd")); // Format tanggal sesuai dengan MySQL
            query.bindValue(":status", ui->cmbstatus->currentText());

            if (query.exec()) {
                QMessageBox::information(this, "Success", "Data pembayaran berhasil disimpan.");
                ui->editidpembayaran->clear();
                ui->editnis->clear();
                ui->dateeditbayar->setDate(QDate::currentDate()); // Set tanggal ke tanggal saat ini
                ui->cmbstatus->setCurrentIndex(0);
                pembayaran::loadDatapembayaran(); // Panggil fungsi untuk memuat ulang data jika diperlukan
            } else {
                QMessageBox::warning(this, "Error", "Gagal menyimpan data: " + query.lastError().text());
            }
        }
    }
}




void pembayaran::on_pushButton_2_clicked()
{
    int baris = ui->tablePEMBAYARAN->selectionModel()->currentIndex().row();

    if (baris < 0) {
        QMessageBox::information(this, "Warning", "Silakan Pilih Data Terlebih Dahulu untuk Proses Edit");
        return;
    }

    QString id_pembayaran = ui->editidpembayaran->text();
    QString nis = ui->editnis->text();
    QDate tgl_pembayaran = ui->dateeditbayar->date(); // Pastikan sesuai dengan tipe data tanggal
    QString status = ui->cmbstatus->currentText();

    if (id_pembayaran.isEmpty() || nis.isEmpty() || tgl_pembayaran.isNull() || status.isEmpty()) {
        QMessageBox::information(this, "Warning", "Silakan Isi Semua Data yang Diperlukan untuk Proses Edit");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE pembayaran SET nis = :nis, tgl_pembayaran = :tgl_pembayaran, status = :status WHERE id_pembayaran = :id_pembayaran");
    query.bindValue(":nis", nis);
    query.bindValue(":tgl_pembayaran", tgl_pembayaran.toString("yyyy-MM-dd")); // Format tanggal sesuai dengan MySQL
    query.bindValue(":status", status);
    query.bindValue(":id_pembayaran", id_pembayaran);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Data pembayaran berhasil diubah.");
        ui->editidpembayaran->clear();
        ui->editnis->clear();
        ui->dateeditbayar->setDate(QDate::currentDate()); // Set tanggal ke tanggal saat ini
        ui->cmbstatus->setCurrentIndex(0);
        pembayaran::loadDatapembayaran(); // Panggil fungsi untuk memuat ulang data jika diperlukan
    } else {
        QMessageBox::warning(this, "Error", "Gagal mengubah data: " + query.lastError().text());
    }
}




void pembayaran::on_pushButton_3_clicked()
{
    if(ui->editidpembayaran->text().isEmpty() && ui->editnis->text().isEmpty() && ui->dateeditbayar->date().isNull() && ui->cmbstatus->currentText().isEmpty())
    {
        QMessageBox::information(this,"Warning","Silakan Pilih Data Yang Akan Dihapus");
        return;
    }else{
        QSqlQuery hapus;
        hapus.prepare("DELETE FROM pembayaran WHERE id_pembayaran = :IDPEMBAYARAN");
        hapus.bindValue(":IDPEMBAYARAN", ui->editidpembayaran->text().toInt());
        hapus.exec();

        pembayaran::loadDatapembayaran();
    }
}


void pembayaran::on_pushButton_4_clicked()
{
    ui->editidpembayaran->setText("");
    ui->editnis->setText("");
    ui->dateeditbayar->setDate(QDate::currentDate());
    ui->cmbstatus->setCurrentIndex(-1);
}

void pembayaran::on_tablePEMBAYARAN_activated(const QModelIndex &index)
{
    int baris = ui->tablePEMBAYARAN->selectionModel()->currentIndex().row();
    ui->editidpembayaran->setText(ui->tablePEMBAYARAN->model()->index(baris, 0).data().toString());
    ui->editnis->setText(ui->tablePEMBAYARAN->model()->index(baris, 1).data().toString());
    ui->dateeditbayar->setDate(ui->tablePEMBAYARAN->model()->index(baris, 2).data().toDate());
    ui->cmbstatus->setCurrentText(ui->tablePEMBAYARAN->model()->index(baris, 3).data().toString());

}


void pembayaran::loadDatapembayaran(){
    crudModel =new QSqlQueryModel(this);
    crudModel->setQuery("SELECT*FROM pembayaran");
    crudModel->setHeaderData(0,Qt::Horizontal,QObject::tr("ID pembayaran"));
    crudModel->setHeaderData(1,Qt::Horizontal,QObject::tr("NIS"));
    crudModel->setHeaderData(2,Qt::Horizontal,QObject::tr("TANGGAL BAYAR"));
    crudModel->setHeaderData(3,Qt::Horizontal,QObject::tr("STATUS"));
    ui->tablePEMBAYARAN->setModel(crudModel);
    ui->tablePEMBAYARAN->setColumnWidth(0,110);
    ui->tablePEMBAYARAN->setColumnWidth(0,200);
    ui->tablePEMBAYARAN->setColumnWidth(0,120);
    ui->tablePEMBAYARAN->setColumnWidth(0,200);
    ui->tablePEMBAYARAN->show();
}


