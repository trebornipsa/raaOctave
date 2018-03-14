#pragma once

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
		raaConnection();

		virtual void send(raaMessage *pMessage)=0; 
		virtual void receive(raaMessage *pMessage);
		virtual void close()=0;

		raaMessage* createMessage(unsigned short usType);

	protected:
		virtual ~raaConnection();
		raaConnectionListener* m_pConnectionListener;

	private:
		void setListener(raaConnectionListener* pListener);
		void destroyListener();

	};
}
