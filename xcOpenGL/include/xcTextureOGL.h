/**
 * @class CTextureOGL
 *
 * @brief class for the texture of opengl
 *
 * This class is to use the unsigned int of texture that opengl needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "xcTexture.h"
namespace xcEngineSDK {
	class TextureOGL : public TextureB
	{
	 protected:
		/**
		 * @brief protected functions
		 */

		/// Default Constructor
		TextureOGL() = default;

		/// Destructor
		~TextureOGL() = default;

		/**
		 * @brief protected variables member
		 */

		/**
		 * @Variable m_texture, unsigned int for the texture
		 */
		unsigned int m_texture = 0;

		/**
		 * @Variable m_rTV, unsigned int for the render target view
		 */
		unsigned int m_rTV = 0;

		/**
		 * @Variable m_dSV, unsigned int for the depth stencil view
		 */
		unsigned int m_dSV = 0;

		/**
		 * @Variable m_uAV, unsigned int for the unordered access view
		 */
		unsigned int m_uAV = 0;

		/**
		 * @Variable m_sRV, unsigned int for the shader resource view
		 */
		unsigned int m_sRV = 0;

		friend class OGLGraphiAPI;

	};

}