// raaDisplayController.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <QtWidgets/QApplication>

#include "raaDisplayControllerInterface.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	raaDisplayControllerInterface* pInterface = new raaDisplayControllerInterface();
	pInterface->show();

	a.exec();

    return 0;
}

