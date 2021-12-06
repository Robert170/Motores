/*****************************************************************************/
/**
 * @file    xcBlendStateDX.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    1/12/2021
 * @brief   This class is to use the pointers of blend state that directX needs
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
#include <xcBlendState.h>
#include "xcPrerequisitesDX.h"
namespace xcEngineSDK {
  class BlendStateDX : public BlendState
  {
   public:
    /// Destructor
    ~BlendStateDX();

   protected:

    /**
      * @brief protected functions
    */

    /// Default Constructor
     BlendStateDX() = default;

    /**
     * @brief protected variables member
     */

    /**
     * @Variable m_pBlendState, is for an blend state
     */
    ID3D11BlendState* m_pBlendState = nullptr;


    friend class DXGraphiAPI;
  };
}