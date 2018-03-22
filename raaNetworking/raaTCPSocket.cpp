#include "raaNetworking.h"

#include "raaMessage.h"
#include "raaTcpSocket.h"
#include "raaTcpSocket.moc"
#include "raaNetworkingTypes.h"
#include <iostream>


raaNetworking::raaTcpSocket::raaTcpSocket(QObject *pParent) : QTcpSocket(pParent)
{
}

raaNetworking::raaTcpSocket::~raaTcpSocket()
{
	std::cout << "raaTcpSocket deleted" << std::endl;
	close();
}

void raaNetworking::raaTcpSocket::customEvent(QEvent* pEvent)
{
	if (pEvent)
	{
		if (pEvent->type() == raaNetworking::writeEvent())
		{
			m_Mutex.lock();
			raaMessage *pMsg = static_cast<raaMessage*>(pEvent);
			long long iSize = pMsg->data().length();
			unsigned short usType = pMsg->type();
			unsigned int uiMessageID = pMsg->messageID();
			write((const char*)&usType, sizeof(unsigned short));
			write((const char*)&iSize, sizeof(long long));
			write((const char*)&uiMessageID, sizeof(unsigned int));
			write(pMsg->data().data(), iSize);
			m_Mutex.unlock();
		}
	}
}
