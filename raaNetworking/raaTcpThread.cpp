//#include <stdint.h>
#include <iostream>
#include <QtCore/QCoreApplication>

#include "raaMessage.h"
#include "raaNetworking.h"
#include "raaNetworkingTypes.h"
#include "raaTcpThread.h"
#include "raaTcpThread.moc"

raaNetworking::raaTcpThread::raaTcpThread(QString sAddress, quint16 uiPort, QObject* pParent) : QThread(pParent), raaConnection(sAddress, uiPort, false), m_piSocketDescriptor(0), m_pSocket(0)
{
}

raaNetworking::raaTcpThread::raaTcpThread(qintptr piSocketDescriptor, QString sAddress, quint16 uiPort, QObject* pParent) : QThread(pParent), raaConnection(sAddress, uiPort, true), m_piSocketDescriptor(piSocketDescriptor), m_pSocket(0)
{
}

void raaNetworking::raaTcpThread::send(raaMessage* pMsg)
{
	if (m_pSocket) QCoreApplication::postEvent(m_pSocket, pMsg);
	else QCoreApplication::postEvent(this, pMsg);
}

void raaNetworking::raaTcpThread::close()
{
	m_pSocket->disconnectFromHost();
}

void raaNetworking::raaTcpThread::readyRead()
{
	while (m_pSocket->bytesAvailable())
	{
		qint64 iSize = 0;
		unsigned short usType = 0;
		unsigned int uiMessageID = 0;
		m_pSocket->read((char*)&usType, sizeof(unsigned short));
		m_pSocket->read((char*)&iSize, sizeof(qint64));
		m_pSocket->read((char*)&uiMessageID, sizeof(unsigned int));

		if (iSize > 0)
		{
			QByteArray b;
			b.append(m_pSocket->read(iSize));
			if (b.length() == iSize) 	QCoreApplication::postEvent(this, new raaMessage(b, usType, raaNetworking::readEvent(), this, uiMessageID));
		}
	}
}

void raaNetworking::raaTcpThread::disconnected()
{
	if (m_pSocket)
	{
		m_pSocket->close();
//		m_pSocket->deleteLater();
		m_pSocket = 0;
	}
	quit();
}

void raaNetworking::raaTcpThread::tcpStateChanged(QAbstractSocket::SocketState state)
{
	emit(stateChanged(state, this));
}

void raaNetworking::raaTcpThread::run()
{
	if (!m_pSocket)
	{
		m_pSocket = new raaTcpSocket();  
		connect(m_pSocket, SIGNAL(disconnected()), SLOT(disconnected()), Qt::DirectConnection);
		connect(this, SIGNAL(finished()), m_pSocket, SLOT(deleteLater()));
		//		connect(m_pSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(tcpStateChanged(QAbstractSocket::SocketState)), Qt::DirectConnection);
		connect(m_pSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(tcpStateChanged(QAbstractSocket::SocketState)));

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
		if (pEvent->type() == raaNetworking::readEvent())
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
	std::cout << "raaTcpThread deleted" << std::endl;
	if (m_pSocket)
	{
		disconnect(m_pSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
		m_pSocket->close();
//		m_pSocket->deleteLater();
		m_pSocket = 0;
	}
//	quit(); 
}

