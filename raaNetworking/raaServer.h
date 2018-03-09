#pragma once

#include <QtNetwork/QTcpServer>

namespace raaNetworking
{
	class raaServer: public QTcpServer
	{
		Q_OBJECT
	public:
		raaServer();
		virtual ~raaServer();


	};
}
