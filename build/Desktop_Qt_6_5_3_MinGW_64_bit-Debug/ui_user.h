/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *editnamauser;
    QLabel *label_2;
    QLineEdit *editusername;
    QLabel *label_3;
    QLineEdit *editpassword;
    QComboBox *cmblevel;
    QLabel *label_4;
    QLineEdit *editiduser;
    QLabel *label_6;
    QLabel *label_5;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableView *tableUSER;

    void setupUi(QDialog *user)
    {
        if (user->objectName().isEmpty())
            user->setObjectName("user");
        user->resize(510, 596);
        formLayoutWidget = new QWidget(user);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(40, 90, 431, 191));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        editnamauser = new QLineEdit(formLayoutWidget);
        editnamauser->setObjectName("editnamauser");

        formLayout->setWidget(1, QFormLayout::FieldRole, editnamauser);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        editusername = new QLineEdit(formLayoutWidget);
        editusername->setObjectName("editusername");

        formLayout->setWidget(2, QFormLayout::FieldRole, editusername);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        editpassword = new QLineEdit(formLayoutWidget);
        editpassword->setObjectName("editpassword");

        formLayout->setWidget(3, QFormLayout::FieldRole, editpassword);

        cmblevel = new QComboBox(formLayoutWidget);
        cmblevel->setObjectName("cmblevel");

        formLayout->setWidget(4, QFormLayout::FieldRole, cmblevel);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        editiduser = new QLineEdit(formLayoutWidget);
        editiduser->setObjectName("editiduser");

        formLayout->setWidget(0, QFormLayout::FieldRole, editiduser);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        label_5 = new QLabel(user);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(200, 30, 81, 21));
        pushButton_1 = new QPushButton(user);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(30, 290, 83, 29));
        pushButton_2 = new QPushButton(user);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(150, 290, 83, 29));
        pushButton_3 = new QPushButton(user);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(270, 290, 83, 29));
        pushButton_4 = new QPushButton(user);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(390, 290, 83, 29));
        tableUSER = new QTableView(user);
        tableUSER->setObjectName("tableUSER");
        tableUSER->setGeometry(QRect(30, 341, 441, 231));

        retranslateUi(user);

        QMetaObject::connectSlotsByName(user);
    } // setupUi

    void retranslateUi(QDialog *user)
    {
        user->setWindowTitle(QCoreApplication::translate("user", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("user", "Nama", nullptr));
        label_2->setText(QCoreApplication::translate("user", "Username", nullptr));
        label_3->setText(QCoreApplication::translate("user", "Password", nullptr));
        label_4->setText(QCoreApplication::translate("user", "Level", nullptr));
        label_6->setText(QCoreApplication::translate("user", "ID", nullptr));
        label_5->setText(QCoreApplication::translate("user", "TABEL USER", nullptr));
        pushButton_1->setText(QCoreApplication::translate("user", "Simpan", nullptr));
        pushButton_2->setText(QCoreApplication::translate("user", "Edit", nullptr));
        pushButton_3->setText(QCoreApplication::translate("user", "Hapus", nullptr));
        pushButton_4->setText(QCoreApplication::translate("user", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class user: public Ui_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
