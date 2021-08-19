/**
 * @class CSamplerStateOGL
 *
 * @brief class for the sampler state of opengl
 *
 * This class is to use the unsigned int of sampler state that opengl needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "xcSamplerState.h"
namespace xcEngineSDK {
	class SamplerStateOGL : public SamplerState
	{
		/**
		 * @brief protected functions
		 */
	 public:
		/// Default Constructor
		SamplerStateOGL() = default;
		~SamplerStateOGL() = default;

	 protected:

		

		/**
		 * @brief protected variables member
		 */

		/**
		 * @Variable m_SamSt, unsigned int for the sampler state
		 */
		uint32 m_samSt = 0;

		friend class OGLGraphiAPI;
	};
}
