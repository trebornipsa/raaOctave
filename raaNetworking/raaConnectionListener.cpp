#include "raaConnection.h"
#include "raaConnectionListener.h"

raaNetworking::raaConnectionListener::raaConnectionListener(raaConnection *pConnection)
{
}

raaNetworking::raaConnectionListenerFactory::raaConnectionListenerFactory()
{
	
}

raaNetworking::raaConnectionListenerFactory::~raaConnectionListenerFactory()
{
	
}

bool raaNetworking::raaConnectionListener::send(raaMessage* pMessage)
{
	if(m_pConnection && pMessage)
	{
		m_pConnection->send(pMessage);
		return true;
	}
	return false;
}

raaNetworking::raaConnectionListener::~raaConnectionListener()
{
}
