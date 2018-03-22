/********************************************************************************
** Form generated from reading UI file 'raaServerInterfaceQt.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef RAASERVERINTERFACEQT_H
#define RAASERVERINTERFACEQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_raaServerInterfaceQt
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLineEdit *message;
    QPushButton *send_button;
    QTextEdit *output;

    void setupUi(QMainWindow *raaServerInterfaceQt)
    {
        if (raaServerInterfaceQt->objectName().isEmpty())
            raaServerInterfaceQt->setObjectName(QStringLiteral("raaServerInterfaceQt"));
        raaServerInterfaceQt->resize(800, 600);
        centralwidget = new QWidget(raaServerInterfaceQt);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        message = new QLineEdit(frame);
        message->setObjectName(QStringLiteral("message"));

        horizontalLayout->addWidget(message);

        send_button = new QPushButton(frame);
        send_button->setObjectName(QStringLiteral("send_button"));

        horizontalLayout->addWidget(send_button);


        verticalLayout->addWidget(frame);

        output = new QTextEdit(centralwidget);
        output->setObjectName(QStringLiteral("output"));
        output->setReadOnly(true);

        verticalLayout->addWidget(output);

        raaServerInterfaceQt->setCentralWidget(centralwidget);

        retranslateUi(raaServerInterfaceQt);

        QMetaObject::connectSlotsByName(raaServerInterfaceQt);
    } // setupUi

    void retranslateUi(QMainWindow *raaServerInterfaceQt)
    {
        raaServerInterfaceQt->setWindowTitle(QApplication::translate("raaServerInterfaceQt", "Server", 0));
        send_button->setText(QApplication::translate("raaServerInterfaceQt", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class raaServerInterfaceQt: public Ui_raaServerInterfaceQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // RAASERVERINTERFACEQT_H
