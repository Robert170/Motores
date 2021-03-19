/**
 * @class CShaderProgramDX
 *
 * @brief class base for pixel and vertex shader of directx
 *
 * This class is for compile and set pixel and vertex shader of directx
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 12/2/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "xcShaderProgram.h"
#include "xcPixelShaderDX.h"
#include "xcVertexShaderDX.h"
namespace xcEngineSDK {
	class ShaderProgramDX : public ShaderProgram
	{
	 public:
		/// Destructor
		~ShaderProgramDX();
	 protected:

		/**
		 * @brief protected functions
		 */

		/// Default Constructor
		ShaderProgramDX() = default;



		/**
		 * @brief protected variables member
		 */

		/**
		 * @Variable m_PixelShaderProgram, pointer for the pixel shader of directx
		 */
		PixelShaderDX* m_pixelShaderProgram = nullptr;

		/**
		 * @Variable m_PixelShaderProgram, pointer for the pixel shader of directx
		 */
		VertexShaderDX* m_vertexShaderProgram = nullptr;




		friend class DXGraphiAPI;
	};

}