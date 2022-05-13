#include "xcRasterizerStateDX.h"

namespace xcEngineSDK {
	RasterizerStateDX::~RasterizerStateDX()
	{
		if (m_pRasterizerState)
		{
			m_pRasterizerState->Release();
		}
	}
}