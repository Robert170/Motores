/**
 * @class CSamplerStateDX
 *
 * @brief class for the sampler state of directx
 *
 * This class is to use the pointers of sampler state that directx needs
 *
 * @author Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "xcSamplerState.h"
#include <d3d11.h>
#include <d3dcompiler.h>
namespace xcEngineSDK {
	class SamplerStateDX : public SamplerState
	{
	 public:
		/// Destructor
		~SamplerStateDX();
	 protected:
		/**
		 * @brief protected functions
		 */

		/// Default Constructor
		SamplerStateDX() = default;

		/**
		 * @brief protected variables member
		 */

		/**
		 * @Variable m_pSamplerLinear, pointer for the sampler state
		 */
		ID3D11SamplerState* m_pSamplerLinear = nullptr;

		friend class DXGraphiAPI;

	};

}