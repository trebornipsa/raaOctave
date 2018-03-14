#pragma once


#include "raaNetworkingDefs.h"

namespace raaNetworking
{
	class raaConnection;
	class raaMessage;
	class RAANETWORKING_DLL_DEF raaConnectionListener
	{
		friend raaConnection;
	public:
		raaConnectionListener(raaConnection *pConnection);

		virtual void receive(raaMessage *pMessage) = 0;
		bool send(raaMessage* pMessage);
	protected:
		virtual ~raaConnectionListener();
	private:
		raaConnection* m_pConnection;
	};

	class RAANETWORKING_DLL_DEF raaConnectionListenerFactory
	{
	public:
		raaConnectionListenerFactory();
		virtual ~raaConnectionListenerFactory();
		virtual raaConnectionListener* create(raaConnection *pConnection) = 0;
	};
}
