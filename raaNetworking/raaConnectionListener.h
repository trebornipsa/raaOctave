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
		raaConnectionListener(raaConnection *pConnection, bool bCanDelete=true);

		virtual void receive(raaMessage *pMessage, raaMessage* pReply=0) = 0;
		bool send(raaMessage* pMessage);
		raaMessage* createMessage(unsigned short usType);
		bool canDelete();
		void setDeleteable(bool bCanDelete);
	protected:
		virtual ~raaConnectionListener();
	private:
		raaConnection* m_pConnection;
		bool m_bCanDelete; 
	};

	class RAANETWORKING_DLL_DEF raaConnectionListenerFactory
	{
	public:
		raaConnectionListenerFactory();
		virtual ~raaConnectionListenerFactory();
		virtual raaConnectionListener* create(raaConnection *pConnection) = 0;
	};
}
