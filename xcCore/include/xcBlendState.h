/*****************************************************************************/
/**
 * @file    xcBlendState.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    1/12/2021
 * 
 * @brief   Represents the blend state base to graphics api
 *
 * blent state to use in DiretcX or OpenGL
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
/*****************************************************************************/
/**
 * Includes
 */
 /*****************************************************************************/
#include "xcGraphiAPI.h"
namespace xcEngineSDK {
  class BlendState
  {
  public:
    /// Default Constructor
    BlendState() = default;
    /// Destructor
    virtual ~BlendState() = default;


  };
}

