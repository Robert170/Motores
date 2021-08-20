/*****************************************************************************/
/**
 * @file    xcBaseRenderer.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    20/08/2021
 * @brief   Represents Base of the renderer 
 *
 * The base of the renderer 
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
/*****************************************************************************/
/**
 * Includes
 */
 /*****************************************************************************/
#include <xcModule.h>
#include <xcPrerequisitesCore.h>

namespace xcEngineSDK {
	class XC_CORE_EXPORT BaseRenderer : public Module<BaseRenderer>
	{
	public:
		BaseRenderer() = default;
		~BaseRenderer() = default;

    FORCEINLINE void
      setObject(BaseRenderer* render) {
			BaseRenderer::_instance() = render;
    }
	private:

	};

  /**
   * @brief export the instance
   */
  XC_CORE_EXPORT BaseRenderer& 
  g_renderer();

  /**
   * @Variable funProtoGraphiAPI, instance of the class
   */
  using funProtoRenderer = BaseRenderer * (*)();


}
