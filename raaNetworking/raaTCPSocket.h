#pragma once

#include <QtNetwork/QTcpSocket>
#include <QtCore/QMutex>

#include "raaSocket.h"

#include "raaNetworkingDefs.h"

namespace raaNetworking
{
	class RAANETWORKING_DLL_DEF raaTcpSocket: public QTcpSocket, public raaSocket
	{
		Q_OBJECT
	public:
		raaTcpSocket(QObject*pParent=0);
		virtual ~raaTcpSocket();
		virtual raaTcpSocket* asTcpSocket();
		virtual raaUdpSocket* asUdpSocket();

		virtual void read();
		virtual void disconnect();
		virtual void delaidDelete();
		virtual void close();
	protected:
		QMutex m_Mutex;
		
		virtual void customEvent(QEvent *pEvent);
	};
}
