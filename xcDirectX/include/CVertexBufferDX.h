/**
 * @class CVertexBufferDX
 *
 * @brief class for vertex buffers of directx
 *
 * This class is to use pointer of vertex buffer that directx needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/25/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "CVertexBuffer.h"
#include <d3d11.h>
#include <d3dcompiler.h>
namespace xcEngineSDK {
  class CVertexBufferDX : public CVertexBuffer
  {
   protected:
    /// Default Constructor
    CVertexBufferDX() = default;

    /// Destructor
    ~CVertexBufferDX();

    /**
     * @brief protected variables member
     */

    /**
     * @Variable m_pVertexBuffer, is for a vertex buffer
     */
    ID3D11Buffer* m_pVertexBuffer = nullptr;

    unsigned int m_stride;
    unsigned int m_offset;

    friend class CDXGraphiAPI;
  };
}

