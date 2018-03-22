#pragma once

#include <QtCore/QObject>
#include "raaDisplaySystemDefs.h"
#include "raaDisplaySystemTypes.h"
#include <raaNetworking/raaConnectionListener.h>
#include <QtCore/QMutex>


namespace raaDisplaySystem
{
	class RAADISPLAYSYSTEM_DLL_DEF raaDisplaySystem : public QObject, public raaNetworking::raaConnectionListenerFactory
	{
	private:
		Q_OBJECT
	public:

		const static unsigned int csm_uiUnloaded = 0;
		const static unsigned int csm_uiLoaded = 1;
		const static unsigned int csm_uiRunning = 2;
		const static unsigned int csm_uiPaused = 3;
		const static unsigned int csm_uiFailed = 4;

		static void start(quint16 uiControlPort);
		static void stop();
		static raaDisplaySystem* instance();
		raaDisplaySystem(quint16 uiControlPort=0, QObject* pParent=0);
		virtual ~raaDisplaySystem();	

		void addScreen(std::string sName);
		void addViewpoint(std::string sName);

		raaDisplayScreen* screen(std::string sName);
		raaViewpoint* viewpoint(std::string sName);

		const raaDisplayScreenNameMap& screens();
		const raaViewpointNameMap& viewpoints();

		bool save(std::string sFile);
		bool load(std::string sFile);

		unsigned int status();

		virtual raaNetworking::raaConnectionListener* create(raaNetworking::raaConnection* pConnection);

		void controlRecieve(raaNetworking::raaMessage* pMessage, raaNetworking::raaMessage* pReply);
	protected:
		static raaDisplaySystem* sm_pInstance;
		raaDisplayScreenNameMap m_mScreens;
		raaViewpointNameMap m_mViewpoints;
		quint16 m_uiControlPort;
		QMutex m_ControlReadMutex;

		unsigned int m_uiStatus;
		std::string m_sName;


	};
}
