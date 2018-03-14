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
		static void start();
		static void stop();
		static raaNetworking* instance();

		bool createServer(QString sName, quint16 uiPort, raaConnectionListenerFactory* pFactory);
		bool createClient(QString sName, QString sHostAddress, quint16 uiPort, raaConnectionListenerFactory* pFactory);

		void closeServer(QString sName);
		void closeClient(QString sName);

	private:
		raaNetworking();
		virtual ~raaNetworking();
		static raaNetworking* sm_pInstance;
		static unsigned int sm_uiInstance;

		raaConnectionManagerNameMap m_mServersByName;
		raaConnectionManagerNameMap m_mClientsByName;
		raaConnectionManagerPortMap m_mServersByPort;
		raaConnectionManagerPortMap m_mClientsByPort;
	};
}
