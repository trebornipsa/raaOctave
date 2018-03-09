#include <QtCore/QCoreApplication>
#include "raaNetworking.h"
#include "raaMessage.h"

#include "raaTcpSocket.h"
#include "raaTcpSocket.moc"


raaNetworking::raaTcpSocket::raaTcpSocket(QObject *pParent): QTcpSocket(pParent)
{
}


raaNetworking::raaTcpSocket* raaNetworking::raaTcpSocket::asTcpSocket()
{
	return this;
}

raaNetworking::raaUdpSocket* raaNetworking::raaTcpSocket::asUdpSocket()
{
	return 0;
}

void raaNetworking::raaTcpSocket::read()
{
	while(bytesAvailable())
	{
		qint64 iSize = 0;
		QTcpSocket::read((char*)&iSize, sizeof(unsigned int));

		if (iSize > 0)
		{
			QByteArray b;
			b.append(QTcpSocket::read(iSize));
			if (b.length() == iSize) 	QCoreApplication::postEvent(raaNetworking::instance(), new raaMessage(this, b, raaNetworking::readEvent()));
		}
	}
}

void raaNetworking::raaTcpSocket::disconnect()
{
	disconnectFromHost();
}

void raaNetworking::raaTcpSocket::delaidDelete()
{
	QTcpSocket::deleteLater();
}

void raaNetworking::raaTcpSocket::close()
{
	QTcpSocket::close();
}

raaNetworking::raaTcpSocket::~raaTcpSocket()
{
}


void raaNetworking::raaTcpSocket::customEvent(QEvent* pEvent)
{
	if (pEvent)
	{
		if (pEvent->type() == raaNetworking::writeEvent())
		{
			m_Mutex.lock();
			raaMessage *pMsg = static_cast<raaMessage>(pEvent);
			unsigned int iSize = pMsg->data().length();
			write((const char*)&iSize, sizeof(unsigned int));
			write(pMsg->data().data(), iSize);
			m_Mutex.unlock();
		}
	}

}
