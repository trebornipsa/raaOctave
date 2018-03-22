#pragma once

#include <QtCore/QEvent>
#include  <QtCore/QString>
#include "raaNetworkingDefs.h"
#include <QtCore/QStringList>
#include <QtCore/QMutex>

namespace raaNetworking
{
	class raaConnection;
	class RAANETWORKING_DLL_DEF raaMessage: public QEvent
	{
		friend raaConnection;
	public:
		const static unsigned short csm_usTypeNone = 0;
		const static unsigned short csm_usTypeSystem = 1;
		const static unsigned short csm_usTypeInform = 2;
		const static unsigned short csm_usTypeRequest = 3;
		const static unsigned short csm_usTypeResponce = 4;

		const static unsigned int csm_uiMsgBadIndex = 5100;

		raaMessage(unsigned short usType, QEvent::Type t);
		raaMessage(QByteArray &data, unsigned short usType, QEvent::Type t, raaConnection* pConnection, unsigned int uiMessageID);
		virtual ~raaMessage();

		void add(unsigned short usVal);
		void add(unsigned int uiVal);
		void add(int iVal);
		void add(std::string sVal);
		void add(unsigned int *puiVal, unsigned int uiCount);
		void add(float *pfVal, unsigned int uiCount);
		void add(const char* pccVal, unsigned int uiSize);
		void add(bool bVal);
		void add(float f);

		unsigned short asUShort(unsigned int uiIndex);
		unsigned int asUInt(unsigned int uiIndex);
		int asInt(unsigned int uiIndex);
		std::string asString(unsigned int uiIndex);
		float* asFloatArray(unsigned int uiIndex);
		unsigned int* asUIntArray(unsigned int uiIndex);
		const char* asConstChar(unsigned int uiIndex);
		bool asBool(unsigned int uiIndex);
		float asFloat(unsigned int uiIndex);

		unsigned int length();

		QByteArray& data();

		unsigned short type();

		raaConnection* connection();

		unsigned int messageID();

	protected:
		unsigned int m_uiMessageID;
		void unpack();

		QByteArray m_Data;
		QByteArrayList m_DataList;
		unsigned short m_usType;
		unsigned int m_uiID;
		static unsigned int sm_uiID;
		unsigned int m_uiBuildLen;

		QMutex m_Mutex;
		raaConnection* m_pConnection;
		static unsigned int sm_uiMessageID;
	};
}
