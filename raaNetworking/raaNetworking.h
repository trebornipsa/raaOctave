#pragma once

#include "raaNetworkingDefs.h"
#include <QtCore/QEvent>
#include <QtCore/QObject>



namespace raaNetworking
{
	class raaMessage;

	class RAANETWORKING_DLL_DEF raaNetworking: public QObject
	{
		Q_OBJECT
	public:
		static void start();
		static void stop();
		static raaNetworking* instance();

		static QEvent::Type readEvent();
		static QEvent::Type writeEvent();

		void write(raaMessage* pMessage);

		void createServer(QString sName, quint16 uiPort);
		void createClient(QString sName, quint16 uiPort, QString sIP, bool bTcp = true, bool bUdp = false);

		void closeServer(QString sName);
		void closeClient(QString sName);
	private:
		static int sm_iRead;
		static int sm_iWrite;

		raaNetworking();
		virtual ~raaNetworking();
		static raaNetworking* sm_pInstance;
		static unsigned int sm_uiInstance;

	protected:
		void customEvent(QEvent *pEvent);


	};
}
