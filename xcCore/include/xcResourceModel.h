/*****************************************************************************/
/**
 * @file    xcResourceModel.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/07/17
 * @brief   Represents the resource of the model
 *
 * Represents all nodes of the scene
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once

/*****************************************************************************/
/**
 * Includes
 */
 /*****************************************************************************/
#include <xcVector4.h>
#include <xcMatrix4x4.h>
#include <xcGraphiAPI.h>
#include "xcTexture.h"

#include "xcPrerequisitesCore.h"




namespace xcEngineSDK {

  enum TEXTURE_TYPE
  {
    /** Dummy value.
     *
     *  No texture, but the value to be used as 'texture semantic'
     *  (#aiMaterialProperty::mSemantic) for all material properties
     *  *not* related to textures.
     */
    TextureType_NONE = 0,
    
    /** LEGACY API MATERIALS 
     * Legacy refers to materials which 
     * Were originally implemented in the specifications around 2000.
     * These must never be removed, as most engines support them.
     */
    
    /** The texture is combined with the result of the diffuse
     *  lighting equation.
     */
    TextureType_DIFFUSE = 1,
    
    /** The texture is combined with the result of the specular
     *  lighting equation.
     */
    TextureType_SPECULAR = 2,
    
    /** The texture is combined with the result of the ambient
     *  lighting equation.
     */
    TextureType_AMBIENT = 3,
    
    /** The texture is added to the result of the lighting
     *  calculation. It isn't influenced by incoming light.
     */
    TextureType_EMISSIVE = 4,
    
    /** The texture is a height map.
     *
     *  By convention, higher gray-scale values stand for
     *  higher elevations from the base height.
     */
    TextureType_HEIGHT = 5,
    
    /** The texture is a (tangent space) normal-map.
     *
     *  Again, there are several conventions for tangent-space
     *  normal maps. Assimp does (intentionally) not
     *  distinguish here.
     */
    TextureType_NORMALS = 6,
    
    /** The texture defines the glossiness of the material.
     *
     *  The glossiness is in fact the exponent of the specular
     *  (p hong) lighting equation. Usually there is a conversion
     *  function defined to map the linear color values in the
     *  texture to a suitable exponent. Have fun.
    */
    TextureType_SHININESS = 7,
    
    /** The texture defines per-pixel opacity.
     *
     *  Usually 'white' means opaque and 'black' means
     *  'transparency'. Or quite the opposite. Have fun.
    */
    TextureType_OPACITY = 8,
    
    /** Displacement texture
     *
     *  The exact purpose and format is application-dependent.
     *  Higher color values stand for higher vertex displacements.
    */
    TextureType_DISPLACEMENT = 9,
    
    /** Lightmap texture (aka Ambient Occlusion)
     *
     *  Both 'Lightmaps' and dedicated 'ambient occlusion maps' are
     *  covered by this material property. The texture contains a
     *  scaling value for the final color value of a pixel. Its
     *  intensity is not affected by incoming light.
    */
    TextureType_LIGHTMAP = 10,
    
    /** Reflection texture
     *
     * Contains the color of a perfect mirror reflection.
     * Rarely used, almost never for real-time applications.
    */
    TextureType_REFLECTION = 11,
    
    /** PBR Materials
     * PBR definitions from maya and other modelling packages now use this standard.
     * This was originally introduced around 2012.
     * Support for this is in game engines like Godot, Unreal or Unity3D.
     * Modelling packages which use this are very common now.
     */
    
    TextureType_BASE_COLOR = 12,
    TextureType_NORMAL_CAMERA = 13,
    TextureType_EMISSION_COLOR = 14,
    TextureType_METALNESS = 15,
    TextureType_DIFFUSE_ROUGHNESS = 16,
    TextureType_AMBIENT_OCCLUSION = 17,
    
    /** Unknown texture
     *
     *  A texture reference that does not match any of the definitions
     *  above is considered to be 'unknown'. It is still imported,
     *  but is excluded from any further post-processing.
    */
    TextureType_UNKNOWN = 18,
  
  
    #ifndef SWIG
      _TextureType_Force32Bit = INT_MAX
    #endif
};

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

  struct MeshInfo
  {
    Vector4 vertex;
    Vector4 normal;
    Vector4 tangent;
    Vector2 texCoords;
    Vector4 bonesWeight[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    uint32 id_Bones[4] = { 0 };
  };

  struct ModelData
  {
    Vector<MeshInfo> meshData;
    Vector<uint32> index;
    Vector<Texture*> modelTextures;
    BONES_INFO* skeletal;
  };

  


  class XC_CORE_EXPORT ResourceModel
  {
   public:
    ResourceModel() = default;

    ResourceModel(const String& path);


    ~ResourceModel() = default;


   private:

    /**
     * @brief      loadModel function, to load the model
     * @param      path parameter one, path of the model
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    void 
    loadModel(const String& path);

    /**
     * @brief      processNode function, to process node of the model
     * @param      node parameter one, node of the model
     * @param      scene parameter two, scene of the model
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    void 
    processNode(const void* node,
                const void* scene);

    /**
     * @brief      processMesh function, to process node of the mesh
     * @param      mesh parameter one, mesh of the model
     * @param      scene parameter two, scene of the model
     * @bug		     No know Bugs
     * @return     Returns a mesh
     */
    ModelData
    processMesh(const void* mesh, 
                const void* scene);

    void 
    loadVertexData(const void* mesh, ModelData& data);

    void
    loadAnimationData(const void* mesh, ModelData& data);

    /**
     * @brief      LoadMaterialTextures function, to load material of the model
     * @param      mat parameter one, material of the model
     * @param      type parameter two, type of material of the model
     * @param      typeName parameter three, name of the material
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    void 
    loadMaterialTextures(const void* mat,
                         TEXTURE_TYPE type,
                         ModelData& data);


    String 
    getTexturePath(String file);

   private:

   // /**
   //  * @brief private variables
   //  */
   // // model data 
   // 
   // /**
   //  * @Variable m_Texturesloaded, is for all textures of the model
   //  */
   // Vector<Texture*> m_texturesloaded;
   // 
   // /**
   //  * @Variable m_vSamplers, is for all samplers
   //  */
   // Vector<SamplerState*> m_vSamplers;
   // 
   // /**
   //  * @Variable m_vMeshes, is for all Meshes
   //  */
   // Vector<Mesh>  m_vMeshes;

   // /**
   //  * @Variable m_Directory, directory of textures
   //  */
   String m_directory;

   // /**
   //  * @Variable m_Texture, texture of model
   //  */
   // Texture* m_texture = nullptr;

   // /**
   //  * @Variable m_Sampler, sampler of model
   //  */
   // SPtr<SamplerState> m_sampler;



    Vector<ModelData> m_vModelsData;

  };

}