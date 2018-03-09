#pragma once

#include "raaNetworkingDefs.h"

namespace raaNetworking
{
	class raaTcpSocket;
	class raaUdpSocket;
	class RAANETWORKING_DLL_DEF raaSocket
	{
	public:
		raaSocket();
		virtual ~raaSocket();
		virtual raaTcpSocket* asTcpSocket()=0;
		virtual raaUdpSocket* asUdpSocket()=0;

		virtual void read()=0;
		virtual void disconnect()=0;
		virtual void delaidDelete() = 0;
		virtual void close()=0;

	};
}
