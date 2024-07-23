/********************************************************************************
** Form generated from reading UI file 'daftar.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAFTAR_H
#define UI_DAFTAR_H

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

class Ui_daftar
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *editnisdaftar;
    QLabel *label_2;
    QLineEdit *editnamadaftar;
    QLabel *label_3;
    QLineEdit *edittempatdaftar;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QDateEdit *dateedittgllahirdaftar;
    QComboBox *cmbjenkeldaftar;
    QComboBox *cmbagamadaftar;
    QLabel *label_14;
    QLineEdit *editiddaftar;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *edittelepondaftar;
    QLineEdit *editalamatdaftar;
    QLineEdit *editemaildaftar;
    QLineEdit *edituploaddaftar;
    QLineEdit *editfotodaftar;
    QLineEdit *editstatusdaftar;
    QTableView *tableDAFTAR;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_13;

    void setupUi(QDialog *daftar)
    {
        if (daftar->objectName().isEmpty())
            daftar->setObjectName("daftar");
        daftar->resize(1043, 747);
        formLayoutWidget = new QWidget(daftar);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(40, 70, 451, 241));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        editnisdaftar = new QLineEdit(formLayoutWidget);
        editnisdaftar->setObjectName("editnisdaftar");

        formLayout->setWidget(1, QFormLayout::FieldRole, editnisdaftar);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        editnamadaftar = new QLineEdit(formLayoutWidget);
        editnamadaftar->setObjectName("editnamadaftar");

        formLayout->setWidget(2, QFormLayout::FieldRole, editnamadaftar);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        edittempatdaftar = new QLineEdit(formLayoutWidget);
        edittempatdaftar->setObjectName("edittempatdaftar");

        formLayout->setWidget(3, QFormLayout::FieldRole, edittempatdaftar);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        dateedittgllahirdaftar = new QDateEdit(formLayoutWidget);
        dateedittgllahirdaftar->setObjectName("dateedittgllahirdaftar");

        formLayout->setWidget(4, QFormLayout::FieldRole, dateedittgllahirdaftar);

        cmbjenkeldaftar = new QComboBox(formLayoutWidget);
        cmbjenkeldaftar->setObjectName("cmbjenkeldaftar");

        formLayout->setWidget(5, QFormLayout::FieldRole, cmbjenkeldaftar);

        cmbagamadaftar = new QComboBox(formLayoutWidget);
        cmbagamadaftar->setObjectName("cmbagamadaftar");

        formLayout->setWidget(6, QFormLayout::FieldRole, cmbagamadaftar);

        label_14 = new QLabel(formLayoutWidget);
        label_14->setObjectName("label_14");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_14);

        editiddaftar = new QLineEdit(formLayoutWidget);
        editiddaftar->setObjectName("editiddaftar");

        formLayout->setWidget(0, QFormLayout::FieldRole, editiddaftar);

        formLayoutWidget_2 = new QWidget(daftar);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(520, 70, 481, 221));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(formLayoutWidget_2);
        label_7->setObjectName("label_7");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(formLayoutWidget_2);
        label_8->setObjectName("label_8");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(formLayoutWidget_2);
        label_9->setObjectName("label_9");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_9);

        label_10 = new QLabel(formLayoutWidget_2);
        label_10->setObjectName("label_10");

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_10);

        label_11 = new QLabel(formLayoutWidget_2);
        label_11->setObjectName("label_11");

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_11);

        label_12 = new QLabel(formLayoutWidget_2);
        label_12->setObjectName("label_12");

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_12);

        edittelepondaftar = new QLineEdit(formLayoutWidget_2);
        edittelepondaftar->setObjectName("edittelepondaftar");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, edittelepondaftar);

        editalamatdaftar = new QLineEdit(formLayoutWidget_2);
        editalamatdaftar->setObjectName("editalamatdaftar");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, editalamatdaftar);

        editemaildaftar = new QLineEdit(formLayoutWidget_2);
        editemaildaftar->setObjectName("editemaildaftar");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, editemaildaftar);

        edituploaddaftar = new QLineEdit(formLayoutWidget_2);
        edituploaddaftar->setObjectName("edituploaddaftar");

        formLayout_2->setWidget(3, QFormLayout::FieldRole, edituploaddaftar);

        editfotodaftar = new QLineEdit(formLayoutWidget_2);
        editfotodaftar->setObjectName("editfotodaftar");

        formLayout_2->setWidget(4, QFormLayout::FieldRole, editfotodaftar);

        editstatusdaftar = new QLineEdit(formLayoutWidget_2);
        editstatusdaftar->setObjectName("editstatusdaftar");

        formLayout_2->setWidget(5, QFormLayout::FieldRole, editstatusdaftar);

        tableDAFTAR = new QTableView(daftar);
        tableDAFTAR->setObjectName("tableDAFTAR");
        tableDAFTAR->setGeometry(QRect(40, 430, 961, 271));
        pushButton_1 = new QPushButton(daftar);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(40, 360, 171, 29));
        pushButton_2 = new QPushButton(daftar);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(280, 360, 191, 29));
        pushButton_3 = new QPushButton(daftar);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(540, 360, 191, 29));
        pushButton_4 = new QPushButton(daftar);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(830, 360, 171, 29));
        label_13 = new QLabel(daftar);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(450, 20, 101, 20));

        retranslateUi(daftar);

        QMetaObject::connectSlotsByName(daftar);
    } // setupUi

    void retranslateUi(QDialog *daftar)
    {
        daftar->setWindowTitle(QCoreApplication::translate("daftar", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("daftar", "NIS", nullptr));
        label_2->setText(QCoreApplication::translate("daftar", "Nama", nullptr));
        label_3->setText(QCoreApplication::translate("daftar", "Tempat Lhr", nullptr));
        label_4->setText(QCoreApplication::translate("daftar", "Tanggal Lhr", nullptr));
        label_5->setText(QCoreApplication::translate("daftar", "JenKel", nullptr));
        label_6->setText(QCoreApplication::translate("daftar", "Agama", nullptr));
        label_14->setText(QCoreApplication::translate("daftar", "ID", nullptr));
        label_7->setText(QCoreApplication::translate("daftar", "Telepon", nullptr));
        label_8->setText(QCoreApplication::translate("daftar", "Alamat", nullptr));
        label_9->setText(QCoreApplication::translate("daftar", "Email", nullptr));
        label_10->setText(QCoreApplication::translate("daftar", "Foto", nullptr));
        label_11->setText(QCoreApplication::translate("daftar", "Upload", nullptr));
        label_12->setText(QCoreApplication::translate("daftar", "Status", nullptr));
        pushButton_1->setText(QCoreApplication::translate("daftar", "Simpan", nullptr));
        pushButton_2->setText(QCoreApplication::translate("daftar", "Edit", nullptr));
        pushButton_3->setText(QCoreApplication::translate("daftar", "Hapus", nullptr));
        pushButton_4->setText(QCoreApplication::translate("daftar", "Clear", nullptr));
        label_13->setText(QCoreApplication::translate("daftar", "TABEL DAFTAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class daftar: public Ui_daftar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAFTAR_H
