#pragma once

#include <raaNetworking/raaConnectionListener.h>

class raaDisplayControllerInterface;

class raaDisplayControlConnection: public raaNetworking::raaConnectionListener
{
public:
	raaDisplayControlConnection(raaNetworking::raaConnection* pConnection, raaDisplayControllerInterface* pInterface);
	virtual ~raaDisplayControlConnection();

	virtual void receive(raaNetworking::raaMessage* pMessage, raaNetworking::raaMessage* pReply);
protected:
	raaDisplayControllerInterface* m_pInterface;

};

