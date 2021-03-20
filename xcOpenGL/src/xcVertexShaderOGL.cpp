#include "xcVertexShaderOGL.h"
namespace xcEngineSDK {
  std::string 
  VertexShaderOGL::readFile(std::string FileName) {

    m_vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {

      //open file
      m_vertexShaderFile.open(FileName);
      // read file's buffer contents into streams
      m_vertexShaderStream << m_vertexShaderFile.rdbuf();
      // close file handlers
      m_vertexShaderFile.close();
      // convert stream into string
      m_vertexCode = m_vertexShaderStream.str();

      return m_vertexCode;
    }
    catch (std::ifstream::failure& e) {
      //error
      return " ";
    }
  }

}