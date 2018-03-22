#pragma once

#include <QtCore/QObject>
#include "raaNetworkingDefs.h"

namespace raaNetworking
{
	class raaConnectionListener;
	class raaConnectionManager;
	class raaMessage;

	class raaConnection
	{
		friend raaConnectionManager;
	public:
		raaConnection(QString sAddress, quint16 uiPort, bool bServer);

		virtual void send(raaMessage *pMessage)=0; 
		virtual void receive(raaMessage *pMessage);
		raaMessage* createMessage(unsigned short usType);

		virtual quint16 port();
		virtual QString address();
		bool isServer();

		virtual void close() = 0;


	protected:
		virtual ~raaConnection();
		raaConnectionListener* m_pConnectionListener;
		bool m_bServer;
		quint16 m_uiPort;
		QString m_sAddress;
	private:
		void setListener(raaConnectionListener* pListener);
		void destroyListener();

	};
}
