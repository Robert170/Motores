/*****************************************************************************/
/**
 * @file    xcComputBufferDX.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    17/10/2021
 * @brief   This class is to use the pointers of compute buffer that directX needs
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once

/*****************************************************************************/
/**
 * Includes
 */
 /*****************************************************************************/
#include <xcComputShader.h>
#include "xcPrerequisitesOGL.h"


namespace xcEngineSDK {
	class ComputeShaderOGL : public ComputeShader
	{
	public:
		/// Destructor
		~ComputeShaderOGL() = default;

	protected:
		ComputeShaderOGL() = default;
		

		friend class OGLGraphiAPI;
	};
}