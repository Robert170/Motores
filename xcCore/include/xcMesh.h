/**
 * @class CMesh
 *
 * @brief class for the Mesh of the model
 *
 * This class is the for Mesh of Directx and opengl
 *
 * @author Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 12/3/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>

#include <xcQuaternions.h>

#include"xcPrerequisitesCore.h"
#include "xcShaderProgram.h"
#include "xcInputLayout.h"
#include "xcVertexBuffer.h"
#include "xcIndexBuffer.h"

namespace xcEngineSDK {

  struct BONES 
  {
    Matrix4x4 Offset;
    Matrix4x4 Transformation;
  };

  struct BONES_INFO
  {
    uint32 NumBones = 0;
    Vector<BONES> VecSkeletal;
    std::map<String, uint32> BonesMap;
  };

  struct Vertex {
    // position
    Vector3 Position;
    // texCoords
    Vector2 TexCoords;
  };

  struct Texture {
    uint32 id;
    String type;
    String path;
  };

  class XC_CORE_EXPORT Mesh
  {
   public:

     Mesh() = default;

    // constructor
     Mesh(Vector<BoneVertex> Vertices,
          Vector<uint32> indices,
          Vector<TextureB*> Textures,
          Vector<SamplerState*> Samplers,
          BONES_INFO* Skull,
          BoneVertex* BonVer,
          uint32 NumBones,
          const aiScene* m_scene);

    // render the mesh
    void
    draw(ShaderProgram& shader,
         Vector<SamplerState*> Samplers);

   public:
    /**
       * @brief public functions
    */

    /**
      * @Variable m_Vertices, textures vertex
    */
    Vector<BoneVertex> m_Vertices;

    /**
      * @Variable m_Indices, textures indices
    */
    Vector<uint32> m_Indices;

    /**
      * @Variable m_vTextures, all textures
    */
    Vector<TextureB*> m_vTextures;

    /**
      * @Variable m_vSamplers, all samplers
    */
    Vector<SamplerState*> m_vSamplers;

     /*
     variable pointer CMesh for the Parent.
    */
     Mesh* m_Parent;

     //! A public variable.
     /*!
       variable vector of CMesh for the m_Children.
     */
     Vector<Mesh*>	m_Children;

     SPtr<BONES_INFO> m_pBonesInfo = nullptr;

     SPtr<BoneVertex> m_pBoneVertex = nullptr;

     Vector<Matrix4x4> m_bonesTransforms;

   private:
    // render data 

    IndexBuffer* m_indexBuffer;
    VertexBuffer* m_vertexBuffer;
    const aiScene* m_scene;


   private:
    // initializes all the buffer objects/arrays
    void 
    setupMesh();

  public:
    Matrix4x4
    boneTrasnform(float time, 
                  Vector<Matrix4x4>& transform);

    void 
    nodeHeirarchy(float time,
                  const aiNode* node, 
                  const Matrix4x4& transform);

    const aiNodeAnim* 
    FindNodeAnimation(const String NameNod,
                      const aiAnimation* Anim);

    int32 
    findPosition(float AnimationTime, const aiNodeAnim* pNodeAnim);

    int32 
    findRotation(float AnimationTime, const aiNodeAnim* pNodeAnim);

    int32 
    findScaling(float AnimationTime, const aiNodeAnim* pNodeAnim);

    void 
    calcInterpolatedPosition(aiVector3D& Out, 
                             float AnimationTime, 
                             const aiNodeAnim* pNodeAnim);
    void 
    calcInterpolatedRotation(aiQuaternion& Out, 
                             float AnimationTime, 
                             const aiNodeAnim* pNodeAnim);
    void 
    calcInterpolatedScaling(aiVector3D& Out, 
                            float AnimationTime, 
                            const aiNodeAnim* pNodeAnim);
  };

}