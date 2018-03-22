#include "stdafx.h"
#include "raaConnection.h"
#include "raaServerInterface.h"
#include "raaServerInterface.moc"
#include <raaNetworking/raaNetworking.h>

raaServerInterface* raaServerInterface::sm_pInstance = 0;

raaServerInterface::raaServerInterface()
{
	raaNetworking::raaNetworking::start(this);
	raaNetworking::raaNetworking::instance()->createServer("server", 65201, new raaConnectionFactory());

	if (!sm_pInstance) sm_pInstance = this;
	setupUi(this);
	connect(send_button, SIGNAL(clicked()), SLOT(read()));
}

raaServerInterface::~raaServerInterface()
{
	if (sm_pInstance == this) sm_pInstance = 0;
	raaNetworking::raaNetworking::stop();
}

void raaServerInterface::read()
{
	//QLineEdit *pMessage = dynamic_cast<QLineEdit*>(sender());

	if(raaConnection::sm_pInstance)
	{
//		std::cout << "Input -> " << message->text() << std::endl;
		std::string s = "Hi Robbie";
		raaConnection::sm_pInstance->post(s);
	}
}
