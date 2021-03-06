/**
 * @class CVertexBuffer
 *
 * @brief class base for vertex buffer
 *
 * This class is the base for vertex buffer of Directx and opengl
 *
 * @author Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/25/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
namespace xcEngineSDK {

  class CVertexBuffer 
  {

   public:

    /// Default Constructor
    CVertexBuffer() = default;

    /// Destructor
    virtual ~CVertexBuffer() = default;
  };
}

