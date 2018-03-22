#pragma once
#include <cstdint>

#include <QtCore/QThread>
#include <QtNetwork/QAbstractSocket>
//#include <QtNetwork/QTcpSocket>

#include "raaConnection.h"
#include "raaNetworking.h"
#include "raaTcpSocket.h"
#include "raaNetworkingDefs.h"



namespace raaNetworking
{
	class raaMessage;
	class raaConnectionListener;
	class raaConnectionManager;

	class RAANETWORKING_DLL_DEF raaTcpThread : public QThread, public raaConnection
	{
		Q_OBJECT
	public:
		raaTcpThread(QString sAddress, quint16 uiPort, QObject *pParent = 0);
		raaTcpThread(qintptr piSocketDescriptor, QString sAddress, quint16 uiPort, QObject *pParent = 0);
		virtual ~raaTcpThread();

		QString name();

		virtual void send(raaMessage* pMsg);

		virtual void close();
	public slots:
		void tcpStateChanged(QAbstractSocket::SocketState);
		void readyRead();
		void disconnected();

	signals:
		void stateChanged(QAbstractSocket::SocketState, raaConnection*);

	protected:
		raaTcpSocket *m_pSocket;
		qintptr m_piSocketDescriptor;


		virtual void run();
		virtual void customEvent(QEvent *pEvent);
		QMutex m_Mutex;

	};
}