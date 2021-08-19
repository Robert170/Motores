/*****************************************************************************/
/**
 * @file    xcDepthStencilState.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/08/18
 * @brief   Represents the depth stencil state
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

namespace xcEngineSDK {
  class DepthStencilState
  {
  public:

    /// Default Constructor
    DepthStencilState() = default;

    /// Destructor
    virtual ~DepthStencilState() = default;
  };
}
