/**
 * @class CConstantBufferDX
 *
 * @brief class for all constant buffers of directx
 *
 * This class is to use all pointers of constant buffer that directx needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */

#pragma once
#include "xcConstantBuffer.h"
#include <d3d11.h>
#include <d3dcompiler.h>
namespace xcEngineSDK {

  class ConstantBufferDX : public ConstantBuffer
  {
   public:
    /// Destructor
    ~ConstantBufferDX();
   protected:
    /// Default Constructor
    ConstantBufferDX() = default;

    /**
     * @brief protected variables member
     */

    /**
     * @Variable m_pConstantBuffer, is for a constant buffer
     */
    ID3D11Buffer* m_pConstantBuffer = nullptr;

    friend class DXGraphiAPI;
  };

}