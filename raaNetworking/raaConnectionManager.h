#pragma once

#include "raaNetworkingTypes.h"
#include "raaNetworkingDefs.h"

namespace raaNetworking
{
	class raaConnectionListenerFactory;
	class raaConnectionListener;
	class RAANETWORKING_DLL_DEF raaConnectionManager
	{
	public:
		raaConnectionManager(quint16 uiPort, raaConnectionListenerFactory *pFactory);
		virtual ~raaConnectionManager();
		raaConnectionListener* createListener(raaConnection* pConnection);

		void addConnection(raaConnection* pConnection);
		void removeConnection(raaConnection* pConnection);
		quint16 port();

	protected:
		raaConnectionListenerFactory *m_pFactory;
		raaConnectionList m_lConnections;
		quint16 m_uiPort;

	};
}
