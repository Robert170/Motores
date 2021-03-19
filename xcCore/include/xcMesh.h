/**
 * @class CMesh
 *
 * @brief class for the Mesh of the model
 *
 * This class is the for Mesh of Directx and opengl
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 12/3/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include <glad/glad.h> 
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>
#include "xcShaderProgram.h"
#include "xcInputLayout.h"
#include "xcVertexBuffer.h"
#include "xcIndexBuffer.h"
namespace xcEngineSDK {
  struct Vertex {
    // position
    Vector3 Position;
    // texCoords
    Vector2 TexCoords;
  };

  struct Texture {
    uint32 id;
    std::string type;
    std::string path;
  };

  class Mesh
  {
   public:

    // constructor
    Mesh(std::vector<SimpleVertex> Vertices,
         std::vector<unsigned int> indices,
         InputLayout_Desc InpLayDesc,
         //std::vector<Texture> textures,
         GraphiAPI* API);

    // render the mesh
    void
    draw(ShaderProgram& shader,
         GraphiAPI* API);

   public:
    // mesh Data
    std::vector<SimpleVertex> m_Vertices;
    std::vector<unsigned int> m_Indices;
    //std::vector<Texture> m_Textures;

    InputLayout* m_inutLaout;
    InputLayout_Desc m_inpLayDesc;

   private:
    // render data 

    IndexBuffer* m_indexBuffer;
    VertexBuffer* m_vertexBuffer;



    // initializes all the buffer objects/arrays
    void 
    setupMesh(GraphiAPI* API);
  };

}