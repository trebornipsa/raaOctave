
#include "raaConnectionListener.h"
#include "raaConnectionManager.h"
#include "raaMessage.h"
#include "raaConnection.h"
#include "raaNetworkingTypes.h"
#include "raaNetworking.h"
#include <iostream>

raaNetworking::raaConnection::raaConnection(QString sAddress, quint16 uiPort, bool bServer): m_pConnectionListener(0), m_bServer(bServer), m_sAddress(sAddress), m_uiPort(uiPort)
{
}

void raaNetworking::raaConnection::setListener(raaConnectionListener *pListener)
{
	destroyListener();
	m_pConnectionListener = pListener;
}

void raaNetworking::raaConnection::destroyListener()
{
	if (m_pConnectionListener && m_pConnectionListener->canDelete()) delete m_pConnectionListener;
	m_pConnectionListener = 0;
}

void raaNetworking::raaConnection::receive(raaMessage* pMessage)
{
	if (pMessage && m_pConnectionListener)
	{
		switch (pMessage->type())
		{
			case csm_usTcpMsgInfo:
			case csm_usTcpMsgReply:
			{
				m_pConnectionListener->receive(pMessage);
				break;
			}
			case csm_usTcpMsgRequest:
			{
				raaMessage *pReply = new raaMessage(csm_usTcpMsgReply, raaNetworking::writeEvent());
				pReply->m_uiMessageID = pMessage->m_uiMessageID;
				m_pConnectionListener->receive(pMessage, pReply);
				send(pReply);
				break;
			}
		}
	}
}

quint16 raaNetworking::raaConnection::port()
{
	return m_uiPort;
}

QString raaNetworking::raaConnection::address()
{
	return m_sAddress;
}

raaNetworking::raaMessage* raaNetworking::raaConnection::createMessage(unsigned short usType)
{
	return new raaMessage(usType, raaNetworking::writeEvent());
}

bool raaNetworking::raaConnection::isServer()
{
	return m_bServer;
}

raaNetworking::raaConnection::~raaConnection()
{
	std::cout << "raaConnection deleted" << std::endl;
	destroyListener();
}
