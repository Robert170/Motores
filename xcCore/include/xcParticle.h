#pragma once
#include <xcVector3.h>

namespace xcEngineSDK {

	struct Particle
	{
		Vector<bool> m_isLiving;
		Vector<float> m_lifeTime;
		Vector<float> m_maxLifeTime;
	  Vector<Vector3> m_position;
		
	};

}