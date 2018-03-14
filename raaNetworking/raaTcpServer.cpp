#include "raaTcpServer.h"
#include "raaTcpServer.moc"
#include "raaTcpThread.h"
#include "raaNetworkingTypes.h"

raaNetworking::raaTcpServer::raaTcpServer(quint16 uiPort, raaConnectionListenerFactory* pFactory, QObject* pParent): QTcpServer(pParent), m_uiPort(uiPort), raaConnectionManager(uiPort, pFactory)
{
	if (m_uiPort) listen(QHostAddress::Any, m_uiPort);
}

raaNetworking::raaTcpServer::~raaTcpServer()
{
}

void raaNetworking::raaTcpServer::stateChanged(QAbstractSocket::SocketState state)
{
	raaConnection *pConnection = dynamic_cast<raaConnection*>(sender());
	if (pConnection)
	{
		switch (state)
		{
		case QAbstractSocket::UnconnectedState:
			break;
		case QAbstractSocket::HostLookupState:
			break;
		case QAbstractSocket::ConnectingState:
			break;
		case QAbstractSocket::ConnectedState:
			addConnection(pConnection);
				break;
		case QAbstractSocket::BoundState:
			break;
		case QAbstractSocket::ClosingState:
			removeConnection(pConnection);
			break;
		case QAbstractSocket::ListeningState:
			break;
		default:
			break;
		}
	}
}

void raaNetworking::raaTcpServer::incomingConnection(qintptr piSocketDescriptor)
{
	raaTcpThread *pThread = new raaTcpThread(piSocketDescriptor, this);
	connect(pThread, SIGNAL(finished()), pThread, SLOT(deleteLater()));
	connect(pThread, SIGNAL(stateChanged(QAbstractSocket::SocketState)), SLOT(stateChanged(QAbstractSocket::SocketState)), Qt::DirectConnection);
	pThread->start();
}
