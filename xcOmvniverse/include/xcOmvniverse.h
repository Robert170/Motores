/*****************************************************************************/
/**
 * @file    xcOmvniverse.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    18/01/2022
 * @brief   Represents the implementation of omvniverse class
 *
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
#include <xcBaseOmvniverse.h>
#include <OmniClient.h>
#include <OmniUsdLive.h>
#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usdGeom/mesh.h>
#include <pxr/usd/usdGeom/metrics.h>
#include <pxr/base/gf/matrix4f.h>
#include <pxr/base/gf/vec2f.h>
#include <pxr/usd/usdUtils/pipeline.h>
#include <pxr/usd/usdUtils/sparseValueWriter.h>
#include <pxr/usd/usdShade/material.h>
#include <pxr/usd/usd/prim.h>
#include <pxr/usd/usd/primRange.h>
#include <pxr/usd/usdShade/input.h>
#include <pxr/usd/usdShade/output.h>
#include <pxr/usd/usdGeom/xform.h>
#include <pxr/usd/usdShade/materialBindingAPI.h>
#include <pxr/usd/usdLux/distantLight.h>
#include <pxr/usd/usdLux/domeLight.h>
#include <pxr/usd/usdShade/shader.h>
#include <pxr/usd/usd/modelAPI.h>
#include <pxr/usd/usdGeom/primvarsAPI.h>

#include "xcPrerequisitesOmvniverse.h"


namespace xcEngineSDK {


  class Omvniverse : public BaseOmvniverse
  {
   public:

      
    Omvniverse() = default;
    ~Omvniverse() = default;


    void
    init() override;
    
    void
    update() override;

    void
    createUSD(String& destinationPath, String& file) override;

    /*bool
    connectToOmni(const String& fileName) override;*/

    /* void
     liveEdit(Vector<UsdPrim> primVector);*/
    String m_existingExample;
   private:

    const uint64 kOmniClientVersion = (uint64)OMNICLIENT_VERSION_MAJOR << 48 |
                                      (uint64)OMNICLIENT_VERSION_MINOR << 32 |
                                      (uint64)OMNICLIENT_VERSION_PATCH;
    bool m_liveEditActive = false;



  };

  extern "C" XC_PLUGIN_EXPORT Omvniverse * create_Omvniverse() {

      auto m_omvniverse = new Omvniverse();

      return m_omvniverse;

  }


}
