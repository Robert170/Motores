/*****************************************************************************/
/**
 * @file    xcStaticMesh.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/08/02
 * @brief   Represents the component static mesh
 *
 * Represents all nodes of the scene
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

#include "xcPrerequisitesCore.h"
#include "xcComponent.h"


namespace xcEngineSDK {

  class Model;

  class XC_CORE_EXPORT StaticMesh : public Component
  {
   public:
    StaticMesh() = default;
    ~StaticMesh() = default;

    StaticMesh(WeakSptr<Model> model);


    void
    update(float deltaTime) override;

    void
    render() override;

    void
    setModel(WeakSptr<Model> model);

    SPtr<Model>
    getModel();

   private:
    
     SPtr<Model> m_model;
    

  };
}