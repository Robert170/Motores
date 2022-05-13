/**
 * @class CIndexBuffer
 *
 * @brief class base for index buffer
 *
 * This class is the base for index buffer of Directx and opengl
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/25/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "xcPrerequisitesCore.h"
namespace xcEngineSDK {
  class IndexBuffer
  {
   public:

    /// Default Constructor
    IndexBuffer() = default;

    /// Destructor
    virtual ~IndexBuffer() = default;
  };
}
