#include "xcShaderProgramDX.h"

namespace xcEngineSDK {
	ShaderProgramDX::~ShaderProgramDX()
	{
		delete m_vertexShaderProgram;
		delete m_pixelShaderProgram;
	}
}
