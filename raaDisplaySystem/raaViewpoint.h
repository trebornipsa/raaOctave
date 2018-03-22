#pragma once

#include "raaDisplaySystemDefs.h"
#include <QtCore/QString>
#include <osg/Matrixf>

namespace raaDisplaySystem
{
	class RAADISPLAYSYSTEM_DLL_DEF raaViewpoint
	{
	public:
		raaViewpoint(std::string sName);
		virtual ~raaViewpoint();

		std::string name();

		osg::Matrixf physcialViewpoint();
		osg::Matrixf virtualPoint();

		void setPysicalViewpoint(osg::Matrixf& mPhysicalViewpoint);
		void setVirtualViewpoint(osg::Matrixf& mVirtualViewpoint);
		void setVirtualViewpoint(osg::Vec3f& vEyePos, osg::Vec3f& vEyeUp, osg::Vec3f& vEyeDir);
		void setPhysicalViewpoint(osg::Vec3f& vEyePos, osg::Vec3f& vEyeUp, osg::Vec3f& vEyeDir);

	protected:
		std::string m_sName;
		osg::Matrixf m_mPhysicalViewpoint;
		osg::Matrixf m_mVirtualViewpoint;
	};
}
