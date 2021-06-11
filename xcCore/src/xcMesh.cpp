#include "xcMesh.h"

namespace xcEngineSDK {
  Mesh::Mesh(Vector<BoneVertex> Vertices,
             Vector<uint32> indices,
             Vector<TextureB*> Textures,
             Vector<SamplerState*> Samplers,
             BONES_INFO* Skull,
             BoneVertex* BonVer,
             uint32 NumBones,
             GraphiAPI* API) {

    this->m_Vertices = Vertices;
    this->m_Indices = indices;
    this->m_vTextures = Textures;
    this->m_vSamplers = Samplers;
    m_pBonesInfo.reset(Skull);
    m_pBoneVertex.reset(BonVer);
    m_bonesTransforms.clear();
    m_bonesTransforms.resize(NumBones);

    // now that we have all the required data, set the vertex buffers and its attribute pointers.
    setupMesh(API);
  }

  void 
  Mesh::draw(ShaderProgram& shader,
             Vector<SamplerState*> Samplers,
             GraphiAPI* API) {

    XC_UNREFERENCED_PARAMETER(shader);

    //set shader resource
    for (int i = 0; i < m_vTextures.size(); i++)
    {
        API->setShaderResource(m_vTextures,
                               1);
    }

    //set sampler state
    for (int i = 0; i < Samplers.size(); i++)
    {
        API->setSamplerState(Samplers,
                             1);
    }

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
                                             1);
    
    m_indexBuffer = API->createIndexBuffer(m_Indices,
                                           1);
  }

  void 
  VERTERX_BONE_DATA::AddBoneData(uint32 ID_Bone, float Weights) {
    for (int i = 0; i < 4; i++)
    {
      if (weights[i] == 0.0)
      {
        id_Bone[i] = ID_Bone;
        weights[i] = Weights;
        return;
      }
    }
  }
}