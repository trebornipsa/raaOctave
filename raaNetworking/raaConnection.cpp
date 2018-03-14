
#include "raaConnectionListener.h"
#include "raaConnectionManager.h"
#include "raaMessage.h"
#include "raaConnection.h"

raaNetworking::raaConnection::raaConnection(): m_pConnectionListener(0)
{
}

void raaNetworking::raaConnection::setListener(raaConnectionListener *pListener)
{
	destroyListener();
	m_pConnectionListener = pListener;
}

void raaNetworking::raaConnection::destroyListener()
{
	if (m_pConnectionListener)
	{
		delete m_pConnectionListener;
		m_pConnectionListener = 0;
	}
}

void raaNetworking::raaConnection::receive(raaMessage* pMessage)
{
	if (pMessage && m_pConnectionListener) m_pConnectionListener->receive(pMessage);
}

raaNetworking::raaMessage* raaNetworking::raaConnection::createMessage(unsigned short usType)
{
	return new raaMessage(usType, writeEvent());
}

raaNetworking::raaConnection::~raaConnection()
{
	destroyListener();
}
