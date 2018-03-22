#pragma once

#include <QtWidgets/QMainWindow>

#include <raaNetworking/raaConnectionListener.h>

#include "raaDisplayControllerInterfaceQt.h"

class raaDisplayControlConnection;

class raaDisplayControllerInterface: public QMainWindow, public Ui::raaDisplayControllerInterfaceQt, public raaNetworking::raaConnectionListenerFactory
{
private:
	Q_OBJECT
public:
	raaDisplayControllerInterface();
	virtual ~raaDisplayControllerInterface();
	virtual raaNetworking::raaConnectionListener* create(raaNetworking::raaConnection* pConnection);

	void setControlConnected(bool bState);

public slots:
	void connectDisconnect();
protected:
	raaDisplayControlConnection* m_pConnection;
	bool m_bConnected;
};

