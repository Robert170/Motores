#include "xcInputLayoutDX.h"

namespace xcEngineSDK {
	InputLayoutDX::~InputLayoutDX()
	{
		if (m_pInputLayout)
		{
			m_pInputLayout->Release();
		}
	}
}