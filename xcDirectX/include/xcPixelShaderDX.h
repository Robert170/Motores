/**
 * @class CPixelShaderDX
 *
 * @brief class for the pixel shader of directx
 *
 * This class is to use the pointers of pixel shader that directx needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */

#pragma once
#include "xcPixelShader.h"
#include <windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>


namespace xcEngineSDK {
	class PixelShaderDX : public PixelShader
	{
	 public:
		/// Destructor
		~PixelShaderDX();

	 protected:

		/**
			* @brief protected functions
		*/

		/// Default Constructor
		PixelShaderDX() = default;



		/**
		 * @brief      CompilePixelShaderFromFile function, to compile a shader from a file
		 * @param      FileName parameter one, name of the file with the shader
		 * @param      EntryPoint parameter two, entry point of the shader
		 * @param      ShaderModel parameter three, shader model of the shader
		 * @param      ppBlobOut parameter fourth, blob
		 * @bug		   No know Bugs
		 * @return     Returns nothing
		 */
		bool 
		compilePixelShaderFromFile(const std::wstring& FileName,
			                         const std::string& EntryPoint,
			                         const std::string& ShaderModel,
			                         ID3DBlob** ppBlobOut);
		/**
		 * @brief protected variables member
		 */

		/**
		 * @Variable m_PixelShader, pointer for the pixel shader
		 */
		ID3D11PixelShader* m_pixelShader = nullptr;

		/**
		 * @Variable m_pPSBlob, pointer for the blob of pixel shader
		 */
		ID3DBlob* m_pPSBlob = nullptr;


		friend class DXGraphiAPI;
	};

}