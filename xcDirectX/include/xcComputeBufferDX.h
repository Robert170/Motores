/*****************************************************************************/
/**
 * @file    xcComputBufferDX.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    17/10/2021
 * @brief   This class is to use the pointers of compute buffer that directX needs
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
#include <xcComputeBuffer.h>
#include "xcPrerequisitesDX.h"


namespace xcEngineSDK {
  class ComputeBufferDX : public ComputeBuffer
  {
   public:
    /// Destructor
    ~ComputeBufferDX() = default;

   protected:

    /**
     * @brief protected variables member
     */

    /**
     * @Variable m_pComputeBuffer, is for an compute buffer
     */
    ID3D11Buffer* m_pComputeBuffer = nullptr;

    /**
     * @Variable m_UAV, pointer for the unordered access view
     */
    ID3D11UnorderedAccessView* m_pUAV = nullptr;

    /**
     * @Variable m_SRV, pointer for the shader resource view
     */
    ID3D11ShaderResourceView* m_pSRV = nullptr;


    uint32 m_offset = 0;

    friend class DXGraphiAPI;
  };
}