
/**
 * @class CRasterizerState
 *
 * @brief class base for rasterizer state
 *
 * This class is the base for rasterizer state of Directx and opengl
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "xcPrerequisitesCore.h"
namespace xcEngineSDK {
	class SamplerState
	{
	public:
		/// Default Constructor
		SamplerState() = default;

		/// Destructor
		virtual ~SamplerState() = default;
	};
}

