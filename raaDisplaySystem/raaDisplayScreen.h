#pragma once

#include <osg/Matrix>

#include "raaDisplaySystemDefs.h"
#include <QtCore/QString>

namespace raaDisplaySystem
{
	class RAADISPLAYSYSTEM_DLL_DEF raaDisplayScreen
	{
	public:
		raaDisplayScreen(std::string sName);
		~raaDisplayScreen();

		std::string name();

		osg::Matrixf perspective();
		osg::Matrixf modelView();

		void setPerspective(osg::Matrixf& mPerspective);
		void setModelView(osg::Matrixf& mMoelView);

		osg::Vec3f physicalScreen(unsigned int uiIndex);
		osg::Vec3f virtualScreen(unsigned int uiIndex);

		const int* viewport();
		int viewportParam(unsigned int uiIndex);
		void setViewport(unsigned int uiIndex, int uiParam);
		void setViewport(int* aiViewport);

	protected: 
		std::string m_sName;
		osg::Matrixf m_mPerspective;
		osg::Matrixf m_mModelView;
		osg::Vec3f m_avPhysicalScreen[4];
		osg::Vec3f m_avVirtualScreen[4];
		int m_aiViewport[4];
	};
}
