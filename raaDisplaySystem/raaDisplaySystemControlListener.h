#pragma once

#include <raaNetworking/raaConnectionListener.h>
#include "raaDisplaySystemDefs.h"

namespace raaDisplaySystem
{
	class raaDisplaySystem;
	class RAADISPLAYSYSTEM_DLL_DEF raaDisplaySystemControlListener: public raaNetworking::raaConnectionListener
	{
	public:
		raaDisplaySystemControlListener(raaNetworking::raaConnection *pConnection, raaDisplaySystem* pDisplaySystem);
		virtual ~raaDisplaySystemControlListener();
		virtual void receive(raaNetworking::raaMessage* pMessage, raaNetworking::raaMessage* pReply);
	protected:
		raaDisplaySystem* m_pDisplaySystem;
	};

}
