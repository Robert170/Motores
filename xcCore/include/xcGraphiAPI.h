/**
 * @class CGraphiAPI
 *
 * @brief class base for the GraphiApi
 *
 * This class is the base for graphiapi of Directx and opengl
 *
 * @author Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 9/24/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include <xcPrerequisitesCore.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <xcVector4.h>
#include <xcMatrix4x4.h>
#include <xcModule.h>

#include "xcPixelShader.h"
#include "xcTexture.h"
#include "xcVertexShader.h"
#include "xcConstantBuffer.h"
#include "xcInputLayout.h"

namespace xcEngineSDK {

  class TextureB;
  class IndexBuffer;
  class VertexBuffer;
  class ConstantBuffer;
  class PixelShader;
  class VertexShader;
  class SamplerState;
  class PixelShader;
  class VertexShader;
  class InputLayout;
  class RasterizerState;
  class ShaderProgram;
  class Model;

  using TEXTURE_FORMAT = enum
  {
    TF_UNKNOWN = 0,
    TF_R32G32B32A32_TYPELESS = 1,
    TF_R32G32B32A32_FLOAT = 2,
    TF_R32G32B32A32_UINT = 3,
    TF_R32G32B32A32_SINT = 4,
    TF_R32G32B32_TYPELESS = 5,
    TF_R32G32B32_FLOAT = 6,
    TF_R32G32B32_UINT = 7,
    TF_R32G32B32_SINT = 8,
    TF_R16G16B16A16_TYPELESS = 9,
    TF_R16G16B16A16_FLOAT = 10,
    TF_R16G16B16A16_UNORM = 11,
    TF_R16G16B16A16_UINT = 12,
    TF_R16G16B16A16_SNORM = 13,
    TF_R16G16B16A16_SINT = 14,
    TF_R32G32_TYPELESS = 15,
    TF_R32G32_FLOAT = 16,
    TF_R32G32_UINT = 17,
    TF_R32G32_SINT = 18,
    TF_R32G8X24_TYPELESS = 19,
    TF_D32_FLOAT_S8X24_UINT = 20,
    TF_R32_FLOAT_X8X24_TYPELESS = 21,
    TF_X32_TYPELESS_G8X24_UINT = 22,
    TF_R10G10B10A2_TYPELESS = 23,
    TF_R10G10B10A2_UNORM = 24,
    TF_R10G10B10A2_UINT = 25,
    TF_R11G11B10_FLOAT = 26,
    TF_R8G8B8A8_TYPELESS = 27,
    TF_R8G8B8A8_UNORM = 28,
    TF_R8G8B8A8_UNORM_SRGB = 29,
    TF_R8G8B8A8_UINT = 30,
    TF_R8G8B8A8_SNORM = 31,
    TF_R8G8B8A8_SINT = 32,
    TF_R16G16_TYPELESS = 33,
    TF_R16G16_FLOAT = 34,
    TF_R16G16_UNORM = 35,
    TF_R16G16_UINT = 36,
    TF_R16G16_SNORM = 37,
    TF_R16G16_SINT = 38,
    TF_R32_TYPELESS = 39,
    TF_D32_FLOAT = 40,
    TF_R32_FLOAT = 41,
    TF_R32_UINT = 42,
    TF_R32_SINT = 43,
    TF_R24G8_TYPELESS = 44,
    TF_D24_UNORM_S8_UINT = 45,
    TF_R24_UNORM_X8_TYPELESS = 46,
    TF_X24_TYPELESS_G8_UINT = 47,
    TF_R8G8_TYPELESS = 48,
    TF_R8G8_UNORM = 49,
    TF_R8G8_UINT = 50,
    TF_R8G8_SNORM = 51,
    TF_R8G8_SINT = 52,
    TF_R16_TYPELESS = 53,
    TF_R16_FLOAT = 54,
    TF_D16_UNORM = 55,
    TF_R16_UNORM = 56,
    TF_R16_UINT = 57,
    TF_R16_SNORM = 58,
    TF_R16_SINT = 59,
    TF_R8_TYPELESS = 60,
    TF_R8_UNORM = 61,
    TF_R8_UINT = 62,
    TF_R8_SNORM = 63,
    TF_R8_SINT = 64,
    TF_A8_UNORM = 65,
    TF_R1_UNORM = 66,
    TF_R9G9B9E5_SHAREDEXP = 67,
    TF_R8G8_B8G8_UNORM = 68,
    TF_G8R8_G8B8_UNORM = 69,
    TF_BC1_TYPELESS = 70,
    TF_BC1_UNORM = 71,
    TF_BC1_UNORM_SRGB = 72,
    TF_BC2_TYPELESS = 73,
    TF_BC2_UNORM = 74,
    TF_BC2_UNORM_SRGB = 75,
    TF_BC3_TYPELESS = 76,
    TF_BC3_UNORM = 77,
    TF_BC3_UNORM_SRGB = 78,
    TF_BC4_TYPELESS = 79,
    TF_BC4_UNORM = 80,
    TF_BC4_SNORM = 81,
    TF_BC5_TYPELESS = 82,
    TF_BC5_UNORM = 83,
    TF_BC5_SNORM = 84,
    TF_B5G6R5_UNORM = 85,
    TF_B5G5R5A1_UNORM = 86,
    TF_B8G8R8A8_UNORM = 87,
    TF_B8G8R8X8_UNORM = 88,
    TF_R10G10B10_XR_BIAS_A2_UNORM = 89,
    TF_B8G8R8A8_TYPELESS = 90,
    TF_B8G8R8A8_UNORM_SRGB = 91,
    TF_B8G8R8X8_TYPELESS = 92,
    TF_B8G8R8X8_UNORM_SRGB = 93,
    TF_BC6H_TYPELESS = 94,
    TF_BC6H_UF16 = 95,
    TF_BC6H_SF16 = 96,
    TF_BC7_TYPELESS = 97,
    TF_BC7_UNORM = 98,
    TF_BC7_UNORM_SRGB = 99,
    TF_AYUV = 100,
    TF_Y410 = 101,
    TF_Y416 = 102,
    TF_NV12 = 103,
    TF_P010 = 104,
    TF_P016 = 105,
    TF_420_OPAQUE = 106,
    TF_YUY2 = 107,
    TF_Y210 = 108,
    TF_Y216 = 109,
    TF_NV11 = 110,
    TF_AI44 = 111,
    TF_IA44 = 112,
    TF_P8 = 113,
    TF_A8P8 = 114,
    TF_B4G4R4A4_UNORM = 115,

    TF_P208 = 130,
    TF_V208 = 131,
    TF_V408 = 132,

    TF_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE = 189,
    TF_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE = 190,

    TF_FORCE_UINT = 0xffffffff
  };

  using TEXTURE_BIND_FLAG = enum
  {
    TEXTURE_BIND_SHADER_RESOURCE = 0x8L,
    TEXTURE_BIND_RENDER_TARGET = 0x20L,
    TEXTURE_BIND_DEPTH_STENCIL = 0x40L,
    TEXTURE_BIND_UNORDERED_ACCESS = 0x80L,
  };

  using TYPE_USAGE = enum
  {
    TYPE_USAGE_DEFAULT = 0,
    TYPE_USAGE_IMMUTABLE = 1,
    TYPE_USAGE_DYNAMIC = 2,
    TYPE_USAGE_STAGING = 3
  };

  using CLEAR_FLAG = enum
  {
    CLEAR_DEPTH = 0x1L,
    CLEAR_STENCIL = 0x2L
  };

  using PRIMITIVE_TOPOLOGY = enum
  {
    PRIMITIVE_TOPOLOGY_UNDEFINED = 0,
    PRIMITIVE_TOPOLOGY_POINTLIST = 1,
    PRIMITIVE_TOPOLOGY_LINELIST = 2,
    PRIMITIVE_TOPOLOGY_LINESTRIP = 3,
    PRIMITIVE_TOPOLOGY_TRIANGLELIST = 4,
    PRIMITIVE_TOPOLOGY_TRIANGLESTRIP = 5,
    PRIMITIVE_TOPOLOGY_LINELIST_ADJ = 10,
    PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ = 11,
    PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ = 12,
    PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ = 13,
    PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST = 33,
    PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST = 34,
    PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST = 35,
    PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST = 36,
    PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST = 37,
    PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST = 38,
    PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST = 39,
    PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST = 40,
    PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST = 41,
    PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST = 42,
    PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST = 43,
    PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST = 44,
    PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST = 45,
    PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST = 46,
    PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST = 47,
    PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST = 48,
    PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST = 49,
    PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST = 50,
    PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST = 51,
    PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST = 52,
    PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST = 53,
    PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST = 54,
    PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST = 55,
    PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST = 56,
    PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST = 57,
    PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST = 58,
    PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST = 59,
    PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST = 60,
    PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST = 61,
    PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST = 62,
    PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST = 63,
    PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST = 64,

  };

  struct SimpleVertex
  {
    Vector3	Pos;
    Vector2 Tex;
    //glm::vec3 Pos;
    //glm::vec2 Tex;
  };

  struct ColorStruct
  {
    float R { };
    float G { };
    float B { };
    float A { };
  };

  struct InputLayout_Desc
  {
    std::vector<std::string> Semantics;
    std::vector<unsigned int> Formats;
  };

  struct CCameraDatas
  {
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

  class XC_CORE_EXPORT GraphiAPI : public Module<GraphiAPI>
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
    createDeviceandSwap() { };

    /**
     * @brief      createDeferredContext function, to create Deferred Context
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    createDeferredContext() { };

   public:

    /// Default Constructor
    GraphiAPI() = default;

    /// Destructor
    ~GraphiAPI() = default;


    FORCEINLINE void
    setObject(GraphiAPI* api) {
      GraphiAPI::_instance() = api;
    }

    /**
     * @brief public functions
     */


    /**
      * @brief      init function, to init the api
      * @param      width parameter one, width of the window
      * @param      height parameter two, height of the window
      * @bug		    No know Bugs
      * @return     Returns nothing
    */
    virtual void 
    init(uint32 width,
         uint32 height) {

      initWindow(width, height);
      createDeviceandSwap();
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
    /*virtual CModel* LoadModel(CGraphiAPI* API,
                            InputLayout_Desc InpLayDesc,
                            std::string Path) { };*/

    //create


    /**
     * @brief      createVertexBuffer function, to create vertex buffer
     * @param      bindFlags parameter one, bind Flags for the desc of vertex buffer
     * @param      Ver parameter two, a vector whit SimpleVertex
     * @param      NumBuffer parameter three, id for the vertex buffer
     * @bug		     No know Bugs
     * @return     Returns a pointer of CBuffer
     */

    virtual VertexBuffer* 
    createVertexBuffer(const std::vector <SimpleVertex>&,
                       uint32 = 0) { return nullptr; };

    /**
     * @brief      createIndexBuffer function, to create index buffer
     * @param      Ind parameter one, a vector unsigned ints of indices
     * @param      NumBuffer parameter two, NumBuffer for the index buffer
     * @bug		     No know Bugs
     * @return     Returns a pointer of CBuffer
     */
    virtual IndexBuffer* 
    createIndexBuffer(const std::vector<uint32_t>&,
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
    virtual ConstantBuffer* 
    createConstantBuffer(uint32,
                         uint32 = 0,
                         const void* = nullptr) { return nullptr; };



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
    virtual TextureB*
    createTexture2D(uint32,
                    uint32,
                    uint32, //deberia estar en la clase texture
                    TEXTURE_FORMAT = TF_R8G8B8A8_UNORM,
                    uint32 = TEXTURE_BIND_SHADER_RESOURCE,
                    TYPE_USAGE = TYPE_USAGE_DEFAULT) { return nullptr; };

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
     * @return     Returns a pointer of CPixelShader
     */
    virtual ShaderProgram* 
    createShaderProgram(const std::string&,
                        const std::string&,
                        const std::string& = "",
                        const std::string& = "",
                        const std::string& = "",
                        const std::string& = "",
                        int32 = 0,
                        int32 = 0) { return nullptr; }; //no va

    /**
     * @brief      createPixelShaders function, to create pixel shader
     * @param      FileName parameter one, name of the file of the pixel shader
     * @param      Entry parameter two, point of entry in the file
     * @param      ShaderModel parameter three, shader model of pixel shader
     * @param      NumPixelShader parameter four, number of the pixel shader
     * @bug		     No know Bugs
     * @return     Returns a pointer of CPixelShader
     */
    virtual PixelShader* 
    createPixelShaders(const std::string&,
                       const std::string& = "",
                       const std::string& = "",
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
    virtual	VertexShader* 
    createVertexShaders(const std::string&,
                        const std::string& = "",
                        const std::string& = "",
                        int32 = 0) { return nullptr; }; //no va
    /**
     * @brief      createInputLayout function, to create the input layout
     * @param      Vertex parameter one, a pointer of vertex shader for use his blop
     * @param      SemanticName parameter two, a vector of string with semantic name
     * @param      NumInputLayout parameter three, number of input layout
     * @bug		     No know Bugs
     * @return     Returns a pointer of CInputLayout
     */
    virtual InputLayout* 
    createInputLayout(ShaderProgram&,
                      InputLayout_Desc&,
                      uint32 = 0) { return nullptr; }; //no va

    /**
     * @brief      createSamplerState function, to create the sampler state
     * @param      NumSamplerState parameter two, number of sampler state
     * @bug		     No know Bugs
     * @return     Returns a pointer of CSamplerState
     */
    virtual SamplerState* 
    createSamplerState(uint32 = 0) { return nullptr; }; //no va

    /**
     * @brief      createRasterizerState function, to create the sampler state
     * @bug		     No know Bugs
     * @return     Returns a pointer of CRasterizerState
     */
    virtual RasterizerState* 
    createRasterizerState() { return nullptr; }; //falta parametros


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
    setVertexBuffer(VertexBuffer*,
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
    setIndexBuffer(IndexBuffer*,
                   uint32) { }; //deben estar en la clase buffer

    /**
     * @brief      setVertexShaderConstantBuffer function, to set constant
     *             buffer of the vertex shader
     * @param      ConstBuff parameter one, a pointer of CConstantBuffer
     * @param      StartSlot parameter two, start slot for set constant buffer
     * @param      NumBuffer parameter three, number of buffer
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setVertexShaderConstantBuffer(ConstantBuffer*,
                                  uint32,
                                  uint32) { };

    /**
     * @brief      setPixelShaderConstantBuffer function, to set constant
     *             buffer of the pixel shader
     * @param      ConstBuff parameter one, a pointer of CConstantBuffer
     * @param      StartSlot parameter two, start slot for set constant buffer
     * @param      NumBuffer parameter three, number of buffer
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setPixelShaderConstantBuffer(ConstantBuffer*,
                                 uint32,
                                 uint32) { };

    /**
     * @brief      setShaderProgram function, to set pixel and vertex shader
     * @param      Pixel parameter one, a pointer of CShaderProgram
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setShaderProgram(ShaderProgram*) { };


    /**
     * @brief      setPixelShaders function, to set pixel shader
     * @param      Pixel parameter one, a pointer of CPixelShader
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setPixelShaders(PixelShader*) { };

    /**
     * @brief      setVertexShaders function, to set vertex shader
     * @param      Pixel parameter one, a pointer of CVertexShader
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setVertexShaders(VertexShader*) { };

    /**
     * @brief      setInputLayout function, to set input layout
     * @param      Inp parameter one, a pointer of CInputLayout
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setInputLayout(InputLayout*) { };

    /**
     * @brief      setSamplerState function, to set sampler state
     * @param      Sam parameter one, a pointer of CSamplerState
     * @param      StartSlot parameter two, start slot for set sampler state
     * @param      NumSamplers parameter three, number of sampler
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setSamplerState(const std::vector<SamplerState*>& ,
                    uint32) { }; //

    /**
     * @brief      setDepthStencil function, to set depth stencil
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setDepthStencil(TextureB*) { }; ///necesita recibir una textura

    /**
     * @brief      setRasterizerState function, to set rasteraizer state
     * @param      RasState parameter one, a pointer of CRasterizerState
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setRasterizerState(RasterizerState*) { };

    /**
     * @brief      setRenderTarget function, to set render target
     * @param      pRTTex parameter one, a pointer of CTexture
     * @param      pDSTex parameter two, a pointer of CTexture
     * @param      NumView parameter three, number of render target view
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setRenderTarget(const std::vector<TextureB*>&,
                    TextureB* = nullptr) { };

    /**
     * @brief      setShaderResouerce function, to set shader resource
     * @param      pRTTex parameter one, a pointer of CTexture
     * @param      pDSTex parameter two, a pointer of CTexture
     * @param      NumView parameter three, number of render target view
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setShaderResource(const std::vector<TextureB*>&,
                      uint32 = 0) { };

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
    setPrimitiveTopology(PRIMITIVE_TOPOLOGY =
                         PRIMITIVE_TOPOLOGY_TRIANGLELIST) { };

    /**
     * @brief      setDefaultRenderTarget function, to set default render taret
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    setDefaultRenderTarget() { };

    //clear

    /**
     * @brief      clearRendTarView function, to clear the render target view
     * @param      RT parameter one, a pointer of CTexture
     * @param      ClearColor parameter two, of for the color of back buffer
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    clearRenderTarget(TextureB*,
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
    clearDepthStencil(TextureB*,
                      uint32 = CLEAR_DEPTH,
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
     * @param      ConstantBufffer parameter two, consant buffer
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    virtual void 
    updateSubresource(const void*,
                      ConstantBuffer&) { };


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


   protected:

    /**
     * @brief protected variables member
     */

    /**
     * @Variable m_Width, width of the window
     */
    unsigned int m_width = 800;

    /**
     * @Variable m_Height, height of the window
     */
    unsigned int m_height = 600;
  };

  /**
   * @brief export the instance 
   */
  XC_CORE_EXPORT GraphiAPI& g_graphiAPI();

  /**
   * @Variable funProtoGraphiApi, instance of the class
   */
  using funProtoGraphiApi = GraphiAPI * (*)();

  

}


