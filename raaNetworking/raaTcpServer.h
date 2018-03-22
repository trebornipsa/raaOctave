#pragma once

#include <QtNetwork/QTcpServer>

#include "raaNetworkingTypes.h"
#include "raaConnectionManager.h"

namespace raaNetworking
{
	class raaTcpThread;
	class raaTcpServer: public QTcpServer, public raaConnectionManager
	{
		Q_OBJECT
	public:
		raaTcpServer(quint16 uiPort, raaConnectionListenerFactory *pFactory, bool bCanDeleteFactory=true, QObject* pParent=0);
		virtual ~raaTcpServer();

	public slots:
		void stateChanged(QAbstractSocket::SocketState, raaConnection*);

	protected:
		quint16 m_uiPort;

		void incomingConnection(qintptr piSocketDescriptor) Q_DECL_OVERRIDE;
	};
}
