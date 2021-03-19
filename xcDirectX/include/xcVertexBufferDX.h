/**
 * @class CVertexBufferDX
 *
 * @brief class for vertex buffers of directx
 *
 * This class is to use pointer of vertex buffer that directx needs
 *
 * @author Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/25/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "xcVertexBuffer.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace xcEngineSDK {
  class VertexBufferDX : public VertexBuffer
  {
  public:
    /// Destructor
    ~VertexBufferDX();

  protected:
    /// Default Constructor
    VertexBufferDX() = default;



    //Separar los buffer en diferentes clases

    /**
     * @brief protected variables member
     */

    /**
     * @Variable m_pVertexBuffer, is for a vertex buffer
     */
    ID3D11Buffer* m_pVertexBuffer = nullptr;

    uint32 m_stride;
    uint32 m_offset;

    friend class DXGraphiAPI;
  };

}