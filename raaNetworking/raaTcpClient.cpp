#include "raaTcpThread.h"

#include "raaTcpClient.h"
#include "raaTcpClient.moc"

raaNetworking::raaTcpClient::raaTcpClient(QString sHostAddress, quint16 uiPort, raaConnectionListenerFactory* pFactory): raaConnectionManager(uiPort, pFactory)
{
	raaTcpThread *pThread = new raaTcpThread(sHostAddress, uiPort, this);
	connect(pThread, SIGNAL(finished()), pThread, SLOT(deleteLater()));
	connect(pThread, SIGNAL(stateChanged(QAbstractSocket::SocketState)), SLOT(stateChanged(QAbstractSocket::SocketState)), Qt::DirectConnection);
	pThread->start();
}

raaNetworking::raaTcpClient::~raaTcpClient()
{
	
}

void raaNetworking::raaTcpClient::stateChanged(QAbstractSocket::SocketState state)
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
