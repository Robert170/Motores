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
#include "xcComputeShaderDX.h"
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
		 * @Variable m_pixelShaderProgram, pointer for the pixel shader of directx
		 */
		PixelShaderDX* m_pixelShaderProgram = nullptr;

		/**
		 * @Variable m_vertexShaderProgram, pointer for the vertex shader of directx
		 */
		VertexShaderDX* m_vertexShaderProgram = nullptr;

		/**
		 * @Variable m_computeShaderProgram, pointer for the compute shader of directx
		 */
		ComputeShaderDX* m_computeShaderProgram = nullptr;


		friend class DXGraphiAPI;
	};

}