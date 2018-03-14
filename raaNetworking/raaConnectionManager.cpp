#include "raaConnection.h"
#include "raaConnectionListener.h"
#include "raaConnectionManager.h"

raaNetworking::raaConnectionManager::raaConnectionManager(quint16 uiPort, raaConnectionListenerFactory *pFactory) : m_pFactory(pFactory), m_uiPort(uiPort)
{
}

raaNetworking::raaConnectionManager::~raaConnectionManager()
{
	if (m_pFactory) delete m_pFactory;
	raaConnectionList l = m_lConnections;
	m_lConnections.clear();
	for (raaConnectionList::iterator it = l.begin(); it != l.end(); it++)(*it)->close();
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

raaNetworking::raaConnectionListener* raaNetworking::raaConnectionManager::createListener(raaConnection* pConnection)
{
	if (m_pFactory) return m_pFactory->create(pConnection);
	return 0;
}
