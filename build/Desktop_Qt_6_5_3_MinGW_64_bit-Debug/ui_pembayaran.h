/********************************************************************************
** Form generated from reading UI file 'pembayaran.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEMBAYARAN_H
#define UI_PEMBAYARAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pembayaran
{
public:
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *editnis;
    QDateEdit *dateeditbayar;
    QComboBox *cmbstatus;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *editidpembayaran;
    QTableView *tablePEMBAYARAN;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *pembayaran)
    {
        if (pembayaran->objectName().isEmpty())
            pembayaran->setObjectName("pembayaran");
        pembayaran->resize(459, 508);
        label = new QLabel(pembayaran);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 30, 141, 20));
        formLayoutWidget = new QWidget(pembayaran);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(40, 70, 381, 151));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        editnis = new QLineEdit(formLayoutWidget);
        editnis->setObjectName("editnis");

        formLayout->setWidget(1, QFormLayout::FieldRole, editnis);

        dateeditbayar = new QDateEdit(formLayoutWidget);
        dateeditbayar->setObjectName("dateeditbayar");

        formLayout->setWidget(2, QFormLayout::FieldRole, dateeditbayar);

        cmbstatus = new QComboBox(formLayoutWidget);
        cmbstatus->setObjectName("cmbstatus");

        formLayout->setWidget(3, QFormLayout::FieldRole, cmbstatus);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        editidpembayaran = new QLineEdit(formLayoutWidget);
        editidpembayaran->setObjectName("editidpembayaran");

        formLayout->setWidget(0, QFormLayout::FieldRole, editidpembayaran);

        tablePEMBAYARAN = new QTableView(pembayaran);
        tablePEMBAYARAN->setObjectName("tablePEMBAYARAN");
        tablePEMBAYARAN->setGeometry(QRect(40, 290, 381, 192));
        pushButton_1 = new QPushButton(pembayaran);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(40, 240, 83, 29));
        pushButton_2 = new QPushButton(pembayaran);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(140, 240, 83, 29));
        pushButton_3 = new QPushButton(pembayaran);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(240, 240, 83, 29));
        pushButton_4 = new QPushButton(pembayaran);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(340, 240, 83, 29));

        retranslateUi(pembayaran);

        QMetaObject::connectSlotsByName(pembayaran);
    } // setupUi

    void retranslateUi(QDialog *pembayaran)
    {
        pembayaran->setWindowTitle(QCoreApplication::translate("pembayaran", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("pembayaran", "TABEL PEMBAYARAN", nullptr));
        label_2->setText(QCoreApplication::translate("pembayaran", "NIS", nullptr));
        label_3->setText(QCoreApplication::translate("pembayaran", "Tanggal Bayar", nullptr));
        label_4->setText(QCoreApplication::translate("pembayaran", "Status", nullptr));
        label_5->setText(QCoreApplication::translate("pembayaran", "ID", nullptr));
        pushButton_1->setText(QCoreApplication::translate("pembayaran", "Simpan", nullptr));
        pushButton_2->setText(QCoreApplication::translate("pembayaran", "Edit", nullptr));
        pushButton_3->setText(QCoreApplication::translate("pembayaran", "Hapus", nullptr));
        pushButton_4->setText(QCoreApplication::translate("pembayaran", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pembayaran: public Ui_pembayaran {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEMBAYARAN_H
