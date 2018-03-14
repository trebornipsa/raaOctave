#pragma once

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
		raaTcpThread(qintptr piSocketDescriptor, QObject *pParent = 0);

		virtual void close();

		QString name();

		virtual void send(raaMessage* pMsg);

	public slots:
		void readyRead();
		void disconnected();

	protected:
		raaTcpSocket *m_pSocket;
		qintptr m_piSocketDescriptor;
		QString m_sAddress;
		quint16 m_uiPort;
		bool m_bServer;

		virtual void run();
		virtual void customEvent(QEvent *pEvent);
		QMutex m_Mutex;

		virtual ~raaTcpThread();
	};
}