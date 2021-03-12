/**
 * @class CIndexBufferDX
 *
 * @brief class for index buffers of directx
 *
 * This class is to use pointer of index buffer that directx needs
 *
 * @author Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/25/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "CIndexBuffer.h"
#include <d3d11.h>
#include <d3dcompiler.h>
namespace xcEngineSDK {
  class CIndexBufferDX : public CIndexBuffer
  {
   protected:
    /// Default Constructor
    CIndexBufferDX() = default;

    /// Destructor
    ~CIndexBufferDX();

    /**
      * @brief protected variables member
    */

    /**
      * @Variable m_pIndexBuffer, is for an index buffer
    */
    ID3D11Buffer* m_pIndexBuffer = nullptr;

    unsigned int m_offset;


    friend class CDXGraphiAPI;
  };
} 

