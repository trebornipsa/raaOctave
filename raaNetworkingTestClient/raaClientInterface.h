#pragma once

#include <QtWidgets\QMainWindow>
#include "raaClientInterfaceQt.h"


class raaClientInterface : public QMainWindow, public Ui::raaClientInterfaceQt
{
	Q_OBJECT
public:
	raaClientInterface();
	virtual ~raaClientInterface();
	static raaClientInterface* sm_pInstance;
	public slots:
	void read();
	void connectClient();
	void send();


};
