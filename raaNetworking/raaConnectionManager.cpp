#include "raaConnection.h"
#include "raaConnectionListener.h"
#include "raaConnectionManager.h"
#include <iostream>

raaNetworking::raaConnectionManager::raaConnectionManager(quint16 uiPort, raaConnectionListenerFactory *pFactory, bool bCanDeleteFactory) : m_pFactory(pFactory), m_uiPort(uiPort), m_bCanDeleteFactory(bCanDeleteFactory)
{
}

raaNetworking::raaConnectionManager::~raaConnectionManager()
{
	std::cout << "raaConnectionManager deleted" << std::endl;
	if (m_pFactory && m_bCanDeleteFactory) delete m_pFactory;
	raaConnectionList l = m_lConnections;
	for (raaConnectionList::iterator it = l.begin(); it != l.end(); it++) (*it)->close();
}

void raaNetworking::raaConnectionManager::addConnection(raaConnection* pConnection)
{
	if (pConnection && std::find(m_lConnections.begin(), m_lConnections.end(), pConnection) == m_lConnections.end())
	{
		m_lConnections.push_back(pConnection);
		pConnection->setListener(createListener(pConnection));
	}
}

void raaNetworking::raaConnectionManager::removeConnection(raaConnection* pConnection)
{
	if (pConnection && std::find(m_lConnections.begin(), m_lConnections.end(), pConnection) != m_lConnections.end())
	{
		m_lConnections.remove(pConnection);
		pConnection->destroyListener();
	}
}

quint16 raaNetworking::raaConnectionManager::port()
{
	return m_uiPort;
}

void raaNetworking::raaConnectionManager::send(raaMessage* pMessage)
{
	if(pMessage)
	{
		for (raaConnectionList::iterator it = m_lConnections.begin(); it != m_lConnections.end(); it++) (*it)->send(pMessage);
	}
}


raaNetworking::raaConnectionListener* raaNetworking::raaConnectionManager::createListener(raaConnection* pConnection)
{
	if (m_pFactory) return m_pFactory->create(pConnection);
	return 0;
}
