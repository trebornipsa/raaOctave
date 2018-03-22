#include "raaConnection.h"
#include "raaConnectionListener.h"
#include <iostream>

raaNetworking::raaConnectionListener::raaConnectionListener(raaConnection *pConnection, bool bCanDelete): m_pConnection(pConnection), m_bCanDelete(bCanDelete)
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

raaNetworking::raaMessage* raaNetworking::raaConnectionListener::createMessage(unsigned short usType)
{
	if (m_pConnection) return m_pConnection->createMessage(usType);
	return 0;
}

bool raaNetworking::raaConnectionListener::canDelete()
{
	return m_bCanDelete;
}

void raaNetworking::raaConnectionListener::setDeleteable(bool bCanDelete)
{
	m_bCanDelete = bCanDelete;
}

raaNetworking::raaConnectionListener::~raaConnectionListener()
{
	std::cout << "raaConnectionListener deleted" << std::endl;
}
