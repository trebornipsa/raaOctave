
#include <raaNetworking/raaNetworking.h>
#include <raaNetworking/raaConnection.h>
#include <raaNetworking/raaMessage.h>

#include "raaDisplaySystemControlListener.h"
#include "raaDisplaySystem.h"
#include "raaDisplayScreen.h"
#include "raaViewpoint.h"
#include "raaDisplaySystemTypes.h"
#include "raaDisplaySystem.moc"
#include <iostream>

raaDisplaySystem::raaDisplaySystem* raaDisplaySystem::raaDisplaySystem::sm_pInstance = 0;

raaDisplaySystem::raaDisplaySystem::raaDisplaySystem(quint16 uiControlPort, QObject* pParent): QObject(pParent), m_uiControlPort(uiControlPort), m_uiStatus(csm_uiUnloaded)
{
	if (!sm_pInstance) sm_pInstance = this;
	else throw csm_uiExceptionDisplaySystemExists;

	raaNetworking::raaNetworking::start(0);
	raaNetworking::raaNetworking::instance()->createServer("DisplaySystem", m_uiControlPort, this, false);
}

void raaDisplaySystem::raaDisplaySystem::addScreen(std::string sName)
{
	if (sName.length() && m_mScreens.find(sName) == m_mScreens.end()) m_mScreens[sName] = new raaDisplayScreen(sName);
	else throw csm_uiExceptionBadName;
}

void raaDisplaySystem::raaDisplaySystem::addViewpoint(std::string sName)
{
	if (sName.length() && m_mViewpoints.find(sName) == m_mViewpoints.end()) m_mViewpoints[sName] = new raaViewpoint(sName);
	else throw csm_uiExceptionBadName;
}

raaDisplaySystem::raaDisplayScreen* raaDisplaySystem::raaDisplaySystem::screen(std::string sName)
{
	if (sName.length() && m_mScreens.find(sName) != m_mScreens.end()) return m_mScreens[sName];
	else throw csm_uiExceptionBadName;
}

raaDisplaySystem::raaViewpoint* raaDisplaySystem::raaDisplaySystem::viewpoint(std::string sName)
{
	if (sName.length() && m_mViewpoints.find(sName) != m_mViewpoints.end()) return m_mViewpoints[sName];
	else throw csm_uiExceptionBadName;
}

const raaDisplaySystem::raaDisplayScreenNameMap& raaDisplaySystem::raaDisplaySystem::screens()
{
	return m_mScreens;
}

const raaDisplaySystem::raaViewpointNameMap& raaDisplaySystem::raaDisplaySystem::viewpoints()
{
	return m_mViewpoints;
}

bool raaDisplaySystem::raaDisplaySystem::save(std::string sFile)
{
	return false;
}

bool raaDisplaySystem::raaDisplaySystem::load(std::string sFile)
{
	return false;
}

unsigned raaDisplaySystem::raaDisplaySystem::status()
{
	return m_uiStatus;
}

raaNetworking::raaConnectionListener* raaDisplaySystem::raaDisplaySystem::create(raaNetworking::raaConnection* pConnection)
{
	if (pConnection->port() == m_uiControlPort) return new raaDisplaySystemControlListener(pConnection, this);
	return 0;
}

void raaDisplaySystem::raaDisplaySystem::controlRecieve(raaNetworking::raaMessage* pMessage, raaNetworking::raaMessage* pReply)
{
	m_ControlReadMutex.lock();

	if(pMessage)
	{
		switch(pMessage->type())
		{
		case raaNetworking::csm_usTcpMsgInfo:
			std::cout << "Control Info Message -> " << pMessage->asString(0) << std::endl;
			break;
		case raaNetworking::csm_usTcpMsgRequest:
			std::cout << "Control Request Message -> " << pMessage->asString(0) << std::endl;
		
			switch(pMessage->asUInt(0))
			{
			case csm_uiMsgStatus:
				pReply->add(csm_uiMsgStatus);
				pReply->add(m_uiStatus);
				break;
			}
			break;
		case raaNetworking::csm_usTcpMsgReply:
			std::cout << "Control Reply Message -> " << pMessage->asString(0) << std::endl;
			break;
		}
	}

	m_ControlReadMutex.unlock();
}

raaDisplaySystem::raaDisplaySystem::~raaDisplaySystem()
{
	raaNetworking::raaNetworking::stop();
	if (sm_pInstance == this) sm_pInstance = 0;
}

void raaDisplaySystem::raaDisplaySystem::start(quint16 uiControlPort)
{
	if (!sm_pInstance) new raaDisplaySystem(uiControlPort);
}

void raaDisplaySystem::raaDisplaySystem::stop()
{
	if (sm_pInstance) delete sm_pInstance;

}