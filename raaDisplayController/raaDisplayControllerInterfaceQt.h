/********************************************************************************
** Form generated from reading UI file 'raaDisplayControllerInterfaceQt.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef RAADISPLAYCONTROLLERINTERFACEQT_H
#define RAADISPLAYCONTROLLERINTERFACEQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_raaDisplayControllerInterfaceQt
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tab_widget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLineEdit *connection_address_edit;
    QLineEdit *connection_port_edit;
    QPushButton *connection_connect_button;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *system_server_status_label;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *system_serverside_load_button;
    QPushButton *system_serverside_save_button;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *system_clientside_load_button;
    QPushButton *system_clientside_save_button;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *display_addremove_name_edit;
    QPushButton *display_addremove_add_button;
    QPushButton *display_addremove_remove_button;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QWidget *tab_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *raaDisplayControllerInterfaceQt)
    {
        if (raaDisplayControllerInterfaceQt->objectName().isEmpty())
            raaDisplayControllerInterfaceQt->setObjectName(QStringLiteral("raaDisplayControllerInterfaceQt"));
        raaDisplayControllerInterfaceQt->resize(523, 279);
        centralwidget = new QWidget(raaDisplayControllerInterfaceQt);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tab_widget = new QTabWidget(centralwidget);
        tab_widget->setObjectName(QStringLiteral("tab_widget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        frame = new QFrame(tab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        connection_address_edit = new QLineEdit(frame);
        connection_address_edit->setObjectName(QStringLiteral("connection_address_edit"));

        horizontalLayout->addWidget(connection_address_edit);

        connection_port_edit = new QLineEdit(frame);
        connection_port_edit->setObjectName(QStringLiteral("connection_port_edit"));

        horizontalLayout->addWidget(connection_port_edit);

        connection_connect_button = new QPushButton(frame);
        connection_connect_button->setObjectName(QStringLiteral("connection_connect_button"));

        horizontalLayout->addWidget(connection_connect_button);


        verticalLayout_2->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 849, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tab_widget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_4);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        system_server_status_label = new QLabel(groupBox_4);
        system_server_status_label->setObjectName(QStringLiteral("system_server_status_label"));

        horizontalLayout_6->addWidget(system_server_status_label);


        verticalLayout->addWidget(groupBox_4);

        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        system_serverside_load_button = new QPushButton(groupBox_2);
        system_serverside_load_button->setObjectName(QStringLiteral("system_serverside_load_button"));

        horizontalLayout_4->addWidget(system_serverside_load_button);

        system_serverside_save_button = new QPushButton(groupBox_2);
        system_serverside_save_button->setObjectName(QStringLiteral("system_serverside_save_button"));

        horizontalLayout_4->addWidget(system_serverside_save_button);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_3);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        system_clientside_load_button = new QPushButton(groupBox_3);
        system_clientside_load_button->setObjectName(QStringLiteral("system_clientside_load_button"));

        horizontalLayout_5->addWidget(system_clientside_load_button);

        system_clientside_save_button = new QPushButton(groupBox_3);
        system_clientside_save_button->setObjectName(QStringLiteral("system_clientside_save_button"));

        horizontalLayout_5->addWidget(system_clientside_save_button);


        verticalLayout->addWidget(groupBox_3);

        verticalSpacer_3 = new QSpacerItem(20, 721, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        tab_widget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        horizontalLayout_2 = new QHBoxLayout(tab_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        splitter = new QSplitter(tab_3);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 205, 154));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        display_addremove_name_edit = new QLineEdit(groupBox);
        display_addremove_name_edit->setObjectName(QStringLiteral("display_addremove_name_edit"));

        horizontalLayout_3->addWidget(display_addremove_name_edit);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 2);

        display_addremove_add_button = new QPushButton(page);
        display_addremove_add_button->setObjectName(QStringLiteral("display_addremove_add_button"));

        gridLayout_2->addWidget(display_addremove_add_button, 1, 0, 1, 1);

        display_addremove_remove_button = new QPushButton(page);
        display_addremove_remove_button->setObjectName(QStringLiteral("display_addremove_remove_button"));

        gridLayout_2->addWidget(display_addremove_remove_button, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 675, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 0, 1, 1);

        toolBox->addItem(page, QStringLiteral("Add/Remove"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 100, 30));
        toolBox->addItem(page_2, QStringLiteral("Screen"));
        splitter->addWidget(toolBox);
        tabWidget_2 = new QTabWidget(splitter);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget_2->addTab(tab_5, QString());
        splitter->addWidget(tabWidget_2);

        horizontalLayout_2->addWidget(splitter);

        tab_widget->addTab(tab_3, QString());

        gridLayout->addWidget(tab_widget, 0, 0, 1, 1);

        raaDisplayControllerInterfaceQt->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(raaDisplayControllerInterfaceQt);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        raaDisplayControllerInterfaceQt->setStatusBar(statusbar);

        retranslateUi(raaDisplayControllerInterfaceQt);

        tab_widget->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(raaDisplayControllerInterfaceQt);
    } // setupUi

    void retranslateUi(QMainWindow *raaDisplayControllerInterfaceQt)
    {
        raaDisplayControllerInterfaceQt->setWindowTitle(QApplication::translate("raaDisplayControllerInterfaceQt", "MainWindow", nullptr));
        connection_address_edit->setText(QApplication::translate("raaDisplayControllerInterfaceQt", "localhost", nullptr));
        connection_port_edit->setText(QApplication::translate("raaDisplayControllerInterfaceQt", "65201", nullptr));
        connection_connect_button->setText(QApplication::translate("raaDisplayControllerInterfaceQt", "Connect", nullptr));
        tab_widget->setTabText(tab_widget->indexOf(tab), QApplication::translate("raaDisplayControllerInterfaceQt", "Connection", nullptr));
        groupBox_4->setTitle(QApplication::translate("raaDisplayControllerInterfaceQt", "Server Status", nullptr));
        system_server_status_label->setText(QApplication::translate("raaDisplayControllerInterfaceQt", "UnKnown", nullptr));
        groupBox_2->setTitle(QApplication::translate("raaDisplayControllerInterfaceQt", "Server Side", nullptr));
        system_serverside_load_button->setText(QApplication::translate("raaDisplayControllerInterfaceQt", "Load", nullptr));
        system_serverside_save_button->setText(QApplication::translate("raaDisplayControllerInterfaceQt", "Save", nullptr));
        groupBox_3->setTitle(QApplication::translate("raaDisplayControllerInterfaceQt", "Client Side", nullptr));
        system_clientside_load_button->setText(QApplication::translate("raaDisplayControllerInterfaceQt", "Load", nullptr));
        system_clientside_save_button->setText(QApplication::translate("raaDisplayControllerInterfaceQt", "Save", nullptr));
        tab_widget->setTabText(tab_widget->indexOf(tab_2), QApplication::translate("raaDisplayControllerInterfaceQt", "System", nullptr));
        groupBox->setTitle(QApplication::translate("raaDisplayControllerInterfaceQt", "Screen Name", nullptr));
        display_addremove_add_button->setText(QApplication::translate("raaDisplayControllerInterfaceQt", "Add", nullptr));
        display_addremove_remove_button->setText(QApplication::translate("raaDisplayControllerInterfaceQt", "Remove", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("raaDisplayControllerInterfaceQt", "Add/Remove", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("raaDisplayControllerInterfaceQt", "Screen", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("raaDisplayControllerInterfaceQt", "Physical Layout", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("raaDisplayControllerInterfaceQt", "Display Morphology", nullptr));
        tab_widget->setTabText(tab_widget->indexOf(tab_3), QApplication::translate("raaDisplayControllerInterfaceQt", "Display", nullptr));
    } // retranslateUi

};

namespace Ui {
    class raaDisplayControllerInterfaceQt: public Ui_raaDisplayControllerInterfaceQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // RAADISPLAYCONTROLLERINTERFACEQT_H
