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

  struct XC_CORE_EXPORT MeshTexture
  {
  public:
    String Type;
    String Path;
    Texture* TextureMesh;
  };


  class XC_CORE_EXPORT Mesh
  {
   public:

     Mesh() = default;
    // constructor
     Mesh(Vector<BoneVertex> Vertices,
          Vector<int32> indices,
          Vector<Texture*> Textures,
          Vector<SamplerState*> Samplers,
          BONES_INFO* skeletal);

    Mesh(Vector<BoneVertex> vertex,
         Vector<int32> index,
         Vector<Texture*> texture,
         SPtr<SamplerState> Samplers);

     //Mesh(ModelData data);

    // render the mesh
    void
    render();

    void
    update(const float& deltaTime);

   
    void
    setUpGPUMesh();

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
    Vector<int32> m_Indices;

    /**
      * @Variable m_vTextures, all textures
    */
    Vector<Texture*> m_vTextures;

    /**
      * @Variable m_vTextures, all textures
    */
    Vector<String> m_vPhats;

    /**
      * @Variable m_vSamplers, all samplers
    */
    Vector< SPtr<SamplerState>> m_vSamplers;

     

     SPtr<BONES_INFO> m_pBonesInfo;

     //SPtr<BoneVertex> m_pBoneVertex = nullptr;

     Vector<Matrix4x4> m_bonesTransforms;

     uint32 m_FaceVertexCount;


   private:
    // render data 

    SPtr<IndexBuffer> m_indexBuffer;
    SPtr<VertexBuffer> m_vertexBuffer;
    const void* m_scene;


   private:
    // initializes all the buffer objects/arrays
   

   public:
    Matrix4x4
    boneTrasnform(float time);

    void 
    nodeHeirarchy(float time,
                  void* node);

    const aiNodeAnim* 
    FindNodeAnimation(const String& NameNod,
                      void* Anim);

    int32 
    findPosition(float AnimationTime, void* pNodeAnim);

    int32 
    findRotation(float AnimationTime, void* pNodeAnim);

    int32 
    findScaling(float AnimationTime, void* pNodeAnim);

    void 
    calcInterpolatedPosition(void* Out, 
                             float AnimationTime, 
                             void* pNodeAnim);
    void 
    calcInterpolatedRotation(void* Out, 
                             float AnimationTime, 
                             void* pNodeAnim);
    void 
    calcInterpolatedScaling(void* Out, 
                            float AnimationTime, 
                            void* pNodeAnim);

    Vector<Vector3>
    getVertexes();

    Vector<int32>
    getIndexes();

    Vector<Vector3>
    getNormals();

    Vector<Vector2>
    getUV();

    uint32
    getFaceVertexCount();

    void 
    getMeshInfo(Vector<Vector3>& vertices,
                Vector<uint32>& indices,
                Vector<Vector3>& normals,
                Vector<Vector2>& uvs);

  };

}