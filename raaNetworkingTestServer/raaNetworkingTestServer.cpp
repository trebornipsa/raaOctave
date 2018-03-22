// raaNetworkingTestServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <QtWidgets\QApplication>
#include <raaNetworking/raaNetworking.h>
#include <raaNetworking/raaConnectionListener.h>
#include <raaNetworking/raaConnection.h>
#include <raaNetworking/raaMessage.h>
#include <iostream>
#include "raaServerInterface.h"
#include "raaConnection.h"
/*
class raaConnection* g_pConnection = 0;

class raaConnection: public raaNetworking::raaConnectionListener
{
public:
	raaConnection(raaNetworking::raaConnection *pConnection): raaConnectionListener(pConnection)
	{
		if (!g_pConnection) g_pConnection = this;
	};

	virtual void receive(raaNetworking::raaMessage* pMessage)
	{
		std::string s = pMessage->asString(0);
		std::cout << "\tIncoming -> " << s << std::endl;
	}

	void post(std::string s)
	{
		raaNetworking::raaMessage* pMsg = createMessage(raaNetworking::csm_usTcpMsgInfo);
		pMsg->add(s);
		send(pMsg);
	}

protected:
	virtual ~raaConnection()
	{
		if (g_pConnection == this) g_pConnection = 0;
	};
};


class raaConnectionFactory: public raaNetworking::raaConnectionListenerFactory
{
public:
	raaConnectionFactory() {};
	virtual ~raaConnectionFactory() {};
	virtual raaNetworking::raaConnectionListener* create(raaNetworking::raaConnection* pConnection)
	{
		return new raaConnection(pConnection);
	}
};
*/
int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

//	raaNetworking::raaNetworking::start();
//	raaNetworking::raaNetworking::instance()->createServer("server", 65201, new raaConnectionFactory());

	raaServerInterface *pInterface = new raaServerInterface();
	pInterface->show();
	a.exec();

//	raaNetworking::raaNetworking::stop();

    return 0;
}

