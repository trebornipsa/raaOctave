#pragma once

#include <map>
#include <list>

namespace raaDisplaySystem
{
	class raaDisplayScreen;
	class raaDisplaySystem;
	class raaViewpoint;

	const static unsigned int csm_uiBottomLeft = 0;
	const static unsigned int csm_uiBottomRight = 1;
	const static unsigned int csm_uiTopRight = 2;
	const static unsigned int csm_uiTopLeft = 3;
	const static unsigned int csm_uiX = 0;
	const static unsigned int csm_uiY = 1;
	const static unsigned int csm_uiWidth = 2;
	const static unsigned int csm_uiHeight = 3;

	const static unsigned int csm_uiExceptionDisplayScreenIndexOutOfRange = 50501;
	const static unsigned int csm_uiExceptionBadArrayPointer = 50502;
	const static unsigned int csm_uiExceptionBadName = 50503;
	const static unsigned int csm_uiExceptionDisplaySystemExists = 50504;

	typedef std::map<std::string, raaDisplaySystem*> raaDisplaySystemNameMap;
	typedef std::map<std::string, raaDisplayScreen*> raaDisplayScreenNameMap;
	typedef std::map<std::string, raaViewpoint*> raaViewpointNameMap;
	typedef std::list<raaDisplaySystem*> raaDisplaySystemList;
	typedef std::list<raaDisplayScreen*> raaDisplayScreenList;
	typedef std::list<raaViewpoint*> raaViewpointList;

	const static unsigned int csm_uiMsgNone = 0;
	const static unsigned int csm_uiMsgStatus = 1;
}