#include "raaMessage.h"
#include "raaNetworkingTypes.h"


raaNetworking::raaMessage::raaMessage(unsigned short usMsgType, QEvent::Type t): QEvent(t)
{
	
}

raaNetworking::raaMessage::raaMessage(QByteArray& data, unsigned short usType, QEvent::Type t): m_Data(data), m_usType(usType), QEvent(t)
{
	
}

void raaNetworking::raaMessage::add(unsigned short usVal)
{
	m_DataList.push_back(QByteArray((const char*)&usVal, sizeof(unsigned short)));
}

void raaNetworking::raaMessage::add(unsigned uiVal)
{
	m_DataList.push_back(QByteArray((const char*)&uiVal, sizeof(unsigned int)));
}

void raaNetworking::raaMessage::add(int iVal)
{
	m_DataList.push_back(QByteArray((const char*)&iVal, sizeof(int)));
}

void raaNetworking::raaMessage::add(std::string sVal)
{
	m_DataList.push_back(sVal.c_str());
}

void raaNetworking::raaMessage::add(unsigned* puiVal, unsigned uiCount)
{
	if (puiVal && uiCount)
	{
		QByteArray data;
		for (unsigned int i = 0; i<uiCount; i++) data.append((const char*)puiVal + i, sizeof(unsigned int));
		m_DataList.push_back(data);
	}
}

void raaNetworking::raaMessage::add(float* pfVal, unsigned uiCount)
{
	if (pfVal && uiCount)
	{
		QByteArray data;
		for (unsigned int i = 0; i<uiCount; i++) data.append((const char*)pfVal + i, sizeof(float));
		m_DataList.push_back(data);
	}
}

void raaNetworking::raaMessage::add(const char* pccVal, unsigned uiSize)
{
	m_DataList.push_back(QByteArray(pccVal, uiSize));
}

void raaNetworking::raaMessage::add(bool bVal)
{
	if (bVal)
		m_DataList.push_back(QByteArray(1, 't'));
	else
		m_DataList.push_back(QByteArray(1, 'f'));
}

void raaNetworking::raaMessage::add(float f)
{
	m_DataList.push_back(QByteArray((const char*)&f, sizeof(float)));
}

unsigned short raaNetworking::raaMessage::asUShort(unsigned uiIndex)
{
	if (uiIndex<m_DataList.size()) return *((unsigned short*)m_DataList[uiIndex].data());
	throw csm_uiMsgBadIndex;
}

unsigned raaNetworking::raaMessage::asUInt(unsigned uiIndex)
{
	if (uiIndex<m_DataList.size()) return *((unsigned int*)m_DataList[uiIndex].data());
	throw csm_uiMsgBadIndex;
}

int raaNetworking::raaMessage::asInt(unsigned uiIndex)
{
	if (uiIndex<m_DataList.size()) return *((int*)m_DataList[uiIndex].data());
	throw csm_uiMsgBadIndex;
}

std::string raaNetworking::raaMessage::asString(unsigned uiIndex)
{
	if (uiIndex < m_DataList.size())
	{
		std::string s = m_DataList[uiIndex].data();
		return s;
	}
	throw csm_uiMsgBadIndex;
}

float* raaNetworking::raaMessage::asFloatArray(unsigned uiIndex)
{
	if (uiIndex<m_DataList.size()) return (float*)m_DataList[uiIndex].data();
	throw csm_uiMsgBadIndex;
}

unsigned* raaNetworking::raaMessage::asUIntArray(unsigned uiIndex)
{
	if (uiIndex<m_DataList.size()) return (unsigned int*)m_DataList[uiIndex].data();
	throw csm_uiMsgBadIndex;
}

const char* raaNetworking::raaMessage::asConstChar(unsigned uiIndex)
{
	if (uiIndex<m_DataList.size()) return m_DataList[uiIndex].data();
	throw csm_uiMsgBadIndex;
}

bool raaNetworking::raaMessage::asBool(unsigned uiIndex)
{
	if (uiIndex < m_DataList.size())
	{
		if (m_DataList[uiIndex].contains('t')) return true;
		return false;
	}
	throw csm_uiMsgBadIndex;
}

float raaNetworking::raaMessage::asFloat(unsigned uiIndex)
{
	if (uiIndex<m_DataList.size()) return *((float*)m_DataList[uiIndex].data());
	throw csm_uiMsgBadIndex;
}

raaNetworking::raaMessage::~raaMessage()
{

}

QByteArray& raaNetworking::raaMessage::data()
{
	if (m_uiBuildLen != m_DataList.length())
	{
		m_Data.clear();

		for (QByteArrayList::iterator it = m_DataList.begin(); it != m_DataList.end();)
		{
			m_Data.append((*it));
			it++;
			if (it != m_DataList.end()) m_Data.append(csm_pcSepperator);
		}
		//		m_Data=qCompress(m_Data, 1);
		m_uiBuildLen = m_DataList.length();
	}
	return m_Data;
}

unsigned short raaNetworking::raaMessage::type()
{
	return m_usType;
}

void raaNetworking::raaMessage::unpack()
{
	qint64 uiIndex = 0, i;

	m_DataList.clear();

	//	m_Data = qUncompress(m_Data);

	do
	{
		i = m_Data.indexOf(csm_pcSepperator, uiIndex);
		if (i != -1)
		{
			m_DataList.push_back(QByteArray(m_Data.data() + uiIndex, i - uiIndex));
			uiIndex = i + csm_pcSepperator.size();
		}
		else
		{
			m_DataList.push_back(QByteArray(m_Data.data() + uiIndex, m_Data.length() - uiIndex));
			uiIndex = -1;
		}
	} while (uiIndex != -1);

}
