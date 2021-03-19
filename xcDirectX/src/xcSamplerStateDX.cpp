#include "xcSamplerStateDX.h"

namespace xcEngineSDK {
	SamplerStateDX::~SamplerStateDX()
	{
		if (m_pSamplerLinear)
		{
			m_pSamplerLinear->Release();
		}
	}
}