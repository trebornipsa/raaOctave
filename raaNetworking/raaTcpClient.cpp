#include "raaTcpThread.h"

#include "raaTcpClient.h"
#include "raaTcpClient.moc"
#include <iostream>

raaNetworking::raaTcpClient::raaTcpClient(QString sHostAddress, quint16 uiPort, raaConnectionListenerFactory* pFactory, bool bCanDeleteFactory): raaConnectionManager(uiPort, pFactory, bCanDeleteFactory)
{
	m_pThread = new raaTcpThread(sHostAddress, uiPort, this);
	connect(m_pThread, SIGNAL(finished()), m_pThread, SLOT(deleteLater()));
	connect(m_pThread, SIGNAL(stateChanged(QAbstractSocket::SocketState, raaConnection*)), SLOT(stateChanged(QAbstractSocket::SocketState, raaConnection*)), Qt::DirectConnection);
	m_pThread->start();
}

raaNetworking::raaTcpClient::~raaTcpClient()
{
	std::cout << "raaTcpClient deleted" << std::endl;
	m_pThread->close();
}

void raaNetworking::raaTcpClient::stateChanged(QAbstractSocket::SocketState state, raaConnection* pConnection)
{
	if (pConnection)
	{
		switch (state)
		{
		case QAbstractSocket::UnconnectedState:
			std::cout << "Client -> Unconnected" << std::endl;
			break;
		case QAbstractSocket::HostLookupState:
			std::cout << "Client -> HostLookup" << std::endl;
			break;
		case QAbstractSocket::ConnectingState:
			std::cout << "Client -> Connecting" << std::endl;
			break;
		case QAbstractSocket::ConnectedState:
			std::cout << "Client -> Connected" << std::endl;

			addConnection(pConnection);
			break;
		case QAbstractSocket::BoundState:
			std::cout << "Client -> Bound" << std::endl;

			break;
		case QAbstractSocket::ClosingState:
			std::cout << "Client -> Closing" << std::endl;
			removeConnection(pConnection);
			break;
		case QAbstractSocket::ListeningState:
			std::cout << "Client -> Listening" << std::endl;

			break;
		default:
			break;
		}
	}
}
