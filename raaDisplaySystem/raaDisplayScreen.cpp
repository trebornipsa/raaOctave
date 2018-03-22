#include "raaDisplayScreen.h"
#include "raaDisplaySystemTypes.h"


raaDisplaySystem::raaDisplayScreen::raaDisplayScreen(std::string sName): m_sName(sName)
{
}

raaDisplaySystem::raaDisplayScreen::~raaDisplayScreen()
{
}

std::string raaDisplaySystem::raaDisplayScreen::name()
{
	return m_sName;
}

osg::Matrixf raaDisplaySystem::raaDisplayScreen::perspective()
{
	return m_mPerspective;
}

osg::Matrixf raaDisplaySystem::raaDisplayScreen::modelView()
{
	return m_mModelView;
}

void raaDisplaySystem::raaDisplayScreen::setPerspective(osg::Matrixf& mPerspective)
{
	m_mPerspective = mPerspective;
}

void raaDisplaySystem::raaDisplayScreen::setModelView(osg::Matrixf& mMoelView)
{
	m_mModelView = mMoelView;
}

osg::Vec3f raaDisplaySystem::raaDisplayScreen::physicalScreen(unsigned uiIndex)
{
	if (uiIndex < 4) return m_avPhysicalScreen[uiIndex];
	else throw csm_uiExceptionDisplayScreenIndexOutOfRange;
}

osg::Vec3f raaDisplaySystem::raaDisplayScreen::virtualScreen(unsigned uiIndex)
{
	if (uiIndex < 4) return m_avVirtualScreen[uiIndex];
	else throw csm_uiExceptionDisplayScreenIndexOutOfRange;
}

const int* raaDisplaySystem::raaDisplayScreen::viewport()
{
	return m_aiViewport;
}

int raaDisplaySystem::raaDisplayScreen::viewportParam(unsigned uiIndex)
{
	if (uiIndex < 4) return m_aiViewport[uiIndex];
	else throw csm_uiExceptionDisplayScreenIndexOutOfRange;
}

void raaDisplaySystem::raaDisplayScreen::setViewport(unsigned uiIndex, int uiParam)
{
	if (uiIndex < 4) m_aiViewport[uiIndex] = uiParam;
	else throw csm_uiExceptionDisplayScreenIndexOutOfRange;
}

void raaDisplaySystem::raaDisplayScreen::setViewport(int* aiViewport)
{
	if(aiViewport)
	{
		m_aiViewport[csm_uiX] = aiViewport[csm_uiX];
		m_aiViewport[csm_uiY] = aiViewport[csm_uiY];
		m_aiViewport[csm_uiWidth] = aiViewport[csm_uiWidth];
		m_aiViewport[csm_uiHeight] = aiViewport[csm_uiHeight];

	}
	else throw csm_uiExceptionBadArrayPointer;
}
