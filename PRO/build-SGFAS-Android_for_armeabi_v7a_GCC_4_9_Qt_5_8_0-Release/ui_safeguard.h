/********************************************************************************
** Form generated from reading UI file 'safeguard.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAFEGUARD_H
#define UI_SAFEGUARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SafeGuard
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QListWidget *list;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_scan;
    QCheckBox *checkBox_discoverable;
    QPushButton *pushButton_openBluetooth;
    QPushButton *pushButton_disconnect;
    QPushButton *pushButton_closeDevice;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_stateText;
    QPushButton *pushButton_alartLed;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QLabel *imageLabel;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QPushButton *pushButton_id;
    QPushButton *pushButton_idx;
    QPushButton *pushButton_readImage;
    QPushButton *pushButton_warning;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_recovery_check;

    void setupUi(QWidget *SafeGuard)
    {
        if (SafeGuard->objectName().isEmpty())
            SafeGuard->setObjectName(QStringLiteral("SafeGuard"));
        SafeGuard->resize(446, 924);
        verticalLayout_4 = new QVBoxLayout(SafeGuard);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox = new QGroupBox(SafeGuard);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        list = new QListWidget(groupBox);
        list->setObjectName(QStringLiteral("list"));

        verticalLayout_2->addWidget(list);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_scan = new QPushButton(groupBox);
        pushButton_scan->setObjectName(QStringLiteral("pushButton_scan"));
        pushButton_scan->setStyleSheet(QStringLiteral(""));

        gridLayout_3->addWidget(pushButton_scan, 0, 1, 1, 1);

        checkBox_discoverable = new QCheckBox(groupBox);
        checkBox_discoverable->setObjectName(QStringLiteral("checkBox_discoverable"));
        checkBox_discoverable->setMaximumSize(QSize(800, 400));
        checkBox_discoverable->setStyleSheet(QStringLiteral(""));

        gridLayout_3->addWidget(checkBox_discoverable, 0, 2, 1, 1);

        pushButton_openBluetooth = new QPushButton(groupBox);
        pushButton_openBluetooth->setObjectName(QStringLiteral("pushButton_openBluetooth"));

        gridLayout_3->addWidget(pushButton_openBluetooth, 0, 0, 1, 1);

        pushButton_disconnect = new QPushButton(groupBox);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));

        gridLayout_3->addWidget(pushButton_disconnect, 1, 0, 1, 1);

        pushButton_closeDevice = new QPushButton(groupBox);
        pushButton_closeDevice->setObjectName(QStringLiteral("pushButton_closeDevice"));

        gridLayout_3->addWidget(pushButton_closeDevice, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(SafeGuard);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        label_stateText = new QLabel(groupBox_2);
        label_stateText->setObjectName(QStringLiteral("label_stateText"));
        label_stateText->setMinimumSize(QSize(100, 20));

        gridLayout_2->addWidget(label_stateText, 0, 1, 1, 1);

        pushButton_alartLed = new QPushButton(groupBox_2);
        pushButton_alartLed->setObjectName(QStringLiteral("pushButton_alartLed"));

        gridLayout_2->addWidget(pushButton_alartLed, 2, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);


        verticalLayout_4->addWidget(groupBox_2);

        textBrowser = new QTextBrowser(SafeGuard);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_4->addWidget(textBrowser);

        groupBox_3 = new QGroupBox(SafeGuard);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        imageLabel = new QLabel(groupBox_3);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setMinimumSize(QSize(400, 400));
        imageLabel->setMaximumSize(QSize(400, 400));

        horizontalLayout->addWidget(imageLabel);


        verticalLayout_4->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(SafeGuard);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_id = new QPushButton(groupBox_4);
        pushButton_id->setObjectName(QStringLiteral("pushButton_id"));

        gridLayout->addWidget(pushButton_id, 0, 0, 1, 1);

        pushButton_idx = new QPushButton(groupBox_4);
        pushButton_idx->setObjectName(QStringLiteral("pushButton_idx"));

        gridLayout->addWidget(pushButton_idx, 0, 1, 1, 1);

        pushButton_readImage = new QPushButton(groupBox_4);
        pushButton_readImage->setObjectName(QStringLiteral("pushButton_readImage"));

        gridLayout->addWidget(pushButton_readImage, 0, 2, 1, 1);

        pushButton_warning = new QPushButton(groupBox_4);
        pushButton_warning->setObjectName(QStringLiteral("pushButton_warning"));

        gridLayout->addWidget(pushButton_warning, 1, 0, 1, 1);

        pushButton_clear = new QPushButton(groupBox_4);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));

        gridLayout->addWidget(pushButton_clear, 1, 1, 1, 1);

        pushButton_recovery_check = new QPushButton(groupBox_4);
        pushButton_recovery_check->setObjectName(QStringLiteral("pushButton_recovery_check"));

        gridLayout->addWidget(pushButton_recovery_check, 1, 2, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);


        verticalLayout_4->addWidget(groupBox_4);

        QWidget::setTabOrder(pushButton_openBluetooth, checkBox_discoverable);
        QWidget::setTabOrder(checkBox_discoverable, list);
        QWidget::setTabOrder(list, pushButton_alartLed);
        QWidget::setTabOrder(pushButton_alartLed, pushButton_scan);
        QWidget::setTabOrder(pushButton_scan, pushButton_warning);
        QWidget::setTabOrder(pushButton_warning, pushButton_readImage);
        QWidget::setTabOrder(pushButton_readImage, pushButton_id);
        QWidget::setTabOrder(pushButton_id, pushButton_clear);

        retranslateUi(SafeGuard);

        QMetaObject::connectSlotsByName(SafeGuard);
    } // setupUi

    void retranslateUi(QWidget *SafeGuard)
    {
        SafeGuard->setWindowTitle(QApplication::translate("SafeGuard", "SafeGuard", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SafeGuard", "\344\277\241\345\217\267\350\277\236\346\216\245\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("SafeGuard", "\350\256\276\345\244\207\345\210\227\350\241\250\357\274\232", Q_NULLPTR));
        pushButton_scan->setText(QApplication::translate("SafeGuard", " \346\211\253\346\217\217\350\256\276\345\244\207", Q_NULLPTR));
        checkBox_discoverable->setText(QApplication::translate("SafeGuard", "  \350\223\235\347\211\231\345\217\257\350\247\201", Q_NULLPTR));
        pushButton_openBluetooth->setText(QApplication::translate("SafeGuard", "\346\211\223\345\274\200\350\256\276\345\244\207", Q_NULLPTR));
        pushButton_disconnect->setText(QApplication::translate("SafeGuard", "\346\226\255\345\274\200\350\277\236\346\216\245", Q_NULLPTR));
        pushButton_closeDevice->setText(QApplication::translate("SafeGuard", "\345\205\263\351\227\255\350\256\276\345\244\207", Q_NULLPTR));
        label_3->setText(QApplication::translate("SafeGuard", "\346\217\220\347\244\272\357\274\232\350\257\267\347\241\256\345\256\232\351\223\276\346\216\245\346\255\243\347\241\256\347\232\204\350\256\276\345\244\207\357\274\201", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("SafeGuard", "\350\277\220\350\241\214\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("SafeGuard", "\347\212\266\346\200\201\346\214\207\347\244\272\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("SafeGuard", "\346\212\245\350\255\246\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_stateText->setText(QApplication::translate("SafeGuard", "\345\276\205\346\234\272\344\270\255....", Q_NULLPTR));
        pushButton_alartLed->setText(QString());
        groupBox_3->setTitle(QApplication::translate("SafeGuard", "\345\233\276\345\203\217\345\233\236\344\274\240\345\214\272\345\237\237\357\274\232", Q_NULLPTR));
        imageLabel->setText(QApplication::translate("SafeGuard", "\345\233\276\345\203\217\345\214\272\345\237\237", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("SafeGuard", "\346\216\247\345\210\266\345\214\272\345\237\237\357\274\232", Q_NULLPTR));
        pushButton_id->setText(QApplication::translate("SafeGuard", "\350\272\253\344\273\275\350\256\244\350\257\201", Q_NULLPTR));
        pushButton_idx->setText(QApplication::translate("SafeGuard", "\350\272\253\344\273\275\350\256\244\350\257\201\345\217\226\346\266\210", Q_NULLPTR));
        pushButton_readImage->setText(QApplication::translate("SafeGuard", "\350\257\273\345\217\226\345\233\276\345\203\217", Q_NULLPTR));
        pushButton_warning->setText(QApplication::translate("SafeGuard", "\350\257\255\351\237\263\345\226\212\350\257\235", Q_NULLPTR));
        pushButton_clear->setText(QApplication::translate("SafeGuard", "\346\270\205\351\231\244\346\212\245\350\255\246\347\212\266\346\200\201", Q_NULLPTR));
        pushButton_recovery_check->setText(QApplication::translate("SafeGuard", "\346\201\242\345\244\215\346\243\200\346\265\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SafeGuard: public Ui_SafeGuard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAFEGUARD_H
