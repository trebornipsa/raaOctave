#pragma once

#include <QtCore/QObject>
#include <QtNetwork/QHostAddress>

#include "raaConnectionManager.h"
#include "raaNetworkingTypes.h"
#include "raaNetworkingDefs.h"

namespace raaNetworking
{
	class raaTcpThread;
	class raaConnection;

	class RAANETWORKING_DLL_DEF raaTcpClient: public QObject, public raaConnectionManager
	{
		Q_OBJECT
	public:
		raaTcpClient(QString sHostAddress, quint16 uiPort, raaConnectionListenerFactory* pFactory, bool bCanDeleteFactory=true);
		virtual ~raaTcpClient();

		raaConnection* createConnection(QString sHostAddress, quint16 uiPort);
		void closeConnection(raaConnection* pConnection);

	public slots:
		void stateChanged(QAbstractSocket::SocketState, raaConnection*);

	protected:
		raaTcpThread* m_pThread;
	};
}
