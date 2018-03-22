#pragma once

#include <raaNetworking/raaConnectionListener.h>
#include <raaNetworking/raaNetworkingTypes.h>
#include <string>
#include <iostream>

//class raaConnection* g_pConnection = 0;

class raaConnection : public raaNetworking::raaConnectionListener
{
public:
	raaConnection(raaNetworking::raaConnection* pConnection);;

	virtual void receive(raaNetworking::raaMessage* pMessage, raaNetworking::raaMessage* pReply);

	void post(std::string s);

	static raaConnection* sm_pInstance;

protected:
	virtual ~raaConnection();
	
};


class raaConnectionFactory : public raaNetworking::raaConnectionListenerFactory
{
public:
	raaConnectionFactory();;
	virtual ~raaConnectionFactory();;
	virtual raaNetworking::raaConnectionListener* create(raaNetworking::raaConnection* pConnection);
};

