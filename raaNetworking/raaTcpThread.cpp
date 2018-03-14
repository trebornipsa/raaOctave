#include <QtCore/QCoreApplication>

#include "raaMessage.h"
#include <iostream>

#include "raaNetworking.h"
#include "raaTcpThread.h"
#include "raaTcpThread.moc"
#include "raaNetworkingTypes.h"

raaNetworking::raaTcpThread::raaTcpThread(QString sAddress, quint16 uiPort, QObject* pParent) : QThread(pParent), m_sAddress(sAddress), m_piSocketDescriptor(0), m_uiPort(uiPort), m_bServer(false), m_pSocket(0)
{
}

raaNetworking::raaTcpThread::raaTcpThread(qintptr piSocketDescriptor, QObject* pParent) : QThread(pParent), m_uiPort(0), m_piSocketDescriptor(piSocketDescriptor), m_bServer(true), m_pSocket(0)
{
}

void raaNetworking::raaTcpThread::close()
{
	m_pSocket->disconnectFromHost();
}

void raaNetworking::raaTcpThread::send(raaMessage* pMsg)
{
	if (m_pSocket) QCoreApplication::postEvent(m_pSocket, pMsg);
	else QCoreApplication::postEvent(this, pMsg);
}

void raaNetworking::raaTcpThread::readyRead()
{
	while (m_pSocket->bytesAvailable())
	{
		qint64 iSize = 0;
		unsigned short usType = 0;
		m_pSocket->read((char*)&usType, sizeof(unsigned short));
		m_pSocket->read((char*)&iSize, sizeof(unsigned int));

		if (iSize > 0)
		{
			QByteArray b;
			b.append(m_pSocket->read(iSize));
			if (b.length() == iSize) 	QCoreApplication::postEvent(this, new raaMessage(b, usType, readEvent()));
		}
	}
}

void raaNetworking::raaTcpThread::disconnected()
{
	m_pSocket->close();
	m_pSocket->deleteLater();
	m_pSocket = 0;
	quit();
}



void raaNetworking::raaTcpThread::run()
{
	if (!m_pSocket)
	{
		m_pSocket = new raaTcpSocket();
		connect(m_pSocket, SIGNAL(disconnected()), SLOT(disconnected()));

		if (m_bServer)
		{
			if (m_pSocket->setSocketDescriptor(m_piSocketDescriptor))
			{
				connect(m_pSocket, SIGNAL(readyRead()), SLOT(readyRead()));
				exec();
			}
		}
		else
		{
			m_pSocket->connectToHost(m_sAddress, m_uiPort);
			connect(m_pSocket, SIGNAL(readyRead()), SLOT(readyRead()));
			exec();
		}
	}
}

void raaNetworking::raaTcpThread::customEvent(QEvent* pEvent)
{
	if (pEvent)
	{
		if (pEvent->type() == readEvent())
		{
			m_Mutex.lock();
			raaMessage *pMsg = static_cast<raaMessage*>(pEvent);
			receive(pMsg);
			m_Mutex.unlock();
		}
	}
}

raaNetworking::raaTcpThread::~raaTcpThread()
{
	if (m_pSocket)
	{
		m_pSocket->close();
		m_pSocket->deleteLater();
		m_pSocket = 0;
	}
}

