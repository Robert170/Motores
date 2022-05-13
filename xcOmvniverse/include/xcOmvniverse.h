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
#include <pxr/usd/usdGeom/metrics.h>
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

   private:




  };

  extern "C" XC_PLUGIN_EXPORT Omvniverse * create_Omvniverse() {

      auto m_omvniverse = new Omvniverse();

      return m_omvniverse;

  }


}
