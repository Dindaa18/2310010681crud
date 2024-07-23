#include "daftar.h"
#include "ui_daftar.h"
#include <QMessageBox>
#include <QSqlQuery>

void daftar::simpanDAFTAR(QString id, QString nis, QString nama, QString tempat, QString tgl_lahir, QString agama, QString telpon, QString alamat, QString email, QString upload, QString foto, QString status){

}

void daftar::ubahDAFTAR(QString id, QString nis, QString nama, QString tempat, QString tgl_lahir, QString agama, QString telpon, QString alamat, QString email, QString upload, QString foto, QString status){

}

daftar::daftar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::daftar)
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

    daftar::loadDataDAFTAR();
    ui->cmbjenkeldaftar->addItem("Perempuan");
    ui->cmbjenkeldaftar->addItem("Lakilaki");
    ui->cmbagamadaftar->addItem("Islam");
    ui->cmbagamadaftar->addItem("Katolik");
    ui->cmbagamadaftar->addItem("Protestan");
    ui->cmbagamadaftar->addItem("Hindu");
    ui->cmbagamadaftar->addItem("Budha");
    ui->cmbagamadaftar->addItem("Konghuchu");

}

daftar::~daftar()
{
    delete ui;
}

void daftar::on_pushButton_1_clicked()
{
    // Validasi semua input
    if(ui->editiddaftar->text().isEmpty()){
        QMessageBox::information(this,"Warning", "Id Belum Di Isi");
        ui->editiddaftar->setFocus();
    } else if(ui->editnisdaftar->text().isEmpty()){
        QMessageBox::information(this,"Warning", "NIS Belum Di Isi");
        ui->editnisdaftar->setFocus();
    } else if(ui->editnamadaftar->text().isEmpty()){
        QMessageBox::information(this,"Warning", "Nama Belum Di Isi");
        ui->editnamadaftar->setFocus();
    } else if(ui->edittempatdaftar->text().isEmpty()){
        QMessageBox::information(this,"Warning", "Tempat Lahir Belum Di Isi");
        ui->edittempatdaftar->setFocus();
    } else if(ui->dateedittgllahirdaftar->date().isNull()){
        QMessageBox::information(this,"Warning", "Tanggal Lahir Belum Di Isi");
        ui->dateedittgllahirdaftar->setFocus();
    } else if(ui->cmbjenkeldaftar->currentText().isEmpty()){
        QMessageBox::information(this,"Warning", "Jenis Kelamin Belum Di Isi");
        ui->cmbjenkeldaftar->setFocus();
    } else if(ui->cmbagamadaftar->currentText().isEmpty()){
        QMessageBox::information(this,"Warning", "Agama Belum Di Isi");
        ui->cmbagamadaftar->setFocus();
    } else if(ui->edittelepondaftar->text().isEmpty()){
        QMessageBox::information(this,"Warning", "Telepon Belum Di Isi");
        ui->edittelepondaftar->setFocus();
    } else if(ui->editalamatdaftar->text().isEmpty()){
        QMessageBox::information(this,"Warning", "Alamat Belum Di Isi");
        ui->editalamatdaftar->setFocus();
    } else if(ui->editemaildaftar->text().isEmpty()){
        QMessageBox::information(this,"Warning", "Email Belum Di Isi");
        ui->editemaildaftar->setFocus();
    } else if(ui->edituploaddaftar->text().isEmpty()){
        QMessageBox::information(this,"Warning", "Upload Belum Di Isi");
        ui->edituploaddaftar->setFocus();
    } else if(ui->editfotodaftar->text().isEmpty()){
        QMessageBox::information(this,"Warning", "Foto Belum Di Isi");
        ui->editfotodaftar->setFocus();
    } else if(ui->editstatusdaftar->text().isEmpty()){
        QMessageBox::information(this,"Warning", "Status Belum Di Isi");
        ui->editstatusdaftar->setFocus();
    } else {
        // Cek duplikat id
        QSqlQuery duplikat;
        duplikat.prepare("SELECT * FROM daftar WHERE id = :id");
        duplikat.bindValue(":id", ui->editiddaftar->text().toInt());
        duplikat.exec();
        if (duplikat.next()){
            QMessageBox::information(this,"Warning","ID Sudah Terdaftar");
            ui->editiddaftar->setText(duplikat.value("id").toString());
            ui->editnisdaftar->setText(duplikat.value("nis").toString());
            ui->editnamadaftar->setText(duplikat.value("nama").toString());
            ui->edittempatdaftar->setText(duplikat.value("tempat").toString());
            ui->dateedittgllahirdaftar->setDate(duplikat.value("tgl_lahir").toDate());
            ui->cmbjenkeldaftar->setCurrentText(duplikat.value("jen_kel").toString());
            ui->cmbagamadaftar->setCurrentText(duplikat.value("agama").toString());
            ui->edittelepondaftar->setText(duplikat.value("telpon").toString());
            ui->editalamatdaftar->setText(duplikat.value("alamat").toString());
            ui->editemaildaftar->setText(duplikat.value("email").toString());
            ui->edituploaddaftar->setText(duplikat.value("upload").toString());
            ui->editfotodaftar->setText(duplikat.value("foto").toString());
            ui->editstatusdaftar->setText(duplikat.value("status").toString());
        } else {
            // Simpan data baru
            QSqlQuery query;
            query.prepare("INSERT INTO daftar (id, nis, nama, tempat, tgl_lahir, jen_kel, agama, telpon, alamat, email, upload, foto, status) VALUES (:id, :nis, :nama, :tempat, :tgl_lahir, :jen_kel, :agama, :telpon, :alamat, :email, :upload, :foto, :status)");
            query.bindValue(":id", ui->editiddaftar->text().toInt());
            query.bindValue(":nis", ui->editnisdaftar->text());
            query.bindValue(":nama", ui->editnamadaftar->text());
            query.bindValue(":tempat", ui->edittempatdaftar->text());
            query.bindValue(":tgl_lahir", ui->dateedittgllahirdaftar->date().toString("yyyy-MM-dd")); // Format tanggal sesuai dengan MySQL
            query.bindValue(":jen_kel", ui->cmbjenkeldaftar->currentText());
            query.bindValue(":agama", ui->cmbagamadaftar->currentText());
            query.bindValue(":telpon", ui->edittelepondaftar->text());
            query.bindValue(":alamat", ui->editalamatdaftar->text());
            query.bindValue(":email", ui->editemaildaftar->text());
            query.bindValue(":upload", ui->edituploaddaftar->text());
            query.bindValue(":foto", ui->editfotodaftar->text());
            query.bindValue(":status", ui->editstatusdaftar->text());

            if (query.exec()) {
                QMessageBox::information(this, "Success", "Data berhasil disimpan.");
                ui->editiddaftar->clear();
                ui->editnisdaftar->clear();
                ui->editnamadaftar->clear();
                ui->edittempatdaftar->clear();
                ui->dateedittgllahirdaftar->setDate(QDate::currentDate()); // Set tanggal ke tanggal saat ini
                ui->cmbjenkeldaftar->setCurrentIndex(0);
                ui->cmbagamadaftar->setCurrentIndex(0);
                ui->edittelepondaftar->clear();
                ui->editalamatdaftar->clear();
                ui->editemaildaftar->clear();
                ui->edituploaddaftar->clear();
                ui->editfotodaftar->clear();
                ui->editstatusdaftar->clear();
                daftar::loadDataDAFTAR(); // Panggil fungsi untuk memuat ulang data jika diperlukan
            } else {
                QMessageBox::warning(this, "Error", "Gagal menyimpan data: " + query.lastError().text());
            }
        }
    }
}

void daftar::on_pushButton_2_clicked()
{
    int baris = ui->tableDAFTAR->selectionModel()->currentIndex().row();

    if (baris < 0) {
        QMessageBox::information(this, "Warning", "Silakan Pilih Data Terlebih Dahulu untuk Proses Edit");
        return;
    }

    QString id = ui->editiddaftar->text();
    QString nis = ui->editnisdaftar->text();
    QString nama = ui->editnamadaftar->text();
    QString tempat = ui->edittempatdaftar->text();
    QDate tgl_lahir = ui->dateedittgllahirdaftar->date();
    QString jen_kel = ui->cmbjenkeldaftar->currentText();
    QString agama = ui->cmbagamadaftar->currentText();
    QString telpon = ui->edittelepondaftar->text();
    QString alamat = ui->editalamatdaftar->text();
    QString email = ui->editemaildaftar->text();
    QString upload = ui->edituploaddaftar->text();
    QString foto = ui->editfotodaftar->text();
    QString status = ui->editstatusdaftar->text();

    if (id.isEmpty() || nis.isEmpty() || nama.isEmpty() || tempat.isEmpty() || tgl_lahir.isNull() ||
        jen_kel.isEmpty() || agama.isEmpty() || telpon.isEmpty() || alamat.isEmpty() ||
        email.isEmpty() || upload.isEmpty() || foto.isEmpty() || status.isEmpty()) {
        QMessageBox::information(this, "Warning", "Silakan Isi Semua Data yang Diperlukan untuk Proses Edit");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE daftar SET nis = :nis, nama = :nama, tempat = :tempat, tgl_lahir = :tgl_lahir, jen_kel = :jen_kel, agama = :agama, telpon = :telpon, alamat = :alamat, email = :email, upload = :upload, foto = :foto, status = :status WHERE id = :id");
    query.bindValue(":nis", nis);
    query.bindValue(":nama", nama);
    query.bindValue(":tempat", tempat);
    query.bindValue(":tgl_lahir", tgl_lahir.toString("yyyy-MM-dd")); // Format tanggal sesuai dengan MySQL
    query.bindValue(":jen_kel", jen_kel);
    query.bindValue(":agama", agama);
    query.bindValue(":telpon", telpon);
    query.bindValue(":alamat", alamat);
    query.bindValue(":email", email);
    query.bindValue(":upload", upload);
    query.bindValue(":foto", foto);
    query.bindValue(":status", status);
    query.bindValue(":id", id);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Data berhasil diubah.");
        ui->editiddaftar->clear();
        ui->editnisdaftar->clear();
        ui->editnamadaftar->clear();
        ui->edittempatdaftar->clear();
        ui->dateedittgllahirdaftar->setDate(QDate::currentDate()); // Set tanggal ke tanggal saat ini
        ui->cmbjenkeldaftar->setCurrentIndex(0);
        ui->cmbagamadaftar->setCurrentIndex(0);
        ui->edittelepondaftar->clear();
        ui->editalamatdaftar->clear();
        ui->editemaildaftar->clear();
        ui->edituploaddaftar->clear();
        ui->editfotodaftar->clear();
        ui->editstatusdaftar->clear();
        daftar::loadDataDAFTAR(); // Panggil fungsi untuk memuat ulang data jika diperlukan
    } else {
        QMessageBox::warning(this, "Error", "Gagal mengubah data: " + query.lastError().text());
    }
}

void daftar::on_pushButton_3_clicked()
{
    if(ui->editiddaftar->text().isEmpty() && ui->editnisdaftar->text().isEmpty() && ui->editnamadaftar->text().isEmpty() &&
        ui->edittempatdaftar->text().isEmpty() && ui->dateedittgllahirdaftar->date().isNull() &&
        ui->cmbjenkeldaftar->currentText().isEmpty() && ui->cmbagamadaftar->currentText().isEmpty() &&
        ui->edittelepondaftar->text().isEmpty() && ui->editalamatdaftar->text().isEmpty() &&
        ui->editemaildaftar->text().isEmpty() && ui->edituploaddaftar->text().isEmpty() &&
        ui->editfotodaftar->text().isEmpty() && ui->editstatusdaftar->text().isEmpty())
    {
        QMessageBox::information(this, "Warning", "Silakan Pilih Data Yang Akan Dihapus");
        return;
    } else {
        QSqlQuery hapus;
        hapus.prepare("DELETE FROM daftar WHERE id = :ID");
        hapus.bindValue(":ID", ui->editiddaftar->text().toInt());

        if(hapus.exec()) {
            QMessageBox::information(this, "Success", "Data berhasil dihapus.");
            ui->editiddaftar->clear();
            ui->editnisdaftar->clear();
            ui->editnamadaftar->clear();
            ui->edittempatdaftar->clear();
            ui->dateedittgllahirdaftar->setDate(QDate::currentDate()); // Set tanggal ke tanggal saat ini
            ui->cmbjenkeldaftar->setCurrentIndex(0);
            ui->cmbagamadaftar->setCurrentIndex(0);
            ui->edittelepondaftar->clear();
            ui->editalamatdaftar->clear();
            ui->editemaildaftar->clear();
            ui->edituploaddaftar->clear();
            ui->editfotodaftar->clear();
            ui->editstatusdaftar->clear();
            daftar::loadDataDAFTAR(); // Panggil fungsi untuk memuat ulang data jika diperlukan
        } else {
            QMessageBox::warning(this, "Error", "Gagal menghapus data: " + hapus.lastError().text());
        }
    }
}

void daftar::on_pushButton_4_clicked()
{
    ui->editiddaftar->setText("");
    ui->editnisdaftar->setText("");
    ui->editnamadaftar->setText("");
    ui->edittempatdaftar->setText("");
    ui->dateedittgllahirdaftar->setDate(QDate::currentDate()); // Set tanggal ke tanggal saat ini
    ui->cmbjenkeldaftar->setCurrentIndex(0); // Set combo box ke index pertama
    ui->cmbagamadaftar->setCurrentIndex(0); // Set combo box ke index pertama
    ui->edittelepondaftar->setText("");
    ui->editalamatdaftar->setText("");
    ui->editemaildaftar->setText("");
    ui->edituploaddaftar->setText("");
    ui->editfotodaftar->setText("");
    ui->editstatusdaftar->setText("");
}

void daftar::on_tableDAFTAR_activated(const QModelIndex &index)
{
    int baris = ui->tableDAFTAR->selectionModel()->currentIndex().row();
    ui->editiddaftar->setText(ui->tableDAFTAR->model()->index(baris, 0).data().toString());
    ui->editnisdaftar->setText(ui->tableDAFTAR->model()->index(baris, 1).data().toString());
    ui->editnamadaftar->setText(ui->tableDAFTAR->model()->index(baris, 2).data().toString());
    ui->edittempatdaftar->setText(ui->tableDAFTAR->model()->index(baris, 3).data().toString());
    ui->dateedittgllahirdaftar->setDate(ui->tableDAFTAR->model()->index(baris, 4).data().toDate());
    ui->cmbjenkeldaftar->setCurrentText(ui->tableDAFTAR->model()->index(baris, 5).data().toString());
    ui->cmbagamadaftar->setCurrentText(ui->tableDAFTAR->model()->index(baris, 6).data().toString());
    ui->edittelepondaftar->setText(ui->tableDAFTAR->model()->index(baris, 7).data().toString());
    ui->editalamatdaftar->setText(ui->tableDAFTAR->model()->index(baris, 8).data().toString());
    ui->editemaildaftar->setText(ui->tableDAFTAR->model()->index(baris, 9).data().toString());
    ui->edituploaddaftar->setText(ui->tableDAFTAR->model()->index(baris, 10).data().toString());
    ui->editfotodaftar->setText(ui->tableDAFTAR->model()->index(baris, 11).data().toString());
    ui->editstatusdaftar->setText(ui->tableDAFTAR->model()->index(baris, 12).data().toString());

}

void daftar::loadDataDAFTAR()
{
    crudModel = new QSqlQueryModel(this);
    crudModel->setQuery("SELECT * FROM daftar");  // Mengganti dari tabel daftar ke tabel daftar
    crudModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    crudModel->setHeaderData(1, Qt::Horizontal, QObject::tr("NIS"));
    crudModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Nama"));
    crudModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Tempat"));
    crudModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Tanggal Lahir"));
    crudModel->setHeaderData(5, Qt::Horizontal, QObject::tr("Jenis Kelamin"));
    crudModel->setHeaderData(6, Qt::Horizontal, QObject::tr("Agama"));
    crudModel->setHeaderData(7, Qt::Horizontal, QObject::tr("Telepon"));
    crudModel->setHeaderData(8, Qt::Horizontal, QObject::tr("Alamat"));
    crudModel->setHeaderData(9, Qt::Horizontal, QObject::tr("Email"));
    crudModel->setHeaderData(10, Qt::Horizontal, QObject::tr("Upload"));
    crudModel->setHeaderData(11, Qt::Horizontal, QObject::tr("Foto"));
    crudModel->setHeaderData(12, Qt::Horizontal, QObject::tr("Status"));
    ui->tableDAFTAR->setModel(crudModel);
    ui->tableDAFTAR->setColumnWidth(0, 50);  // Sesuaikan lebar kolom sesuai kebutuhan
    ui->tableDAFTAR->setColumnWidth(1, 100);
    ui->tableDAFTAR->setColumnWidth(2, 150);
    ui->tableDAFTAR->setColumnWidth(3, 100);
    ui->tableDAFTAR->setColumnWidth(4, 100);
    ui->tableDAFTAR->setColumnWidth(5, 80);
    ui->tableDAFTAR->setColumnWidth(6, 100);
    ui->tableDAFTAR->setColumnWidth(7, 100);
    ui->tableDAFTAR->setColumnWidth(8, 200);
    ui->tableDAFTAR->setColumnWidth(9, 150);
    ui->tableDAFTAR->setColumnWidth(10, 100);
    ui->tableDAFTAR->setColumnWidth(11, 100);
    ui->tableDAFTAR->setColumnWidth(12, 100);
    ui->tableDAFTAR->show();
}

