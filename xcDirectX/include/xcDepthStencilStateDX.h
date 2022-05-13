/*****************************************************************************/
/**
 * @file    xcDepthStencilStateDX.h
 * @author  Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/08/18
 * @brief   Represents the depth stencil state of dirextx
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
#include <xcDepthStencilState.h>
#include "xcPrerequisitesDX.h"
namespace xcEngineSDK {

  class DepthStencilStateDX : public DepthStencilState
  {
  public:
    /// Destructor
    ~DepthStencilStateDX();
  protected:
    /// Default Constructor
    DepthStencilStateDX() = default;

    //Separar los buffer en diferentes clases

    /**
     * @brief protected variables member
     */

     /**
      * @Variable m_pConstantBuffer, is for a constant buffer
      */
    ID3D11DepthStencilState* m_pDepthStencilState = nullptr;

    friend class DXGraphiAPI;
  };

}