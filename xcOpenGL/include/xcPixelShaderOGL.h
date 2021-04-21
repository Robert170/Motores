/**
 * @class CPixelShaderOGL
 *
 * @brief class for the pixel shader of opengl
 *
 * This class is to use the unsigned int of pixel shader and fuctions that opengl needs
 *
 * @author Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "xcPixelShader.h"
#include <fstream>
#include <sstream>
namespace xcEngineSDK {
	class PixelShaderOGL : public PixelShader
	{
	 public:
		/// Destructor
		~PixelShaderOGL() = default;

	 protected:
		/**
			* @brief protected functions
		*/

		/// Default Constructor
		PixelShaderOGL() = default;


		/**
		 * @brief      ReadFile function, to read a file
		 * @param      FileName parameter one, name of the file with the shader
		 * @bug		   No know Bugs
		 * @return     Returns nothing
		*/
		std::string readFile(std::string FileName);

		/**
			* @brief protected variables member
		*/

		/**
			* @Variable m_PixelCode, string where we save te code of the pixel shade
		*/
		std::string m_pixelCode;

		/**
			* @Variable m_PixelShaderFile, for open file, take exepcions
		*/
		std::ifstream m_pixelShaderFile;

		/**
				* @Variable m_PixelShaderStream, this is temp for transfor in string
			*/
		std::stringstream m_pixelShaderStream;

		/**
			* @Variable m_PixelShader, unsigned int for the pixel shader
		*/
		uint32 m_pixelShader = 0;



		friend class OGLGraphiAPI;
	};

}