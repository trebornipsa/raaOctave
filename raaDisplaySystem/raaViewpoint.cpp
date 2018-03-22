#include "raaViewpoint.h"



raaDisplaySystem::raaViewpoint::raaViewpoint(std::string sName): m_sName(sName)
{
}


raaDisplaySystem::raaViewpoint::~raaViewpoint()
{
}

std::string raaDisplaySystem::raaViewpoint::name()
{
	return m_sName;
}

osg::Matrixf raaDisplaySystem::raaViewpoint::physcialViewpoint()
{
	return m_mPhysicalViewpoint;
}

void raaDisplaySystem::raaViewpoint::setPysicalViewpoint(osg::Matrixf& mPhysicalViewpoint)
{
	m_mPhysicalViewpoint = mPhysicalViewpoint;
}

void raaDisplaySystem::raaViewpoint::setVirtualViewpoint(osg::Matrixf& mVirtualViewpoint)
{
	m_mVirtualViewpoint = mVirtualViewpoint;
}

void raaDisplaySystem::raaViewpoint::setVirtualViewpoint(osg::Vec3f& vEyePos, osg::Vec3f& vEyeUp, osg::Vec3f& vEyeDir)
{
	osg::Matrixf m;
	m.makeLookAt(vEyePos, vEyePos + vEyeDir, vEyeUp);
	m_mPhysicalViewpoint = m;
}

void raaDisplaySystem::raaViewpoint::setPhysicalViewpoint(osg::Vec3f& vEyePos, osg::Vec3f& vEyeUp, osg::Vec3f& vEyeDir)
{
	osg::Matrixf m;
	m.makeLookAt(vEyePos, vEyePos + vEyeDir, vEyeUp);
	m_mVirtualViewpoint = m;
}

osg::Matrixf raaDisplaySystem::raaViewpoint::virtualPoint()
{
	return m_mVirtualViewpoint;
}
