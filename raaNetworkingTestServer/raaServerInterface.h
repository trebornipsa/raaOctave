#pragma once

#include <QtWidgets\QMainWindow>
#include "raaServerInterfaceQt.h"

class raaServerInterface: public QMainWindow, public Ui::raaServerInterfaceQt
{
	Q_OBJECT
public:
	raaServerInterface();
	virtual ~raaServerInterface();
	static raaServerInterface* sm_pInstance;
	public slots:
	void read();


};

