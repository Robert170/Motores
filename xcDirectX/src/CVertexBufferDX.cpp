#include "CVertexBufferDX.h"

namespace xcEngineSDK {
	CVertexBufferDX::~CVertexBufferDX() {
		if (m_pVertexBuffer) {
			m_pVertexBuffer->Release();
		}
	}
}