#pragma once

#include <QtCore/QMutex>
#include <QtNetwork/QTcpSocket>
#include "raaNetworkingDefs.h"


namespace raaNetworking
{
	class RAANETWORKING_DLL_DEF raaTcpSocket : public QTcpSocket
	{
		Q_OBJECT
	public:
		raaTcpSocket(QObject *pParent = 0);
		virtual ~raaTcpSocket();
	protected:
		virtual void customEvent(QEvent *pEvent);
		QMutex m_Mutex;

	};
}
