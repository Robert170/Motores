/**
 * @class CVertexShader
 *
 * @brief class base for vertex shader
 *
 * This class is the base for vertex shader of Directx and opengl
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
	class VertexShader
	{
	public:

		/// Default Constructor
		VertexShader() = default;


		/// Destructor
		virtual ~VertexShader() = default;
	};
}

