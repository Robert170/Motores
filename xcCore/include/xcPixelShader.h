/**
 * @class CPixelShader
 *
 * @brief class base for pixell shader
 *
 * This class is the base for pixel shader of Directx and opengl
 *
 * @author Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include <iostream>
namespace xcEngineSDK {
	class PixelShader
	{
	 public:
		/// Default Constructor
		PixelShader() = default;

		/// Destructor
		virtual ~PixelShader() = default;
	};
}

