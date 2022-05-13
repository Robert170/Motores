/*****************************************************************************/
/**
 * @file    xcComputShader.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    17/10/2021
 * @brief   Represents the implementation of compute shader class
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

#include "xcPrerequisitesCore.h"

namespace xcEngineSDK {
  class ComputeShader
  {
  public:

    /// Default Constructor
    ComputeShader() = default;


    /// Destructor
    virtual ~ComputeShader() = default;
  };
}