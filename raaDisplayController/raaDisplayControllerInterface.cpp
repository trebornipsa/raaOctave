#include "stdafx.h"

#include <iostream>

#include <raaNetworking/raaNetworking.h>

#include "raaDisplayControlConnection.h"
#include "raaDisplayControllerInterface.h"
#include "raaDisplayControllerInterface.moc"



raaDisplayControllerInterface::raaDisplayControllerInterface() : m_pConnection(0), m_bConnected(false)
{
	raaNetworking::raaNetworking::start(0);
	setupUi(this);
	statusbar->showMessage("Disconnected");
	connect(connection_connect_button, SIGNAL(clicked()), SLOT(connectDisconnect()));
}
 

raaDisplayControllerInterface::~raaDisplayControllerInterface()
{
	raaNetworking::raaNetworking::stop();
}

raaNetworking::raaConnectionListener* raaDisplayControllerInterface::create(raaNetworking::raaConnection* pConnection)
{
	if (!m_pConnection)
	{
		m_pConnection = new raaDisplayControlConnection(pConnection, this);
		return new raaDisplayControlConnection(pConnection, this);
	}
	return 0;
}

void raaDisplayControllerInterface::setControlConnected(bool bState)
{
	m_bConnected = bState;

	if(bState)
	{
		connection_connect_button->setText("Disconnect");
//		statusbar->showMessage("Connected");
	}
	else
	{
		connection_connect_button->setText("Connect");
//		statusbar->showMessage("Disconnected");
		m_pConnection = 0;
	}
}

void raaDisplayControllerInterface::connectDisconnect()
{
	if(m_bConnected)
	{
		raaNetworking::raaNetworking::instance()->closeClient(QString("control"));
		statusbar->showMessage("Disconected");
	}
	else
	{
		QString sAddress = connection_address_edit->text();
		quint16 uiPort = connection_port_edit->text().toUShort();
		raaNetworking::raaNetworking::instance()->createClient(QString("control"), sAddress, uiPort, this, false);
		statusbar->showMessage("Connected");
	}
}
