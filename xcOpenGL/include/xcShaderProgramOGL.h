/**
 * @class CShaderProgramOGL
 *
 * @brief class base for pixel and vertex shader of opengl
 *
 * This class is for compile and set pixel and vertex shader of opengl
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
#include "xcPixelShaderOGL.h"
#include "xcVertexShaderOGL.h"
namespace xcEngineSDK {
	class ShaderProgramOGL : public ShaderProgram
	{
	 protected:

		/**
		 * @brief protected functions
		 */

		/// Default Constructor
		ShaderProgramOGL() = default;

		/// Destructor
		~ShaderProgramOGL();

		/**
		 * @brief protected variables member
		 */

		/**
		 * @Variable m_AttachShaderID, shader id for atyachand link shaders
		 */
		int m_attachShaderID;

		/**
		 * @Variable m_PixelShaderProgram, pointer for the pixel shader of opengl
		 */
		PixelShaderOGL* m_pixelShaderProgram = nullptr;

		/**
		 * @Variable m_PixelShaderProgram, pointer for the pixel shader of opengl
		 */
		VertexShaderOGL* m_vertexShaderProgram = nullptr;

		friend class OGLGraphiAPI;
	};

}