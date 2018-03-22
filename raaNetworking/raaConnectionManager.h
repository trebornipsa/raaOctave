#pragma once

#include "raaNetworkingTypes.h"
#include "raaNetworkingDefs.h"

namespace raaNetworking
{
	class raaConnectionListenerFactory;
	class raaConnectionListener;
	class raaMessage;
	class RAANETWORKING_DLL_DEF raaConnectionManager
	{
	public:
		raaConnectionManager(quint16 uiPort, raaConnectionListenerFactory *pFactory, bool bCanDeleteFactory=true);
		virtual ~raaConnectionManager();
		raaConnectionListener* createListener(raaConnection* pConnection);

		void addConnection(raaConnection* pConnection);
		void removeConnection(raaConnection* pConnection);
		quint16 port();

		void send(raaMessage *pMessage);

	protected:
		raaConnectionListenerFactory *m_pFactory;
		raaConnectionList m_lConnections;
		quint16 m_uiPort;
		bool m_bCanDeleteFactory;

	};
}
