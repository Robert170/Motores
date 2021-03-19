#include "xcMesh.h"

namespace xcEngineSDK {
  Mesh::Mesh(std::vector<SimpleVertex> Vertices,
             std::vector<unsigned int> Indices,
             InputLayout_Desc InpLayDesc,
             GraphiAPI* API) {
    this->m_Vertices = Vertices;
    this->m_Indices = Indices;
    m_inpLayDesc = InpLayDesc;
    //this->textures = Textures;
    // now that we have all the required data, set the vertex buffers and its attribute pointers.
    setupMesh(API);
  }

  void 
  Mesh::draw(ShaderProgram& shader,
             GraphiAPI* API) {
    API->setVertexBuffer(m_vertexBuffer,
                         0,
                         1,
                         sizeof(SimpleVertex),
                         0);

    API->setIndexBuffer(m_indexBuffer,
                        0);

    // draw mesh
    API->drawIndexed(m_Indices.size(),
                     0,
                     0,
                     nullptr);

  }

  void 
  Mesh::setupMesh(GraphiAPI* API) {
    m_vertexBuffer = API->createVertexBuffer(m_Vertices,
                                             m_Vertices.size(),
                                             1);

    m_indexBuffer = API->createIndexBuffer(m_Indices,
                                           m_Indices.size(),
                                           1);
  }
}