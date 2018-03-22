/********************************************************************************
** Form generated from reading UI file 'raaClientInterfaceQt.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef RAACLIENTINTERFACEQT_H
#define RAACLIENTINTERFACEQT_H

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

class Ui_raaClientInterfaceQt
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *message;
    QPushButton *send_button;
    QTextEdit *output;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLineEdit *port_edit;
    QPushButton *connectButton;

    void setupUi(QMainWindow *raaClientInterfaceQt)
    {
        if (raaClientInterfaceQt->objectName().isEmpty())
            raaClientInterfaceQt->setObjectName(QStringLiteral("raaClientInterfaceQt"));
        raaClientInterfaceQt->resize(1268, 901);
        centralwidget = new QWidget(raaClientInterfaceQt);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        message = new QLineEdit(frame_2);
        message->setObjectName(QStringLiteral("message"));

        horizontalLayout_2->addWidget(message);

        send_button = new QPushButton(frame_2);
        send_button->setObjectName(QStringLiteral("send_button"));

        horizontalLayout_2->addWidget(send_button);


        verticalLayout->addWidget(frame_2);

        output = new QTextEdit(centralwidget);
        output->setObjectName(QStringLiteral("output"));
        output->setReadOnly(true);

        verticalLayout->addWidget(output);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        port_edit = new QLineEdit(frame);
        port_edit->setObjectName(QStringLiteral("port_edit"));

        horizontalLayout->addWidget(port_edit);

        connectButton = new QPushButton(frame);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        horizontalLayout->addWidget(connectButton);


        verticalLayout->addWidget(frame);

        raaClientInterfaceQt->setCentralWidget(centralwidget);

        retranslateUi(raaClientInterfaceQt);

        QMetaObject::connectSlotsByName(raaClientInterfaceQt);
    } // setupUi

    void retranslateUi(QMainWindow *raaClientInterfaceQt)
    {
        raaClientInterfaceQt->setWindowTitle(QApplication::translate("raaClientInterfaceQt", "Client", 0));
        send_button->setText(QApplication::translate("raaClientInterfaceQt", "Send", 0));
        port_edit->setText(QApplication::translate("raaClientInterfaceQt", "65201", 0));
        connectButton->setText(QApplication::translate("raaClientInterfaceQt", "Connect", 0));
    } // retranslateUi

};

namespace Ui {
    class raaClientInterfaceQt: public Ui_raaClientInterfaceQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // RAACLIENTINTERFACEQT_H
