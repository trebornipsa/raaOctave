#include <QtCore/QCoreApplication>

#include "raaSocket.h"
#include "raaSocketThread.h"
#include "raaSocketThread.moc"



raaNetworking::raaSocketThread::raaSocketThread()
{
}


void raaNetworking::raaSocketThread::run()
{
	
}

raaNetworking::raaSocketThread::~raaSocketThread()
{
	if (m_pSocket)
	{
		m_pSocket->close();
		m_pSocket->delaidDelete();
		m_pSocket = 0;
	}
}

void raaNetworking::raaSocketThread::close()
{
	if (m_pSocket) m_pSocket->disconnect();
}

void raaNetworking::raaSocketThread::write(raaMessage* pMsg)
{
	if (m_pSocket)
		QCoreApplication::postEvent(m_pSocket, pMsg);
	else
		QCoreApplication::postEvent(this, pMsg);
}

void raaNetworking::raaSocketThread::readyRead()
{
	if (m_pSocket) m_pSocket->read();
}

void raaNetworking::raaSocketThread::disconnected()
{
	m_pSocket->close();
	m_pSocket->delaidDelete();
	m_pSocket = 0;
	quit();

}

void raaNetworking::raaSocketThread::stateChanged(QAbstractSocket::SocketState state)
{
	emit stateChanged(this, state);
}

QString raaNetworking::raaSocketThread::name()
{
	return m_sName;
}
