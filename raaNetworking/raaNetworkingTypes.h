#pragma once

#include <map>
#include <list>
#include <QtCore/QString>
#include <QtCore/QEvent>

namespace raaNetworking
{
	class raaConnection;
	class raaConnectionManager;

	typedef std::list<raaConnection*> raaConnectionList;
	typedef std::map<QString, raaConnectionManager*> raaConnectionManagerNameMap;
	typedef std::map<quint16, raaConnectionManager*> raaConnectionManagerPortMap;

	static int sm_iRead = 0;
	static int sm_iWrite = 0;

	static QEvent::Type readEvent() {return QEvent::Type(sm_iRead);};
	static QEvent::Type writeEvent() { return QEvent::Type(sm_iWrite);};

	const static unsigned short csm_usTcpMsgSystem = 0;
	const static unsigned short csm_usTcpMsgInfo = 1;
	const static unsigned short csm_usTcpMsgRequest = 2;
	const static unsigned short csm_usTcpMsgReply = 3;

	const static unsigned short csm_usUdpMsgSystem = 0;
	const static unsigned short csm_usUdpMsgInfo = 1;

	const static QByteArray csm_pcSepperator("<rs>", 4);
	const static QByteArray csm_pcInnerSepperator("<ri>", 4);

	static QString tcpMsgTypeToString(unsigned short usType)
	{
		switch (usType)
		{
		case csm_usTcpMsgSystem:
			return QString("tcpMsgSystem");
		case csm_usTcpMsgInfo:
			return QString("tcpMsgInfo");
		case csm_usTcpMsgRequest:
			return QString("tcpMsgRequest");
		case csm_usTcpMsgReply:
			return QString("tcpMsgReply");
		default:
			return QString("tcpMsgUnknown");
		}
	}
}
