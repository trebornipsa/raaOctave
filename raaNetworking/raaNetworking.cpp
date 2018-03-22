#include "raaTcpClient.h"
#include "raaTcpServer.h"
#include "raaNetworking.h"
#include "raaNetworking.moc"
#include <iostream>

raaNetworking::raaNetworking* raaNetworking::raaNetworking::sm_pInstance = 0;
unsigned int raaNetworking::raaNetworking::sm_uiInstance = 0;
int raaNetworking::raaNetworking::sm_iReadEvent = 0;
int raaNetworking::raaNetworking::sm_iWriteEvent = 0;
int raaNetworking::raaNetworking::sm_iCompression = 2;

void raaNetworking::raaNetworking::start(QObject *pParent)
{
	if (!sm_uiInstance++ && !sm_pInstance) new raaNetworking(pParent);
}

void raaNetworking::raaNetworking::stop()
{
	if (!--sm_uiInstance && sm_pInstance) delete sm_pInstance;
}

bool raaNetworking::raaNetworking::createServer(QString sName, quint16 uiPort, raaConnectionListenerFactory* pFactory, bool bCanDeleteFactory)
{
	if(pFactory && sName.length() && m_mServersByName.find(sName)==m_mServersByName.end() && m_mServersByPort.find(uiPort)==m_mServersByPort.end())
	{
		raaTcpServer *pServer = new raaTcpServer(uiPort, pFactory, bCanDeleteFactory);
		m_mServersByPort[uiPort] = pServer;
		m_mServersByName[sName] = pServer;
		return true;
	}
	return false;
}

bool raaNetworking::raaNetworking::createClient(QString sName, QString sHostAddress, quint16 uiPort, raaConnectionListenerFactory* pFactory, bool bCanDeleteFactory)
{
	if (pFactory && sName.length() && m_mClientsByName.find(sName) == m_mClientsByName.end() && m_mClientsByPort.find(uiPort) == m_mClientsByPort.end())
	{
		raaTcpClient *pClient = new raaTcpClient(sHostAddress, uiPort, pFactory, bCanDeleteFactory);
		m_mClientsByPort[uiPort] = pClient;
		m_mClientsByName[sName] = pClient;
		return true;
	}
	return false;
}

void raaNetworking::raaNetworking::closeServer(QString sName)
{
	if(sName.length() && m_mServersByName.find(sName)!=m_mServersByName.end())
	{
		raaConnectionManager* pManager = m_mServersByName[sName];
		m_mServersByPort.erase(pManager->port());
		m_mServersByName.erase(sName);
		delete pManager;
	}
}

void raaNetworking::raaNetworking::closeClient(QString sName)
{
	if (sName.length() && m_mClientsByName.find(sName) != m_mClientsByName.end())
	{
		raaConnectionManager* pManager = m_mClientsByName[sName];
		m_mClientsByPort.erase(pManager->port());
		m_mClientsByName.erase(sName);
		delete pManager;
	}
}

raaNetworking::raaNetworking* raaNetworking::raaNetworking::instance()
{
	if (!sm_uiInstance) raaNetworking::start(0);

	return sm_pInstance;
}

raaNetworking::raaNetworking::raaNetworking(QObject* pParent): QObject(pParent)
{
	if (!sm_pInstance)
	{
		sm_pInstance = this;
		sm_iReadEvent = QEvent::registerEventType();
		sm_iWriteEvent = QEvent::registerEventType();
		qRegisterMetaType<QAbstractSocket::SocketState>();
	}
}

raaNetworking::raaNetworking::~raaNetworking()
{
	std::cout << "raaNetworking deleted" << std::endl;
	if (sm_pInstance == this) delete sm_pInstance;
}

QEvent::Type raaNetworking::raaNetworking::readEvent()
{
	return QEvent::Type(sm_iReadEvent);
}

void raaNetworking::raaNetworking::setCompression(int iCompression)
{
	sm_iCompression = iCompression;
	if (sm_iCompression < -1) sm_iCompression = -1;
	else if (sm_iCompression > 9) sm_iCompression = 9;
}

int raaNetworking::raaNetworking::compression()
{
	return sm_iCompression;
}

QEvent::Type raaNetworking::raaNetworking::writeEvent()
{
	return QEvent::Type(sm_iWriteEvent);
}

