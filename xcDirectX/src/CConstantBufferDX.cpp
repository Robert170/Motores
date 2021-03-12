#include "CConstantBufferDX.h"
namespace xcEngineSDK {
	CConstantBufferDX::~CConstantBufferDX() {
		if (m_pConstantBuffer) {
			m_pConstantBuffer->Release();
		}
	}
}
