#include "raaNetworking.h"

#include "raaMessage.h"
#include "raaTcpSocket.h"
#include "raaTcpSocket.moc"
#include "raaNetworkingTypes.h"


raaNetworking::raaTcpSocket::raaTcpSocket(QObject *pParent) : QTcpSocket(pParent)
{
}

raaNetworking::raaTcpSocket::~raaTcpSocket()
{
}

void raaNetworking::raaTcpSocket::customEvent(QEvent* pEvent)
{
	if (pEvent)
	{
		if (pEvent->type() == writeEvent())
		{
			m_Mutex.lock();
			raaMessage *pMsg = static_cast<raaMessage*>(pEvent);
			unsigned int iSize = pMsg->data().length();
			unsigned short usType = pMsg->type();
			write((const char*)&usType, sizeof(unsigned short));
			write((const char*)&iSize, sizeof(unsigned int));
			write(pMsg->data().data(), iSize);
			m_Mutex.unlock();
		}
	}
}
