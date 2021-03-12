#include "CInputLayoutDX.h"
namespace xcEngineSDK {

	CInputLayoutDX::~CInputLayoutDX() {
		if (m_pInputLayout) {
			m_pInputLayout->Release();
		}
	}
}