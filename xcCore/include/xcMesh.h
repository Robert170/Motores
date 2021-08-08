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


  class XC_CORE_EXPORT Mesh
  {
   public:

     Mesh() = default;
    // constructor
     Mesh(Vector<BoneVertex> Vertices,
          Vector<uint32> indices,
          Vector<Texture*> Textures,
          Vector<SamplerState*> Samplers,
          BONES_INFO* skeletal);

     //Mesh(ModelData data);

    // render the mesh
    void
    render();

    void
    update(const float& deltaTime);

    void
    setupMesh();

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
    Vector<Texture*> m_vTextures;

    /**
      * @Variable m_vSamplers, all samplers
    */
    Vector<SamplerState*> m_vSamplers;

     

     SPtr<BONES_INFO> m_pBonesInfo;

     //SPtr<BoneVertex> m_pBoneVertex = nullptr;

     Vector<Matrix4x4> m_bonesTransforms;


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
  };

}