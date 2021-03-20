#include "xcIndexBufferDX.h"
namespace xcEngineSDK {
	IndexBufferDX::~IndexBufferDX()
	{
		if (m_pIndexBuffer)
		{
			m_pIndexBuffer->Release();
		}
	}
}