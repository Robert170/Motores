#include "CSamplerStateDX.h"
namespace xcEngineSDK {

	CSamplerStateDX::~CSamplerStateDX() {
		if (m_pSamplerLinear) {
			m_pSamplerLinear->Release();
		}
	}
}
