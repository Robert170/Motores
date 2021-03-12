#include "CRasterizerStateDX.h"

namespace xcEngineSDK {

	CRasterizerStateDX::~CRasterizerStateDX() {
		if (m_pRasterizerState) {
			m_pRasterizerState->Release();
		}
	}
}