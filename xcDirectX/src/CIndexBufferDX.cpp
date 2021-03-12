#include "CIndexBufferDX.h"
namespace xcEngineSDK {
	CIndexBufferDX::~CIndexBufferDX() {
		if (m_pIndexBuffer) {
			m_pIndexBuffer->Release();
		}
	}
}