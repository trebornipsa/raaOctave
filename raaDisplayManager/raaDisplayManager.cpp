// raaDisplayManager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <QtCore/QCoreApplication>
#include <raaDisplaySystem/raaDisplaySystem.h>
//#include <raaNetworking/raaNetworking.h>

int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);
//	raaNetworking::raaNetworking::start(0);

	raaDisplaySystem::raaDisplaySystem *pSystem = new raaDisplaySystem::raaDisplaySystem(65201);

//	raaDisplaySystem::raaDisplaySystem::start(65201);


	a.exec();

//	raaNetworking::raaNetworking::stop();

    return 0;
}

