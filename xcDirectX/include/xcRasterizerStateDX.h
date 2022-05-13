/**
 * @class CRasterizerStateDX
 *
 * @brief class for the rasterizer state of directx
 *
 * This class is to use the pointers of rasterizer state that directx needs
 *
 * @author Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/20/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "xcRasterizerState.h"
#include <d3d11.h>
#include <d3dcompiler.h>
namespace xcEngineSDK {
	class RasterizerStateDX : public RasterizerState
	{
	 public:
		/// Destructor
		~RasterizerStateDX();
	 protected:

		/**
			* @brief protected functions
		*/

		/// Default Constructor
		RasterizerStateDX() = default;

		/**
			* @brief protected variables member
		*/

		/**
			* @Variable m_pRasterizerState, pointer for the rasterizer state
		*/
		ID3D11RasterizerState* m_pRasterizerState = nullptr;
		

		friend class DXGraphiAPI;
	};
}
