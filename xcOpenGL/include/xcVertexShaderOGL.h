/**
 * @class CVertexShaderOGL
 *
 * @brief class for the vertex shader of opengl
 *
 * This class is to use the unsigned int of vertex shader and fuctions that opengl needs
 *
 * @author Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "xcVertexShader.h"
#include <fstream>
#include <sstream>
namespace xcEngineSDK {
	class VertexShaderOGL : public VertexShader
	{
	 protected:

		/**
			* @brief protected functions
		*/

		/// Default Constructor
		VertexShaderOGL() = default;

		/// Destructor
		~VertexShaderOGL() = default;

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
			* @Variable m_VertexCode, string where we save te code of the pixel shade
		*/
		std::string m_vertexCode;

		/**
			* @Variable m_VertexShaderFile, for open file, take exepcions
		*/
		std::ifstream m_vertexShaderFile;

		/**
			* @Variable m_VertexShaderStream, this is temp for transfor in string
		*/
		std::stringstream m_vertexShaderStream;

		/**
			* @Variable m_VertexShader, unsigned int for the vertex shader
		*/
		unsigned int m_vertexShader;



		friend class OGLGraphiAPI;
	};
}