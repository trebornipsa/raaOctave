#include "stdafx.h"
#include "raaConnection.h"

raaConnection* raaConnection::sm_pInstance = 0;

raaConnection::raaConnection(raaNetworking::raaConnection* pConnection) : raaConnectionListener(pConnection)
{
	if (!sm_pInstance) sm_pInstance = this;
}

void raaConnection::receive(raaNetworking::raaMessage* pMessage, raaNetworking::raaMessage* pReply) 
{
	std::string s = pMessage->asString(0);
	std::cout << "\tIncoming -> " << s << std::endl;
}

void raaConnection::post(std::string s) 
{
	raaNetworking::raaMessage* pMsg = createMessage(raaNetworking::csm_usTcpMsgInfo);
	pMsg->add(s);
	send(pMsg);
}

raaConnection::~raaConnection() {
	if (sm_pInstance == this) sm_pInstance = 0;
}

raaConnectionFactory::raaConnectionFactory()
{
	
}

raaConnectionFactory::~raaConnectionFactory()
{
	
}

raaNetworking::raaConnectionListener* raaConnectionFactory::create(raaNetworking::raaConnection* pConnection) 
{
	return new raaConnection(pConnection);
}
