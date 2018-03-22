#include "stdafx.h"

#include <raaNetworking/raaNetworking.h>
#include "raaConnection.h"

#include "raaClientInterface.h"
#include "raaClientInterface.moc"

raaClientInterface* raaClientInterface::sm_pInstance = 0;

raaClientInterface::raaClientInterface()
{
	raaNetworking::raaNetworking::start(this);
	if (!sm_pInstance) sm_pInstance = 0;
	setupUi(this);
	connect(message, SIGNAL(returnPressed()), SLOT(read()));
	connect(connectButton, SIGNAL(clicked()), SLOT(connectClient()));
	connect(send_button, SIGNAL(clicked()), SLOT(send()));

}


raaClientInterface::~raaClientInterface()
{
	if (sm_pInstance == this) sm_pInstance = 0;
	raaNetworking::raaNetworking::stop();
}

void raaClientInterface::read()
{
	QLineEdit *pMessage = dynamic_cast<QLineEdit*>(sender());

	if (pMessage && raaConnection::sm_pInstance)
	{
		raaConnection::sm_pInstance->post(pMessage->text().toStdString());
	}
}

void raaClientInterface::connectClient()
{
	quint16 uiPort = port_edit->text().toUShort();
	raaNetworking::raaNetworking::instance()->createClient("client", "localhost", uiPort, new raaConnectionFactory()); 
}

void raaClientInterface::send()
{
	std::string s = "fish";

	raaConnection::sm_pInstance->post(s);
}
