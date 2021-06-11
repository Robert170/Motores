/**
 * @class CInputLayoutOGL
 *
 * @brief class for the input layout of opengl
 *
 * This class is to use the unsigned int of input layout that opengl needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "xcInputLayout.h"
#include <map>
namespace xcEngineSDK {
	class InputLayoutOGL : public InputLayout
	{
	 protected:
		/// Default Constructor
		InputLayoutOGL();

		/// Destructor
		~InputLayoutOGL() = default;

		/**
			* @brief protected variables member
		*/

		/**
			* @Variable m_IPLA, unsigned int for the input layout
		*/
		unsigned int m_iPLA = 0;

		/**
			* @Variable m_Size, size, depent of the format
		*/
		unsigned int m_size = 0;

		/**
			* @Variable m_Offset, offset for each element
		*/
		unsigned int m_offset = 0;

		/**
		 * @Variable m_NumberOfInputLayout, number of input layout to delete
	  */
		unsigned int m_numberOfInputLayout = 0;

		/**
			* @Variable m_mFormatSize, map whit the size of formats
		*/
		std::map<unsigned int, unsigned int> m_mFormatSize;

		unsigned int getSize(unsigned int Format);

		friend class OGLGraphiAPI;
	};
}
