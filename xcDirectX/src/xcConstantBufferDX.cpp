#include "xcConstantBufferDX.h"

namespace xcEngineSDK {
	ConstantBufferDX::~ConstantBufferDX()
	{
		if (m_pConstantBuffer)
		{
			m_pConstantBuffer->Release();
		}
	}
}