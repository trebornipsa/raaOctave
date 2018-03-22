// raaNetworkingTestClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <QtWidgets/QApplication>
#include <raaNetworking/raaNetworking.h>
#include <raaNetworking/raaConnectionListener.h>
#include <raaNetworking/raaConnection.h>
#include <raaNetworking/raaMessage.h>
#include <iostream>
#include "raaClientInterface.h"
#include "raaConnection.h"

/*
class raaConnection : public raaNetworking::raaConnectionListener
{
public:
	raaConnection(raaNetworking::raaConnection *pConnection) : raaConnectionListener(pConnection)
	{
		if (!sm_pInstance) sm_pInstance = this;
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

	static raaConnection* sm_pInstance;

protected:
	virtual ~raaConnection()
	{
		if (sm_pInstance == this) sm_pInstance = 0;
	};
};

class raaConnectionFactory : public raaNetworking::raaConnectionListenerFactory
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
//	raaNetworking::raaNetworking::instance()->createClient("client", "localhost", 65201, new raaConnectionFactory());

	raaClientInterface *pInterface = new raaClientInterface();
	pInterface->show();
	a.exec();

//	raaNetworking::raaNetworking::stop(); 

	return 0;
}
