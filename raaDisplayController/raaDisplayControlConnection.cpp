#include "stdafx.h"
#include "raaDisplayControllerInterface.h"
#include "raaDisplayControlConnection.h"


raaDisplayControlConnection::raaDisplayControlConnection(raaNetworking::raaConnection* pConnection, raaDisplayControllerInterface* pInterface): raaConnectionListener(pConnection), m_pInterface(pInterface)
{
	m_pInterface->setControlConnected(true);
}

raaDisplayControlConnection::~raaDisplayControlConnection()
{
	m_pInterface->setControlConnected(false);
}

void raaDisplayControlConnection::receive(raaNetworking::raaMessage* pMessage, raaNetworking::raaMessage* pReply)
{
}
