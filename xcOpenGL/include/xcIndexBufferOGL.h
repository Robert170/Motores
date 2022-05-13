/**
 * @class CIndexBufferOGL
 *
 * @brief class for index buffers of opengl
 *
 * This class is to use unsigned int of index buffer that opengl needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/25/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "xcIndexBuffer.h"

namespace xcEngineSDK {
  class IndexBufferOGL : public IndexBuffer
  {
   public:
    /// Default Constructor
    IndexBufferOGL() = default;

    /// Destructor
    ~IndexBufferOGL() = default;

   protected:
    /**
      * @brief protected variables member
    */

    /**
      * @Variable m_IBO, is for a index buffer
    */
    uint32 m_IBO = 0;

    friend class OGLGraphiAPI;
  };
}
