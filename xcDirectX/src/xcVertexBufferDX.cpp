#include "xcVertexBufferDX.h"

namespace xcEngineSDK {
	VertexBufferDX::~VertexBufferDX()
	{
		if (m_pVertexBuffer)
		{
			m_pVertexBuffer->Release();
		}
	}
}