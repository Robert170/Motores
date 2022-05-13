/**
 * @class CShaderProgram
 *
 * @brief class base for pixel and vertex shader
 *
 * This class is the base compile and set pixel and vertex shader
 *
 * @author Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 12/2/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
namespace xcEngineSDK {
  class ShaderProgram
  {
   public:
    /// Default Constructor
    ShaderProgram() = default;

    /// Destructor
    virtual ~ShaderProgram() = default;
  };
}

