#pragma once

#include <QtCore/QThread>
#include <QtNetwork/QTcpSocket>

#include "raaNetworkingDefs.h"

namespace raaNetworking
{
	class raaMessage;
	class raaSocket;	
	class RAANETWORKING_DLL_DEF raaSocketThread: public QThread
	{

		Q_OBJECT
	public:
		const static unsigned int csm_uiUnkownSocketType = 0;
		const static unsigned int csm_uiTcpSocketType = 1;
		const static unsigned int csm_uiUdpSocketType = 2;

		raaSocketThread(qintptr piSocketDescriptor, QObject *pParent = 0); // server create tcp
		raaSocketThread(QString sName, QString sAddress, quint16 uiPort, bool bServer, QObject *pParent = 0);  // udp create
		raaSocketThread(QString sName, QString sAddress, quint16 uiPort, QObject *pParent = 0); // tcp client create

		void close();
		void write(raaMessage *pMsg);
		QString name();

		public slots:
		void readyRead();
		void disconnected();
		void stateChanged(QAbstractSocket::SocketState);

	signals:
		void stateChanged(raaSocketThread*, QAbstractSocket::SocketState);


	protected:
		QString m_sName;
		raaSocket *m_pSocket;
		QString m_sAddress;
		quint16 m_uiPort;
		bool m_bServerSide;
		unsigned int m_uiSocketType;
	

		virtual void run();
		virtual ~raaSocketThread();
	};
}
