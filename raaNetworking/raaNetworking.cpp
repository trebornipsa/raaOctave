#include "raaTcpClient.h"
#include "raaTcpServer.h"
#include "raaNetworking.h"
#include "raaNetworking.moc"

raaNetworking::raaNetworking* raaNetworking::raaNetworking::sm_pInstance = 0;
unsigned int raaNetworking::raaNetworking::sm_uiInstance = 0;

void raaNetworking::raaNetworking::start()
{
	if (!sm_uiInstance++ && !sm_pInstance) new raaNetworking();
}

void raaNetworking::raaNetworking::stop()
{
	if (!--sm_uiInstance && sm_pInstance) delete sm_pInstance;
}

bool raaNetworking::raaNetworking::createServer(QString sName, quint16 uiPort, raaConnectionListenerFactory* pFactory)
{
	if(pFactory && sName.length() && m_mServersByName.find(sName)==m_mServersByName.end() && m_mServersByPort.find(uiPort)==m_mServersByPort.end())
	{
		raaTcpServer *pServer = new raaTcpServer(uiPort, pFactory);
		m_mServersByPort[uiPort] = pServer;
		m_mServersByName[sName] = pServer;
		return true;
	}
	return false;
}

bool raaNetworking::raaNetworking::createClient(QString sName, QString sHostAddress, quint16 uiPort, raaConnectionListenerFactory* pFactory)
{
	if (pFactory && sName.length() && m_mClientsByName.find(sName) == m_mClientsByName.end() && m_mClientsByPort.find(uiPort) == m_mClientsByPort.end())
	{
		raaTcpClient *pClient = new raaTcpClient(sHostAddress, uiPort, pFactory);
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
	if (!sm_uiInstance) raaNetworking::start();

	return sm_pInstance;
}



raaNetworking::raaNetworking::raaNetworking()
{
	if(!sm_pInstance) sm_pInstance = this;
	sm_iRead = QEvent::registerEventType();
	sm_iWrite = QEvent::registerEventType();
	qRegisterMetaType<QAbstractSocket::SocketState>();
}

raaNetworking::raaNetworking::~raaNetworking()
{
	if (sm_pInstance == this) delete sm_pInstance;
}

