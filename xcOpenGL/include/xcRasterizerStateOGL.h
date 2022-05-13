/**
 * @class CRasterizerStateOGL
 *
 * @brief class for the rasterizer state of opengl
 *
 * This class is to use the  of rasterizer state that opengl needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/20/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "xcRasterizerState.h"
namespace xcEngineSDK {
	class RasterizerStateOGL : public RasterizerState
	{
	 protected:
		/**
			* @brief protected functions
		*/

		/// Default Constructor
		RasterizerStateOGL() = default;

		/// Destructor
		~RasterizerStateOGL() = default;



		friend class OGLGraphiAPI;
	};

}