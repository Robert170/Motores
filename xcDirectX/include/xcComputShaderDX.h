/*****************************************************************************/
/**
 * @file    xcComputShaderDX.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    17/10/2021
 * @brief   This class is to use the pointers of compute shader that directX needs
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
#include "xcPrerequisitesDX.h"


namespace xcEngineSDK {
  class ComputeShaderDX :public ComputeShader
	{
	 public:
		/// Destructor
		~ComputeShaderDX();
	 protected:

		/**
			* @brief protected functions
		*/

		/// Default Constructor
		 ComputeShaderDX() = default;




		/**
		 * @brief      compileComputeShaderFromFile function, to compile a shader from a file
		 * @param      FileName parameter one, name of the file with the shader
		 * @param      EntryPoint parameter two, entry point of the shader
		 * @param      ShaderModel parameter three, shader model of the shader
		 * @param      ppBlobOut parameter fourth, blob
		 * @bug		   No know Bugs
		 * @return     Returns nothing
		*/
		bool 
		compileComputeShaderFromFile(const WString& FileName,
			                          const String& EntryPoint,
			                          const String& ShaderModel,
			                          ID3DBlob** ppBlobOut);

		/**
			* @brief protected variables member
		*/

		/**
			* @Variable m_VertexShader, pointer for the vertex shader
		*/
		ID3D11ComputeShader* m_computeShader = nullptr;

		/**
			* @Variable m_pVSBlob, pointer for the blob of vertex shader
		*/
		ID3DBlob* m_pCSBlob = nullptr;

		friend class DXGraphiAPI;
	};
}