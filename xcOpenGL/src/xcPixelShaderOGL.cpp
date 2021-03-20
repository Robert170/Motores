#include "xcPixelShaderOGL.h"

namespace xcEngineSDK {
  std::
  string PixelShaderOGL::readFile(std::string FileName) {
    m_pixelShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {

      //open file
      m_pixelShaderFile.open(FileName);
      // read file's buffer contents into streams
      m_pixelShaderStream << m_pixelShaderFile.rdbuf();
      // close file handlers
      m_pixelShaderFile.close();
      // convert stream into string
      m_pixelCode = m_pixelShaderStream.str();

      return m_pixelCode;
    }
    catch (std::ifstream::failure& e)
    {
      //error
      return " ";
    }
  }
}