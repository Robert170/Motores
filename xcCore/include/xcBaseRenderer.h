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
  class Model;
	class BaseRenderer : public Module<BaseRenderer>
	{
	public:
		BaseRenderer() = default;

    virtual
		~BaseRenderer() = default;

    FORCEINLINE void
      setObject(BaseRenderer* render) {
			BaseRenderer::_instance() = render;
    }

    virtual void
    init() {};

    virtual void
    update() {};

    virtual void
    render() {};

    virtual void
    setModels(Vector<SPtr<Model>> models) {};

    virtual void
    setModel(SPtr<Model> model) {};
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
