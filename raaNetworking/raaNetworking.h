#pragma once

#include "raaNetworkingDefs.h"
#include <QtCore/QEvent>
#include <QtCore/QObject>
#include "raaNetworkingTypes.h"


namespace raaNetworking
{
	class raaMessage;
	class raaConnectionListenerFactory;


	class RAANETWORKING_DLL_DEF raaNetworking: public QObject
	{
		Q_OBJECT
	public:
		static void start(QObject *pParent);
		static void stop();
		static raaNetworking* instance();

		bool createServer(QString sName, quint16 uiPort, raaConnectionListenerFactory* pFactory, bool bCanDeleteFactory=true);
		bool createClient(QString sName, QString sHostAddress, quint16 uiPort, raaConnectionListenerFactory* pFactory, bool bCanDeleteFactory = true);

		void closeServer(QString sName);
		void closeClient(QString sName);
		static QEvent::Type readEvent();
		static QEvent::Type writeEvent();

		static void setCompression(int iCompression);
		static int compression();

//	protected:		
//		virtual void customEvent(QEvent *pEvent);


	private:
		raaNetworking(QObject *pParent=0);
		virtual ~raaNetworking();
		static raaNetworking* sm_pInstance;
		static unsigned int sm_uiInstance;
		static int sm_iReadEvent;
		static int sm_iWriteEvent;

		static int sm_iCompression;

		raaConnectionManagerNameMap m_mServersByName;
		raaConnectionManagerNameMap m_mClientsByName;
		raaConnectionManagerPortMap m_mServersByPort;
		raaConnectionManagerPortMap m_mClientsByPort;
	};
}
