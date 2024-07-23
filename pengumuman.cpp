#include "pengumuman.h"
#include "ui_pengumuman.h"
#include <QMessageBox>
#include <QSqlQuery>

void pengumuman::ubahPENGUMUMAN(QString id_pengumuman, QString judul, QString isi, QString tgl_pengumuman) {
    // Implementasi dari metode ini
    // Misalnya, memperbarui data pengguna di database atau struktur data Anda
}

void pengumuman::simpanPENGUMUMAN(QString id_pengumuman, QString judul, QString isi, QString tgl_pengumuman) {
    // Implementasi dari metode ini
    // Misalnya, memperbarui data pengguna di database atau struktur data Anda
}

pengumuman::pengumuman(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pengumuman)
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

}

pengumuman::~pengumuman()
{
    delete ui;
}

void pengumuman::on_pushButton_1_clicked()
{
    // Validasi semua input
    if(ui->editidpengumuman->text().isEmpty()){
        QMessageBox::information(this,"Warning", "Id pengumuman Belum Di Isi");
        ui->editidpengumuman->setFocus();
    } else if(ui->editjudulpengumuman->text().isEmpty()){
        QMessageBox::information(this,"Warning", "Judul Belum Di Isi");
        ui->editjudulpengumuman->setFocus();
    } else if(ui->editisipengumuman->toPlainText().isEmpty()){
        QMessageBox::information(this,"Warning", "Isi Belum Di Isi");
        ui->editisipengumuman->setFocus();
    } else if(ui->dateeditpengumuman->date().isNull()){
        QMessageBox::information(this,"Warning", "Tanggal pengumuman Belum Di Isi");
        ui->dateeditpengumuman->setFocus();
    } else {
        // Cek duplikat id_pengumuman
        QSqlQuery duplikat;
        duplikat.prepare("SELECT * FROM pengumuman WHERE id_pengumuman = :id");
        duplikat.bindValue(":id", ui->editidpengumuman->text().toInt());
        duplikat.exec();
        if (duplikat.next()){
            QMessageBox::information(this,"Warning","ID pengumuman Sudah Terdaftar");
            ui->editidpengumuman->setText(duplikat.value("id_pengumuman").toString());
            ui->editjudulpengumuman->setText(duplikat.value("judul").toString());
            ui->editisipengumuman->setPlainText(duplikat.value("isi").toString());
            ui->dateeditpengumuman->setDate(duplikat.value("tgl_pengumuman").toDate());
        } else {
            // Simpan data baru
            QSqlQuery query;
            query.prepare("INSERT INTO pengumuman (id_pengumuman, judul, isi, tgl_pengumuman) VALUES (:id, :judul, :isi, :tgl_pengumuman)");
            query.bindValue(":id", ui->editidpengumuman->text().toInt());
            query.bindValue(":judul", ui->editjudulpengumuman->text());
            query.bindValue(":isi", ui->editisipengumuman->toPlainText());
            query.bindValue(":tgl_pengumuman", ui->dateeditpengumuman->date().toString("yyyy-MM-dd")); // Format tanggal sesuai dengan MySQL

            if (query.exec()) {
                QMessageBox::information(this, "Success", "Data pengumuman berhasil disimpan.");
                ui->editidpengumuman->clear();
                ui->editjudulpengumuman->clear();
                ui->editisipengumuman->clear();
                ui->dateeditpengumuman->setDate(QDate::currentDate()); // Set tanggal ke tanggal saat ini
                pengumuman::loadDataPENGUMUMAN(); // Panggil fungsi untuk memuat ulang data jika diperlukan
            } else {
                QMessageBox::warning(this, "Error", "Gagal menyimpan data: " + query.lastError().text());
            }
        }
    }
}

void pengumuman::on_pushButton_2_clicked()
{
    int baris = ui->tablePENGUMUMAN->selectionModel()->currentIndex().row();

    if (baris < 0) {
        QMessageBox::information(this, "Warning", "Silakan Pilih Data Terlebih Dahulu untuk Proses Edit");
        return;
    }

    QString id_pengumuman = ui->editidpengumuman->text();
    QString judul = ui->editjudulpengumuman->text();
    QString isi = ui->editisipengumuman->toPlainText();
    QDate tgl_pengumuman = ui->dateeditpengumuman->date();

    if (id_pengumuman.isEmpty() || judul.isEmpty() || isi.isEmpty() || tgl_pengumuman.isNull()) {
        QMessageBox::information(this, "Warning", "Silakan Isi Semua Data yang Diperlukan untuk Proses Edit");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE pengumuman SET judul = :judul, isi = :isi, tgl_pengumuman = :tgl_pengumuman WHERE id_pengumuman = :id_pengumuman");
    query.bindValue(":judul", judul);
    query.bindValue(":isi", isi);
    query.bindValue(":tgl_pengumuman", tgl_pengumuman.toString("yyyy-MM-dd")); // Format tanggal sesuai dengan MySQL
    query.bindValue(":id_pengumuman", id_pengumuman);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Data pengumuman berhasil diubah.");
        ui->editidpengumuman->clear();
        ui->editjudulpengumuman->clear();
        ui->editisipengumuman->clear();
        ui->dateeditpengumuman->setDate(QDate::currentDate()); // Set tanggal ke tanggal saat ini
        pengumuman::loadDataPENGUMUMAN(); // Panggil fungsi untuk memuat ulang data jika diperlukan
    } else {
        QMessageBox::warning(this, "Error", "Gagal mengubah data: " + query.lastError().text());
    }
}


void pengumuman::on_pushButton_3_clicked()
{
    if(ui->editidpengumuman->text().isEmpty() && ui->editjudulpengumuman->text().isEmpty() && ui->editisipengumuman->toPlainText().isEmpty() && ui->dateeditpengumuman->date().isNull())
    {
        QMessageBox::information(this,"Warning","Silakan Pilih Data Yang Akan Dihapus");
        return;
    } else {
        QSqlQuery hapus;
        hapus.prepare("DELETE FROM pengumuman WHERE id_pengumuman = :IDPENGUMUMAN");
        hapus.bindValue(":IDPENGUMUMAN", ui->editidpengumuman->text().toInt());
        hapus.exec();

        pengumuman::loadDataPENGUMUMAN();
    }
}


void pengumuman::on_pushButton_4_clicked()
{
    ui->editidpengumuman->setText("");           // Mengganti dengan editidpengumuman
    ui->editjudulpengumuman->setText("");                    // Menghapus karena tidak ada di tabel pengumuman
    ui->dateeditpengumuman->setDate(QDate::currentDate());  // Mengganti dengan dateeditpengumuman
    ui->dateeditpengumuman->setDate(QDate::currentDate());          // Menghapus karena tidak ada di tabel pengumuman

    // Mengganti nama objek sesuai dengan tabel pengumuman
    ui->editidpengumuman->setText("");
    ui->editjudulpengumuman->setText("");
    ui->editisipengumuman->setText("");
    ui->dateeditpengumuman->setDate(QDate::currentDate());
}

void pengumuman::on_tablePENGUMUMAN_activated(const QModelIndex &index)
{
    int baris = ui->tablePENGUMUMAN->selectionModel()->currentIndex().row();
    ui->editidpengumuman->setText(ui->tablePENGUMUMAN->model()->index(baris, 0).data().toString());  // Mengganti dengan editidpengumuman
    ui->editjudulpengumuman->setText(ui->tablePENGUMUMAN->model()->index(baris, 1).data().toString());  // Mengganti dengan editjudulpengumuman
    ui->editisipengumuman->setText(ui->tablePENGUMUMAN->model()->index(baris, 2).data().toString());  // Mengganti dengan editisipengumuman
    ui->dateeditpengumuman->setDate(ui->tablePENGUMUMAN->model()->index(baris, 3).data().toDate());  // Mengganti dengan dateeditpengumuman
  // Mengganti dengan editidpengumuman
}

void pengumuman::loadDataPENGUMUMAN()
{
    crudModel = new QSqlQueryModel(this);
    crudModel->setQuery("SELECT * FROM pengumuman");  // Mengganti dari tabel pembayaran ke tabel pengumuman
    crudModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID pengumuman"));  // Mengganti dengan ID pengumuman
    crudModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Judul"));  // Mengganti dengan Judul
    crudModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Isi"));  // Mengganti dengan Isi
    crudModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Tanggal pengumuman"));  // Mengganti dengan Tanggal pengumuman
    ui->tablePENGUMUMAN->setModel(crudModel);
    ui->tablePENGUMUMAN->setColumnWidth(0, 110);  // Sesuaikan lebar kolom sesuai kebutuhan
    ui->tablePENGUMUMAN->setColumnWidth(1, 200);
    ui->tablePENGUMUMAN->setColumnWidth(2, 120);
    ui->tablePENGUMUMAN->setColumnWidth(3, 200);
    ui->tablePENGUMUMAN->show();
}





