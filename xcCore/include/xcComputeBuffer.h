/*****************************************************************************/
/**
 * @file    xcComputeBuffer.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    20/10/2021
 * @brief   Represents the compute buffer 
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

  class ComputeBuffer
  {
   public:
    /// Default Constructor
    ComputeBuffer() = default;
    
    /// Destructor
    virtual ~ComputeBuffer() = default;
  };

  
}