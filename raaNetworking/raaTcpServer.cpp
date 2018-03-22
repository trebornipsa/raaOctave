#include "raaTcpServer.h"
#include "raaTcpServer.moc"
#include "raaTcpThread.h"
#include "raaNetworkingTypes.h"
#include <iostream>

raaNetworking::raaTcpServer::raaTcpServer(quint16 uiPort, raaConnectionListenerFactory* pFactory, bool bCanDeleteFactory, QObject* pParent): QTcpServer(pParent), m_uiPort(uiPort), raaConnectionManager(uiPort, pFactory, bCanDeleteFactory)
{
	if (m_uiPort) listen(QHostAddress::Any, m_uiPort);
}

raaNetworking::raaTcpServer::~raaTcpServer()
{
	std::cout << "raaTcpServer deleted" << std::endl;
}



void raaNetworking::raaTcpServer::stateChanged(QAbstractSocket::SocketState state, raaConnection* pConnection)
{
//	raaConnection *pConnection = dynamic_cast<raaConnection*>(sender());
	if (pConnection)
	{
		switch (state)
		{
		case QAbstractSocket::UnconnectedState:
			std::cout << "Server -> Unconnected" << std::endl;
			break;
		case QAbstractSocket::HostLookupState:
			std::cout << "Server -> HostLookup" << std::endl;
			break;
		case QAbstractSocket::ConnectingState:
			std::cout << "Server -> Connecting" << std::endl;
			break;
		case QAbstractSocket::ConnectedState:
			std::cout << "Server -> Connected" << std::endl;

			addConnection(pConnection);
				break;
		case QAbstractSocket::BoundState:
			std::cout << "Server -> Bound" << std::endl;

			break;
		case QAbstractSocket::ClosingState:
			std::cout << "Server -> Closing" << std::endl;

			removeConnection(pConnection);
			break;
		case QAbstractSocket::ListeningState:
			std::cout << "Server -> Listening" << std::endl;

			break;
		default:
			break;
		}
	}
}

void raaNetworking::raaTcpServer::incomingConnection(qintptr piSocketDescriptor)
{
	raaTcpThread *pThread = new raaTcpThread(piSocketDescriptor, "localhost", m_uiPort, this);  
	connect(pThread, SIGNAL(finished()), pThread, SLOT(deleteLater()));
	connect(pThread, SIGNAL(stateChanged(QAbstractSocket::SocketState, raaConnection*)), SLOT(stateChanged(QAbstractSocket::SocketState, raaConnection*)), Qt::DirectConnection);
	pThread->start();
}
