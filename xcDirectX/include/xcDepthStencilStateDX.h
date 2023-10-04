/*****************************************************************************/
/**
 * @file    xcDepthStencilStateDX.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
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

    /**
     * @brief protected variables member
     */

     /**
    * @Variable m_pDepthStencilState, pointer for the depth stencil STATE
    */
    ID3D11DepthStencilState* m_pDepthStencilState = nullptr;

    

    friend class DXGraphiAPI;
  };

}