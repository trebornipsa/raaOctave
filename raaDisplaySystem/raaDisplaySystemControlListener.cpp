#include <raaNetworking/raaMessage.h>

#include "raaDisplaySystem.h"
#include "raaDisplaySystemControlListener.h"
#include <iostream>


raaDisplaySystem::raaDisplaySystemControlListener::raaDisplaySystemControlListener(raaNetworking::raaConnection *pConnection, raaDisplaySystem* pDisplaySystem): raaNetworking::raaConnectionListener(pConnection), m_pDisplaySystem(pDisplaySystem)
{
	std::cout << "Display System Listener started" << std::endl;
}

raaDisplaySystem::raaDisplaySystemControlListener::~raaDisplaySystemControlListener()
{
}

void raaDisplaySystem::raaDisplaySystemControlListener::receive(raaNetworking::raaMessage* pMessage, raaNetworking::raaMessage* pReply)
{
	if (pMessage && m_pDisplaySystem) m_pDisplaySystem->controlRecieve(pMessage, pReply);
}
