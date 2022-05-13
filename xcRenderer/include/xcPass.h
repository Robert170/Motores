/*****************************************************************************/
/**
 * @file    xcPass.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    27/08/2021
 * @brief   Represents the pass of the renderer
 * 
 * That class create and set pass to use in the class of renderer
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
/*****************************************************************************/
/**
 * Includes
 */
 /*****************************************************************************/
#include "xcPrerequisitesRenderer.h"


namespace xcEngineSDK {

  class DepthStencilState;
  class RasterizerState;
  class ShaderProgram;
  class InputLayout;
  class Texture;


	class Pass
	{
	public:
		Pass() = default;
		~Pass() = default;

		void
		createPass();

	private:

		//RenderTargets
		Vector<Texture*> m_RenderTargets;

		//Shader program
    SPtr<ShaderProgram> m_shaderProgram = nullptr;

    //Input layout
    SPtr<InputLayout> m_inputLayout = nullptr;

	};
}

