/**
 * @class CGraphiAPI
 *
 * @brief class base for the GraphiAPI
 *
 * This class is the base for GraphiAPI of Directx and opengl
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 9/24/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include <windows.h>
#include <iostream>
#include <xcVector4.h>
#include <xcMatrix4x4.h>
#include <xcModule.h>
#include <SFML/Window/Window.hpp>

#include "xcPrerequisitesCore.h"
#include "xcPixelShader.h"
#include "xcTexture.h"
#include "xcVertexShader.h"
#include "xcConstantBuffer.h"
#include "xcInputLayout.h"
#include "xcCamera.h"

namespace xcEngineSDK {

  class Texture;
  class IndexBuffer;
  class VertexBuffer;
  class ConstantBuffer;
  class ComputeBuffer;
  class PixelShader;
  class VertexShader;
  class SamplerState;
  class PixelShader;
  class VertexShader;
  class InputLayout;
  class RasterizerState;
  class ShaderProgram;
  class DepthStencilState;
  class BlendState;
  
  namespace TEXTURE_FORMAT {
    enum E {
      kTF_UNKNOWN = 0,
      kTF_R32G32B32A32_TYPELESS = 1,
      kTF_R32G32B32A32_FLOAT = 2,
      kTF_R32G32B32A32_UINT = 3,
      kTF_R32G32B32A32_SINT = 4,
      kTF_R32G32B32_TYPELESS = 5,
      kTF_R32G32B32_FLOAT = 6,
      kTF_R32G32B32_UINT = 7,
      kTF_R32G32B32_SINT = 8,
      kTF_R16G16B16A16_TYPELESS = 9,
      kTF_R16G16B16A16_FLOAT = 10,
      kTF_R16G16B16A16_UNORM = 11,
      kTF_R16G16B16A16_UINT = 12,
      kTF_R16G16B16A16_SNORM = 13,
      kTF_R16G16B16A16_SINT = 14,
      kTF_R32G32_TYPELESS = 15,
      kTF_R32G32_FLOAT = 16,
      kTF_R32G32_UINT = 17,
      kTF_R32G32_SINT = 18,
      kTF_R32G8X24_TYPELESS = 19,
      kTF_D32_FLOAT_S8X24_UINT = 20,
      kTF_R32_FLOAT_X8X24_TYPELESS = 21,
      kTF_X32_TYPELESS_G8X24_UINT = 22,
      kTF_R10G10B10A2_TYPELESS = 23,
      kTF_R10G10B10A2_UNORM = 24,
      kTF_R10G10B10A2_UINT = 25,
      kTF_R11G11B10_FLOAT = 26,
      kTF_R8G8B8A8_TYPELESS = 27,
      kTF_R8G8B8A8_UNORM = 28,
      kTF_R8G8B8A8_UNORM_SRGB = 29,
      kTF_R8G8B8A8_UINT = 30,
      kTF_R8G8B8A8_SNORM = 31,
      kTF_R8G8B8A8_SINT = 32,
      kTF_R16G16_TYPELESS = 33,
      kTF_R16G16_FLOAT = 34,
      kTF_R16G16_UNORM = 35,
      kTF_R16G16_UINT = 36,
      kTF_R16G16_SNORM = 37,
      kTF_R16G16_SINT = 38,
      kTF_R32_TYPELESS = 39,
      kTF_D32_FLOAT = 40,
      kTF_R32_FLOAT = 41,
      kTF_R32_UINT = 42,
      kTF_R32_SINT = 43,
      kTF_R24G8_TYPELESS = 44,
      kTF_D24_UNORM_S8_UINT = 45,
      kTF_R24_UNORM_X8_TYPELESS = 46,
      kTF_X24_TYPELESS_G8_UINT = 47,
      kTF_R8G8_TYPELESS = 48,
      kTF_R8G8_UNORM = 49,
      kTF_R8G8_UINT = 50,
      kTF_R8G8_SNORM = 51,
      kTF_R8G8_SINT = 52,
      kTF_R16_TYPELESS = 53,
      kTF_R16_FLOAT = 54,
      kTF_D16_UNORM = 55,
      kTF_R16_UNORM = 56,
      kTF_R16_UINT = 57,
      kTF_R16_SNORM = 58,
      kTF_R16_SINT = 59,
      kTF_R8_TYPELESS = 60,
      kTF_R8_UNORM = 61,
      kTF_R8_UINT = 62,
      kTF_R8_SNORM = 63,
      kTF_R8_SINT = 64,
      kTF_A8_UNORM = 65,
      kTF_R1_UNORM = 66,
      kTF_R9G9B9E5_SHAREDEXP = 67,
      kTF_R8G8_B8G8_UNORM = 68,
      kTF_G8R8_G8B8_UNORM = 69,
      kTF_BC1_TYPELESS = 70,
      kTF_BC1_UNORM = 71,
      kTF_BC1_UNORM_SRGB = 72,
      kTF_BC2_TYPELESS = 73,
      kTF_BC2_UNORM = 74,
      kTF_BC2_UNORM_SRGB = 75,
      kTF_BC3_TYPELESS = 76,
      kTF_BC3_UNORM = 77,
      kTF_BC3_UNORM_SRGB = 78,
      kTF_BC4_TYPELESS = 79,
      kTF_BC4_UNORM = 80,
      kTF_BC4_SNORM = 81,
      kTF_BC5_TYPELESS = 82,
      kTF_BC5_UNORM = 83,
      kTF_BC5_SNORM = 84,
      kTF_B5G6R5_UNORM = 85,
      kTF_B5G5R5A1_UNORM = 86,
      kTF_B8G8R8A8_UNORM = 87,
      kTF_B8G8R8X8_UNORM = 88,
      kTF_R10G10B10_XR_BIAS_A2_UNORM = 89,
      kTF_B8G8R8A8_TYPELESS = 90,
      kTF_B8G8R8A8_UNORM_SRGB = 91,
      kTF_B8G8R8X8_TYPELESS = 92,
      kTF_B8G8R8X8_UNORM_SRGB = 93,
      kTF_BC6H_TYPELESS = 94,
      kTF_BC6H_UF16 = 95,
      kTF_BC6H_SF16 = 96,
      kTF_BC7_TYPELESS = 97,
      kTF_BC7_UNORM = 98,
      kTF_BC7_UNORM_SRGB = 99,
      kTF_AYUV = 100,
      kTF_Y410 = 101,
      kTF_Y416 = 102,
      kTF_NV12 = 103,
      kTF_P010 = 104,
      kTF_P016 = 105,
      kTF_420_OPAQUE = 106,
      kTF_YUY2 = 107,
      kTF_Y210 = 108,
      kTF_Y216 = 109,
      kTF_NV11 = 110,
      kTF_AI44 = 111,
      kTF_IA44 = 112,
      kTF_P8 = 113,
      kTF_A8P8 = 114,
      kTF_B4G4R4A4_UNORM = 115,

      kTF_P208 = 130,
      kTF_V208 = 131,
      kTF_V408 = 132,

      kTF_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE = 189,
      kTF_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE = 190,

      kTF_FORCE_UINT = 0xffffffff
    };
  }

  namespace CPU_ACCESS_FLAG {
    enum E {
      kCPU_ACCESS_DEFAULT = 0,
      kCPU_ACCESS_WRITE = 0x10000L,
      kCPU_ACCESS_READ = 0x20000L
    };
  }

  namespace TEXTURE_BIND_FLAG {
    enum E {
      kTEXTURE_BIND_SHADER_RESOURCE = 0x8L,
      kTEXTURE_BIND_RENDER_TARGET = 0x20L,
      kTEXTURE_BIND_DEPTH_STENCIL = 0x40L,
      kTEXTURE_BIND_UNORDERED_ACCESS = 0x80L
    };
  }

  namespace TYPE_USAGE {
    enum E {
      kTYPE_USAGE_DEFAULT = 0,
      kTYPE_USAGE_IMMUTABLE = 1,
      kTYPE_USAGE_DYNAMIC = 2,
      kTYPE_USAGE_STAGING = 3
    };
  }

  namespace CLEAR_FLAG {
    enum E {
      kCLEAR_DEPTH = 0x1L,
      kCLEAR_STENCIL = 0x2L
    };
  }

  namespace PRIMITIVE_TOPOLOGY {
    enum E {
      kPRIMITIVE_TOPOLOGY_UNDEFINED = 0,
      kPRIMITIVE_TOPOLOGY_POINTLIST = 1,
      kPRIMITIVE_TOPOLOGY_LINELIST = 2,
      kPRIMITIVE_TOPOLOGY_LINESTRIP = 3,
      kPRIMITIVE_TOPOLOGY_TRIANGLELIST = 4,
      kPRIMITIVE_TOPOLOGY_TRIANGLESTRIP = 5,
      kPRIMITIVE_TOPOLOGY_LINELIST_ADJ = 10,
      kPRIMITIVE_TOPOLOGY_LINESTRIP_ADJ = 11,
      kPRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ = 12,
      kPRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ = 13,
      kPRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST = 33,
      kPRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST = 34,
      kPRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST = 35,
      kPRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST = 36,
      kPRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST = 37,
      kPRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST = 38,
      kPRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST = 39,
      kPRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST = 40,
      kPRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST = 41,
      kPRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST = 42,
      kPRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST = 43,
      kPRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST = 44,
      kPRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST = 45,
      kPRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST = 46,
      kPRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST = 47,
      kPRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST = 48,
      kPRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST = 49,
      kPRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST = 50,
      kPRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST = 51,
      kPRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST = 52,
      kPRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST = 53,
      kPRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST = 54,
      kPRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST = 55,
      kPRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST = 56,
      kPRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST = 57,
      kPRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST = 58,
      kPRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST = 59,
      kPRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST = 60,
      kPRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST = 61,
      kPRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST = 62,
      kPRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST = 63,
      kPRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST = 64,
    };
  }

  namespace FILL_MODE {
    enum E {

      kFILL_WIREFRAME = 2,
      kFILL_SOLID = 3
    };
  }

  namespace CULL_MODE {
    enum E {

      kCULL_NONE = 1,
      kCULL_FRONT = 2,
      kCULL_BACK = 3
    };
  }

  namespace COMPARISON_FUNC {
    enum E {
      kCOMPARISON_NEVER = 1,
      kCOMPARISON_LESS = 2,
      kCOMPARISON_EQUAL = 3,
      kCOMPARISON_LESS_EQUAL = 4,
      kCOMPARISON_GREATER = 5,
      kCOMPARISON_NOT_EQUAL = 6,
      kCOMPARISON_GREATER_EQUAL = 7,
      kCOMPARISON_ALWAYS = 8
    };
  }

  namespace TEXTURE_ADDRESS_MODE {
    enum E {
      kTEXTURE_ADDRESS_WRAP = 1,
      kTEXTURE_ADDRESS_MIRROR = 2,
      kTEXTURE_ADDRESS_CLAMP = 3,
      kTEXTURE_ADDRESS_BORDER = 4,
      kTEXTURE_ADDRESS_MIRROR_ONCE = 5
    };
  }

  namespace FILTER {
    enum E {
      kFILTER_MIN_MAG_MIP_POINT = 0,
      kFILTER_MIN_MAG_POINT_MIP_LINEAR = 0x1,
      kFILTER_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x4,
      kFILTER_MIN_POINT_MAG_MIP_LINEAR = 0x5,
      kFILTER_MIN_LINEAR_MAG_MIP_POINT = 0x10,
      kFILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x11,
      kFILTER_MIN_MAG_LINEAR_MIP_POINT = 0x14,
      kFILTER_MIN_MAG_MIP_LINEAR = 0x15,
      kFILTER_ANISOTROPIC = 0x55,
      kFILTER_COMPARISON_MIN_MAG_MIP_POINT = 0x80,
      kFILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR = 0x81,
      kFILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x84,
      kFILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR = 0x85,
      kFILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT = 0x90,
      kFILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x91,
      kFILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT = 0x94,
      kFILTER_COMPARISON_MIN_MAG_MIP_LINEAR = 0x95,
      kFILTER_COMPARISON_ANISOTROPIC = 0xd5,
      kFILTER_MINIMUM_MIN_MAG_MIP_POINT = 0x100,
      kFILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR = 0x101,
      kFILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x104,
      kFILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR = 0x105,
      kFILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT = 0x110,
      kFILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x111,
      kFILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT = 0x114,
      kFILTER_MINIMUM_MIN_MAG_MIP_LINEAR = 0x115,
      kFILTER_MINIMUM_ANISOTROPIC = 0x155,
      kFILTER_MAXIMUM_MIN_MAG_MIP_POINT = 0x180,
      kFILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR = 0x181,
      kFILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x184,
      kFILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR = 0x185,
      kFILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT = 0x190,
      kFILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x191,
      kFILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT = 0x194,
      kFILTER_MAXIMUM_MIN_MAG_MIP_LINEAR = 0x195,
      kFILTER_MAXIMUM_ANISOTROPIC = 0x1d5
    };
  }

  struct TextureDesc
  {
    uint32 width;
    uint32 height;
    uint32 numTexture;
    TEXTURE_FORMAT::E textureFormat;
    uint32 bindFlags;
    TYPE_USAGE::E usage;
  };

  struct SimpleVertex
  {
    Vector3	Position;
    Vector2 TexCoords;
  };

  struct CBNeverChanges
  {
    Matrix4x4 mView;
    Matrix4x4 mProjection;
    Matrix4x4 mWorld;
  };

  struct CBTransform
  {
    Vector3 mObjectPosition;
  };

  struct CBSSAO
  {
    float mSampleradius;
    float mIntensity;
    float mScale;
    float mBias;
  };

  struct CBHISTOGRAM
  {
    uint32 countR[256];
    uint32 countG[256];
    uint32 countB[256];
    Vector2 fViewportDimensions;

  };

  struct COUNTRG {
    uint32 countR[256];
    uint32 countG[256];
  };

  struct COUNTB {

    uint32 countB[256];
  };


  struct CBSSAO_TEXTURE
  {
    float mWidth;
    float mHeight;
  };

  struct CBBLUR
  {
    //Vector4 mViewporDimension;
    float mViewporDimensionX;
    float mViewporDimensionY;
    float mWidth;
    float mHeight;
  };

  struct CBLIGHT 
  {
    Vector3 Light_pos0;
    Vector4 vViewPosition;
    float LightIntensity_0;
    //float EmissiveIntensity;

    Matrix4x4 matView;
    Matrix4x4 matWorld;
  };

  struct CBLIGHTCAMERA
  {

    Matrix4x4 matView;
    Matrix4x4 matProjection;
  };

  struct CBINVERSE
  {
    Matrix4x4 matInverseView;
  };

  struct BoneVertex {
    Vector3 vertex;
    Vector2 texCoords;
    Vector3 normal;
    Vector3 tangent;
    Vector3 biTangent;

    Vector4 bonesWeight[4] = { 0.0f, 0.0f, 0.0f, 0.0f};
    uint32 id_Bones[4] = { 0 };
  };

  struct ColorStruct
  {
    float R { };
    float G { };
    float B { };
    float A { };

    void
    setColor(float r, float g, float b, float a) {
      R = r;
      G = g;
      B = b;
      A = a;
    }
  };

  struct InputLayout_Desc
  {
    Vector<String> Semantics;
    Vector<uint32> Formats;
  };

  struct CCameraDatas
  {

    /**< struct Vector3 front. */
    Vector3 front;

    /**< struct Vector3 position. */
    Vector3 position;

    /**< struct Vector3 at. */
    Vector3 at;

    /**< struct Vector3 up. */
    Vector3 up;

    /**< struct Vector3 Rigth. */
    Vector3 Rigth;

    /**< struct float W. */
    float W;

    /**< struct float H. */
    float H;

    /**< struct float Near. */
    float Near;

    /**< struct float Far. */
    float Far;

    /**< struct float Fov. */
    float Fov;
  };

  class XC_CORE_EXPORT GraphicsAPI : public Module<GraphicsAPI>
  {
   protected:
    /**
     * @brief protected functions
     */


    /**
     * @brief      initWindow function, to create window for the api
     * @param      width parameter one, width of the window
     * @param      height parameter two, height of the window
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    initWindow(uint32,
               uint32) { };

    /**
     * @brief      createDeviceandSwap function, to create device and swap chain
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    
    virtual void 
    createDeviceandSwap(sf::WindowHandle window) { };

    /**
     * @brief      createDeferredContext function, to create Deferred Context
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    createDeferredContext() { };

   public:

    /// Default Constructor
     GraphicsAPI() = default;

    /// Destructor
    ~GraphicsAPI() = default;


    FORCEINLINE void
    setObject(GraphicsAPI* api) {
      GraphicsAPI::_instance() = api;
    }

    /**
     * @brief public functions
     */


    virtual void
    getDataComputeBuffer(WeakSptr<ComputeBuffer> computeBuffer) {};

    /**
      * @brief      init function, to init the api
      * @param      width parameter one, width of the window
      * @param      height parameter two, height of the window
      * @bug		    No know Bugs
      * @return     Returns nothing
    */
    //init(sf::WindowHandle window)
    virtual void 
    init(sf::WindowHandle window) {

      //initWindow(width, height);
      createDeviceandSwap(window);
    }


    /**
     * @brief      initMatrixWorld function, to init the world matrix
     * @param      MatrixWorld parameter one, a matrix world to modification 
     * @return     Returns a world matrix initialize
     */
    virtual Matrix4x4 
    initMatrixWorld(Matrix4x4&) { return Matrix4x4(); };

    /**
     * @brief      initMatrixView function, to init the view matrix
     * @param      MatrixView parameter one, a matrix view to modification
     * @param      Eye parameter one, eye for the matrix
     * @param      At parameter one, lookat for the matrix
     * @param      Up parameter one, lookat for the matrix
     * @bug		     No know Bugs
     * @return     Returns a view matrix initialize
     */
    virtual Matrix4x4 
    initMatrixView(Matrix4x4&,
                   Vector3&,
                   Vector3&,
                   Vector3&) { return Matrix4x4(); };

    /**
     * @brief      initMatrixProjection function, to init the view matrix
     * @param      MatrixProjection parameter one, a matrix projection to modification
     * @param      Fov parameter one,feel of view for the matrix
     * @param      Height parameter one, Height for the matrix
     * @param      Width parameter one, Width for the matrix
     * @param      Near parameter one, Near for the matrix
     * @param      Far parameter one, Far for the matrix
     * @bug		    No know Bugs
     * @return     Returns a view matrix initialize
     */
    virtual Matrix4x4 
    initMatrixProjection(Matrix4x4&,
                         float&,
                         float&,
                         float&,
                         float&,
                         float&) { return Matrix4x4(); };

    /**
     * @brief      LoadModel function, to load model
     * @param      API parameter one, Api to have access the functions
     * @param      ID parameter two, id for the vertex buffer
     * @bug		     No know Bugs
     * @return     Returns a pointer of CBuffer
     */
    /*virtual Model* LoadModel(GraphiAPI* API,
                            InputLayout_Desc InpLayDesc,
                            string Path) { return nullptr; };*/

    //create


    /**
     * @brief      createVertexBuffer function, to create vertex buffer
     * @param      bindFlags parameter one, bind Flags for the desc of vertex buffer
     * @param      Ver parameter two, a vector whit SimpleVertex
     * @param      NumBuffer parameter three, id for the vertex buffer
     * @bug		     No know Bugs
     * @return     Returns a pointer of CBuffer
     */

    virtual SPtr<VertexBuffer>
    createVertexBuffer(const Vector<BoneVertex>&,
                       uint32 = 0) { return nullptr; };

    /**
     * @brief      createIndexBuffer function, to create index buffer
     * @param      Ind parameter one, a vector unsigned ints of indices
     * @param      NumBuffer parameter two, NumBuffer for the index buffer
     * @bug		     No know Bugs
     * @return     Returns a pointer of CBuffer
     */
    virtual SPtr<IndexBuffer>
    createIndexBuffer(const Vector<uint32_t>&,
                      uint32 = 0) { return nullptr; };

    /**
     * @brief      createConstantBuffer function, to create constant buffer
     *             Never Change
     * @param      BufferSize parameter one, buffer size
     * @param      NumBuffer parameter two, number of buffer
     * @param      Data parameter three, void pointer for the data
     * @bug		     No know Bugs
     * @return     Returns a pointer of CBuffer
     */
    virtual SPtr<ConstantBuffer>
    createConstantBuffer(uint32,
                         uint32 = 0,
                         const void* = nullptr,
                         TYPE_USAGE::E usage = TYPE_USAGE::kTYPE_USAGE_DEFAULT,
                         CPU_ACCESS_FLAG::E cpu_acces = 
                         CPU_ACCESS_FLAG::kCPU_ACCESS_DEFAULT)
                         { return nullptr; };

    virtual SPtr<ComputeBuffer>
    createComputeBuffer(uint32 size,
                        uint32 numElemnts,
                        TYPE_USAGE::E usage,
                        TEXTURE_FORMAT::E format,
                        const void* data) { return nullptr; };



    /**
     * @brief      createTexture1D function, to create a texture
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    createTexture1D() { };

    /**
     * @brief      createTexture2D function, to create a texture 2D
     * @param      width parameter one, width of the texture
     * @param      height parameter two, height of the texture
     * @param      numberTexture parameter three, Number of the texture we are create
     * @param      format parameter four, format for the desc of the texture
     * @param      bindFlags parameter five, bind Flags for the desc of the texture
     * @param      Usage parameter six, Usage for the desc of the texture
     * @bug		     No know Bugs
     * @return     Returns a pointer of CTexture
     */
    virtual Texture*
    createTexture2D(uint32,
                    uint32,
                    uint32, //deberia estar en la clase texture
                    TEXTURE_FORMAT::E = TEXTURE_FORMAT::kTF_R8G8B8A8_UNORM,
                    uint32 = TEXTURE_BIND_FLAG::kTEXTURE_BIND_SHADER_RESOURCE,
                    TYPE_USAGE::E = TYPE_USAGE::kTYPE_USAGE_DEFAULT,
                    const void* Data = nullptr) { Data; return nullptr; };

    /**
     * @brief      createTexture3D function, to create a texture 3D
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    createTexture3D() { };

    /**
     * @brief      createShaderProgram function, to create shader program
     * @param      FileNameVS parameter one, name of the file of the vertex shader
     * @param      FileNamePS parameter two, name of the file of the pixel shader
     * @param      EntryVS parameter three, point of entry in the file vertex shader
     * @param      EntryPS parameter four, point of entry in the file pixel shader
     * @param      ShaderModelVS parameter five, shader model vertex shader
     * @param      ShaderModelPS parameter six, shader model pixel shader
     * @param      NumVertexShader parameter seven, number of the vertex shader
     * @param      NumPixelShader parameter eight, number of the pixel shader
     * @bug		     No know Bugs
     * @return     Returns a pointer of ShaderProgram
     */
    virtual SPtr<ShaderProgram>
    createShaderProgram(const String&,
                        const String&,
                        const String& = "",
                        const String& = "",
                        const String& = "",
                        const String& = "",
                        int32 = 0,
                        int32 = 0) { return nullptr; }; //no va


    /**
     * @brief      createComputeProgram function, to create shader program
     * @param      FileNameCS parameter one, name of the file of the vertex shader
     * @param      EntryCS parameter three, point of entry in the file vertex shader
     * @param      ShaderModelCS parameter five, shader model vertex shader
     * @bug		     No know Bugs
     * @return     Returns a pointer of ShaderProgram
     */
    virtual SPtr<ShaderProgram>
    createComputeShader(const String&,
                         const String& = "",
                         const String& = "") { return nullptr; };

    /**
     * @brief      createPixelShaders function, to create pixel shader
     * @param      FileName parameter one, name of the file of the pixel shader
     * @param      Entry parameter two, point of entry in the file
     * @param      ShaderModel parameter three, shader model of pixel shader
     * @param      NumPixelShader parameter four, number of the pixel shader
     * @bug		     No know Bugs
     * @return     Returns a pointer of CPixelShader
     */
    virtual SPtr<PixelShader>
    createPixelShaders(const String&,
                       const String& = "",
                       const String& = "",
                       int32 = 0) { return nullptr; }; //no va


    /**
     * @brief      createVertexShaders function, to create vertex shader
     * @param      FileName parameter one, name of the file of the vertex shader
     * @param      Entry parameter two, point of entry in the file
     * @param      ShaderModel parameter three, shader model of vertex shader
     * @param      NumVertexShader parameter four, number of the vertex shader
     * @bug		     No know Bugs
     * @return     Returns a pointer of CVertexShader
     */
    virtual	SPtr<VertexShader>
    createVertexShaders(const String&,
                        const String& = "",
                        const String& = "",
                        int32 = 0) { return nullptr; }; //no va

    /**
     * @brief      CreateInputLayoutDesc function, to create the descriptor of the
     *             input layout
     * @param      SemanticsVector parameter one, a vector of semantics
     * @param      FormatsVector parameter two, a vector of formats
     * @bug		No know Bugs
     * @return     Returns a pointer of InputLayout_Desc
     */
    virtual InputLayout_Desc 
    CreateInputLayoutDesc(Vector<String> SemanticsVector,
                          Vector<uint32> FormatsVector) {
                          InputLayout_Desc Temp;
                          return Temp; };

    /**
     * @brief      createInputLayout function, to create the input layout
     * @param      Vertex parameter one, a pointer of vertex shader for use his blop
     * @param      SemanticName parameter two, a vector of string with semantic name
     * @param      NumInputLayout parameter three, number of input layout
     * @bug		     No know Bugs
     * @return     Returns a pointer of CInputLayout
     */
    virtual SPtr<InputLayout>
    createInputLayout(ShaderProgram&,
                      InputLayout_Desc&,
                      uint32 = 0) { return nullptr; }; //no va

    /**
     * @brief      createAutomaticInputLayout function, to create an automatic 
     *             input layout
     * @param      ShaderProgram parameter one, a pointer of ShaderProgram for use his blop
     * @bug		     No know Bugs
     * @return     Returns a pointer of CInputLayout
     */
    virtual SPtr<InputLayout>
    createAutomaticInputLayout(ShaderProgram&) { return nullptr; };


    /**
     * @brief      createSamplerState function, to create the sampler state
     * @param      NumSamplerState parameter one, number of sampler state
     * @bug		     No know Bugs
     * @return     Returns a pointer of CSamplerState
     */
    virtual SPtr<SamplerState>
    createSamplerState(uint32 = 0,
                       float mipLoDBias = 0.0f,
                       float mionLOD = -3.402823466e+38F,
                       float maxLOD = 3.402823466e+38F,
                       COMPARISON_FUNC::E = COMPARISON_FUNC::kCOMPARISON_NEVER,
                       TEXTURE_ADDRESS_MODE::E = 
                       TEXTURE_ADDRESS_MODE::kTEXTURE_ADDRESS_CLAMP,
                       FILTER::E = FILTER::kFILTER_MIN_MAG_MIP_LINEAR)
                      { return nullptr; }; //no va

    /**
     * @brief      createRasterizerState function, to create the rasterizer state
     * @param      fill_mode parameter one, fill mode
     * @param      cull_mode parameter two, cull mode
     * @bug		     No know Bugs
     * @return     Returns a pointer of CRasterizerState
     */
    virtual SPtr<RasterizerState>
    createRasterizerState(FILL_MODE::E, CULL_MODE::E, bool) { return nullptr;};

    /**
     * @brief      creteaDepthStencilState function, to create the depth 
     *             stencil state
     * @param      stencilEnable parameter one, 
     * @param      depthEnable parameter two, 
     * @bug		     No know Bugs
     * @return     Returns a pointer of CRasterizerState
     */
    virtual SPtr<DepthStencilState>
    createDepthStencilState(bool stencilEnable, bool depthEnable) { return nullptr; };

    virtual SPtr<BlendState>
    createBlendState() { return nullptr; };

    //set

    /**
     * @brief      setVertexBuffer function, to set vertex buffer
     * @param      VerBuff parameter one, a pointer of CVertexBuffer
     * @param      StartSlot parameter two, start slot for set vertex buffer
     * @param      NumBuffer parameter three, number of buffer
     * @param      stride parameter four, stride for set vertex buffer
     * @param      offset parameter five, offset for set vertex buffer
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setVertexBuffer(WeakSptr<VertexBuffer>,
                    uint32,
                    uint32,
                    uint32, //deben estar en la clase buffer
                    uint32) { }; //deben estar en la clase buffer

    /**
     * @brief      setIndexBuffer function, to set index buffer
     * @param      IndBuff parameter one, a pointer of CIndexBuffer
     * @param      offset parameter two, offset for set index buffer
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setIndexBuffer(WeakSptr<IndexBuffer>,
                   uint32) { }; //deben estar en la clase buffer

    virtual void
    setComputeBuffer(WeakSptr<ComputeBuffer>,
                     uint32,
                     uint32) { };

    virtual void
    setComputeBufferRTUAV(Texture*,
                          uint32,
                          uint32) { };

    /**
     * @brief      setVSConstantBuffer function, to set constant
     *             buffer of the vertex shader
     * @param      ConstBuff parameter one, a pointer of CConstantBuffer
     * @param      StartSlot parameter two, start slot for set constant buffer
     * @param      NumBuffer parameter three, number of buffer
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setVSConstantBuffer(WeakSptr<ConstantBuffer>,
                        uint32,
                        uint32) { };

    /**
     * @brief      setPSConstantBuffer function, to set constant
     *             buffer of the pixel shader
     * @param      ConstBuff parameter one, a pointer of CConstantBuffer
     * @param      StartSlot parameter two, start slot for set constant buffer
     * @param      NumBuffer parameter three, number of buffer
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setPSConstantBuffer(WeakSptr<ConstantBuffer>,
                        uint32,
                        uint32) { };

    /**
     * @brief      setCSConstantBuffer function, to set constant 
     *             buffer of the compute shader
     * @param      ConstBuff parameter one, a pointer of CConstantBuffer
     * @param      StartSlot parameter two, start slot for set constant buffer
     * @param      NumBuffer parameter three, number of buffer
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setCSConstantBuffer(WeakSptr<ConstantBuffer>,
                        uint32,
                        uint32) { };

    /**
     * @brief      setShaderProgram function, to set pixel and vertex shader
     * @param      Pixel parameter one, a pointer of CShaderProgram
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setShaderProgram(WeakSptr<ShaderProgram>) { };

    virtual void 
    setComputeShader(WeakSptr<ShaderProgram>) { };


    /**
     * @brief      setPS function, to set pixel shader
     * @param      Pixel parameter one, a pointer of CPixelShader
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setPS(WeakSptr<PixelShader>) { };

    /**
     * @brief      setVS function, to set vertex shader
     * @param      Pixel parameter one, a pointer of CVertexShader
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setVS(WeakSptr<VertexShader>) { };

    virtual void
    setBackBuffer(Texture*) {};

    /**
     * @brief      setInputLayout function, to set input layout
     * @param      Inp parameter one, a pointer of CInputLayout
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setInputLayout(WeakSptr<InputLayout>) { };

    /**
     * @brief      setSamplerState function, to set sampler state
     * @param      Sam parameter one, a pointer of CSamplerState
     * @param      StartSlot parameter two, start slot for set sampler state
     * @param      NumSamplers parameter three, number of sampler
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setSamplerState(const Vector<SPtr<SamplerState>>& ,
                    uint32) { }; //

    virtual void
    setSamplerStateCS(const Vector<SPtr<SamplerState>>& ,
                      uint32) { };

    /**
     * @brief      setDepthStencil function, to set depth stencil
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setDepthStencil(WeakSptr<Texture>) { }; ///necesita recibir una textura

    /**
     * @brief      setRasterizerState function, to set rasteraizer state
     * @param      RasState parameter one, a pointer of RasterizerState
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setRasterizerState(WeakSptr<RasterizerState>) { };

    /**
     * @brief      setDepthStencilState function, to set depth stencil state
     * @param      depthStelcilState parameter one, a pointer of DepthStencilState
     * @param      stencilRef parameter two, a uint32 
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void
    setDepthStencilState(WeakSptr<DepthStencilState>, uint32) { };

    /**
     * @brief      setRenderTarget function, to set render target
     * @param      pRTTex parameter one, a pointer of CTexture
     * @param      pDSTex parameter two, a pointer of CTexture
     * @param      NumView parameter three, number of render target view
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setRenderTarget(const Vector<Texture*>&,
                    Texture*) { };

    /**
     * @brief      setShaderResouerce function, to set shader resource
     * @param      pRTTex parameter one, a pointer of CTexture
     * @param      pDSTex parameter two, 
     * @param      NumView parameter three, number of render target view
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setShaderResource(const Vector<Texture*>&,
                      uint32 = 0) { };
    virtual void
    setShaderResourceCS(const Vector<Texture*>&,
                       uint32 = 0) {};



    /**
     * @brief      setViewport function, to set viewport
     * @param      NumViewport parameter one, number of viewport
     * @param      Width parameter two, width for the desc of viewport
     * @param      Height parameter three, height for the desc of viewport
     * @param      TopLeftX parameter four, TopLeftX for the desc of viewport
     * @param      TopLeftY parameter five, TopLeftY for the desc of viewport
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setViewport(uint32,
                float,
                float,
                float = 0,
                float = 0) { }; //falta checar eje z

    /**
     * @brief      setPrimitiveTopology function, to set primitive topology
     * @param      PRIMITIVE_TOPOLOGY parameter one, topology to set
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setPrimitiveTopology(PRIMITIVE_TOPOLOGY::E =
    PRIMITIVE_TOPOLOGY::kPRIMITIVE_TOPOLOGY_TRIANGLELIST) { };

    /**
     * @brief      setDefaultRenderTarget function, to set default render taret
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setDefaultRenderTarget() { };


    virtual Matrix4x4
    matri4x4Context(const Matrix4x4&) { return Matrix4x4(); }

    //clear

    /**
     * @brief      clearRendTarView function, to clear the render target view
     * @param      RT parameter one, a pointer of CTexture
     * @param      ClearColor parameter two, of for the color of back buffer
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    clearRenderTarget(Texture*,
                      ColorStruct) { };

    /**
     * @brief      clearDepthStenView function, to clear the depth stencil view
     * @param      RT parameter one, a pointer of CTexture
     * @param      ClerFlag parameter two, a flag for clear the depth stencil view
     * @param      Depth parameter three, a depth for clear the depth stencil view
     * @param      Stencil parameter fourt, a stencil for clear the depth stencil view
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    clearDepthStencil(Texture*,
                      uint32 = CLEAR_FLAG::kCLEAR_DEPTH,
                      float = 1.0f,
                      uint32 = 0) { };

    /**
     * @brief      clearDefaultRenderTargetAndDepthStencil function, to
     *             clear default render target and depth stencil
     * @param      Color parameter one, of for the color of back buffer
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    clearDefaultRenderTargetAndDepthStencil(ColorStruct) { };


    /**
     * @brief      updateSubresource function, update the source
     * @param      Data parameter one, data to update constant buffer
     * @param      ConstantBufffer parameter two, constant buffer
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    updateSubresource(const void*,
                      ConstantBuffer&) { };


    /**
       * @brief      textureFromFile function, to load texture from file
       * @param      path parameter one, path of the texture
       * @bug		     No know Bugs
       * @return     Returns nothing
     */
    virtual Texture*
    textureFromFile(String path) {return nullptr;};


    virtual void
    dispatch(uint32,uint32,uint32) { };

    virtual void
    desbindingUAV(uint32,
                  uint32) { };

    virtual void
    desbindingRT() { };

    virtual void
    desbindingSR(const Vector<Texture*>&, uint32) { };


    //draw

    /**
      * @brief      DrawModel function, to draw model
      * @param      ShaderPro parameter one, shader program for the model
      * @bug		    No know Bugs
      * @return     Returns nothing
    */
    //virtual void DrawModel(CShaderProgram& ShaderPro) { };

    /**
     * @brief      drawIndexed function, to draw
     * @param      SizeIndex parameter one, num of index
     * @param      StartindexLocation parameter two, start index location
     * @param      BaseVertexLocation parameter two, base vertex location
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    drawIndexed(uint32,
                uint32,
                uint32,
                const void*) { };

    /**
     * @brief      drawInstanced function, to draw
     * @param      VertexCountPerInstance parameter one, Number of vertices to draw
     * @param      InstanceCount parameter two, Number of instances to draw
     * @param      StartVertexLocation parameter two, Index of the first vertex.
     * @param      StartInstanceLocation parameter one, A value added to each index before
     *             reading per-instance data from a vertex buffer
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    drawInstanced(uint32,
                  uint32,
                  uint32,
                  uint32) { };

    /**
     * @brief      draw function, to draw
     * @param      VertexCount parameter one, Number of vertices to draw
     * @param      StartVertexLocation parameter two, Index of the first vertex, which is
                   usually an offset in a vertex buffer
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    draw(uint32,
         uint32) { };

    //swap

    /**
     * @brief      present function, to do swap with swapchain
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    present() { };


    //Clear
    virtual void 
    destroy() { };

    void
    setConstBufferBones(WeakSptr<ConstantBuffer> consBuff) {
      m_bufferBonesAnimation = consBuff.lock();
    }

    SPtr<ConstantBuffer>
    getConstBufferBones() {
      return m_bufferBonesAnimation;
    }

   public:

    /**
     * @brief protected variables member
     */

    /**
     * @Variable m_Width, width of the window
     */
    uint32 m_width = 900;

    /**
     * @Variable m_Height, height of the window
     */
    uint32 m_height = 900;

    /**
     * @Variable m_cbBonesAni, constant buffer of animations
     */
    SPtr<ConstantBuffer> m_bufferBonesAnimation = nullptr;


    sf::Window m_window;
  };

  /**
   * @brief export the instance 
   */
  XC_CORE_EXPORT GraphicsAPI& g_graphicsAPI();

  /**
   * @Variable funProtoGraphiAPI, instance of the class
   */
  using funProtoGraphiAPI = GraphicsAPI * (*)();

  

}




