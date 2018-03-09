#include <QtNetwork/QTcpSocket>
#include "raaNetworking.h"
#include "raaNetworking.moc"

raaNetworking::raaNetworking* raaNetworking::raaNetworking::sm_pInstance = 0;
unsigned int raaNetworking::raaNetworking::sm_uiInstance = 0;
int raaNetworking::raaNetworking::sm_iRead = 0;
int raaNetworking::raaNetworking::sm_iWrite = 0;

void raaNetworking::raaNetworking::start()
{
	if (!sm_uiInstance++ && !sm_pInstance) new raaNetworking();
}

void raaNetworking::raaNetworking::stop()
{
	if (!--sm_uiInstance && sm_pInstance) delete sm_pInstance;
}

raaNetworking::raaNetworking* raaNetworking::raaNetworking::instance()
{
	if (!sm_uiInstance) raaNetworking::start();

	return sm_pInstance;
}

QEvent::Type raaNetworking::raaNetworking::readEvent()
{
	return QEvent::Type(sm_iRead);
}

QEvent::Type raaNetworking::raaNetworking::writeEvent()
{
	return QEvent::Type(sm_iWrite);
}

void raaNetworking::raaNetworking::createServer(QString sName, quint16 uiPort)
{
	
}

void raaNetworking::raaNetworking::createClient(QString sName, quint16 uiPort, QString sIP, bool bTcp, bool bUdp)
{
	
}

void raaNetworking::raaNetworking::closeServer(QString sName)
{
	
}

void raaNetworking::raaNetworking::closeClient(QString sName)
{
	
}

void raaNetworking::raaNetworking::write(raaMessage* pMessage)
{
	
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

void raaNetworking::raaNetworking::customEvent(QEvent* pEvent)
{
	
}
