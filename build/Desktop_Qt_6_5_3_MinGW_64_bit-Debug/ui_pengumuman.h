/********************************************************************************
** Form generated from reading UI file 'pengumuman.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PENGUMUMAN_H
#define UI_PENGUMUMAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pengumuman
{
public:
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *editjudulpengumuman;
    QTextEdit *editisipengumuman;
    QDateEdit *dateeditpengumuman;
    QLabel *label_5;
    QLineEdit *editidpengumuman;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableView *tablePENGUMUMAN;

    void setupUi(QDialog *pengumuman)
    {
        if (pengumuman->objectName().isEmpty())
            pengumuman->setObjectName("pengumuman");
        pengumuman->resize(449, 533);
        label = new QLabel(pengumuman);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 20, 151, 20));
        formLayoutWidget = new QWidget(pengumuman);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(30, 60, 381, 193));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        editjudulpengumuman = new QLineEdit(formLayoutWidget);
        editjudulpengumuman->setObjectName("editjudulpengumuman");

        formLayout->setWidget(1, QFormLayout::FieldRole, editjudulpengumuman);

        editisipengumuman = new QTextEdit(formLayoutWidget);
        editisipengumuman->setObjectName("editisipengumuman");

        formLayout->setWidget(2, QFormLayout::FieldRole, editisipengumuman);

        dateeditpengumuman = new QDateEdit(formLayoutWidget);
        dateeditpengumuman->setObjectName("dateeditpengumuman");

        formLayout->setWidget(3, QFormLayout::FieldRole, dateeditpengumuman);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        editidpengumuman = new QLineEdit(formLayoutWidget);
        editidpengumuman->setObjectName("editidpengumuman");

        formLayout->setWidget(0, QFormLayout::FieldRole, editidpengumuman);

        pushButton_1 = new QPushButton(pengumuman);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(30, 280, 83, 29));
        pushButton_2 = new QPushButton(pengumuman);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(130, 280, 83, 29));
        pushButton_3 = new QPushButton(pengumuman);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(230, 280, 83, 29));
        pushButton_4 = new QPushButton(pengumuman);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(330, 280, 83, 29));
        tablePENGUMUMAN = new QTableView(pengumuman);
        tablePENGUMUMAN->setObjectName("tablePENGUMUMAN");
        tablePENGUMUMAN->setGeometry(QRect(30, 330, 381, 171));

        retranslateUi(pengumuman);

        QMetaObject::connectSlotsByName(pengumuman);
    } // setupUi

    void retranslateUi(QDialog *pengumuman)
    {
        pengumuman->setWindowTitle(QCoreApplication::translate("pengumuman", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("pengumuman", "TABEL PENGUMUMAN", nullptr));
        label_2->setText(QCoreApplication::translate("pengumuman", "Judul", nullptr));
        label_3->setText(QCoreApplication::translate("pengumuman", "Isi", nullptr));
        label_4->setText(QCoreApplication::translate("pengumuman", "Tanggal", nullptr));
        label_5->setText(QCoreApplication::translate("pengumuman", "ID", nullptr));
        pushButton_1->setText(QCoreApplication::translate("pengumuman", "Simpan", nullptr));
        pushButton_2->setText(QCoreApplication::translate("pengumuman", "Edit", nullptr));
        pushButton_3->setText(QCoreApplication::translate("pengumuman", "Hapus", nullptr));
        pushButton_4->setText(QCoreApplication::translate("pengumuman", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pengumuman: public Ui_pengumuman {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PENGUMUMAN_H
