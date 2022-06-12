/**
 * @class CDXGraphiAPI
 *
 * @brief class for the api of directx
 *
 * This class is the ejecutate directx
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 9/24/2020
 *
 *
 * @bug	No know Bugs
 */

#pragma once
#include "xcPrerequisitesDX.h"
#include "xcGraphiAPI.h"
#include "xcTextureDX.h"


namespace xcEngineSDK {

    class DXGraphiAPI : public GraphicsAPI
    {
     private:

        /**
         * @brief private variables member
         */

        /**
         * @Variable m_hWnd, a variable for a window
         */
        HWND m_hWnd;

        /**
         * @Variable m_pd3dDevice, pointer for the device
         */
        ID3D11Device* m_pd3dDevice;


        /**
            * @Variable m_pImmediateContext, pointer for the device context
        */
        ID3D11DeviceContext* m_pImmediateContext;

        /**
            * @Variable m_pSwapChain, pointer for the swap chain
        */
        IDXGISwapChain* m_pSwapChain;



        SPtr<Texture> m_backBuffer;

        SPtr<Texture> m_depthStencil;


     protected:
        /**
            * @brief protected functions
        */

    void
    getDataComputeBuffer(WeakSptr<ComputeBuffer> computeBuffer) override;

        /**
         * @brief      initWindow function, to create window for the api
         * @param      width parameter one, width of the window
         * @param      height parameter two, height of the window
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void
        initWindow(uint32 width,
                       uint32 height) override;

        /**
         * @brief      createDeviceandSwap function, to create device and swap chain
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void
      createDeviceandSwap(sf::WindowHandle window) override;

        /**
         * @brief      createDeferredContext function, to create Deferred Context
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void
        createDeferredContext() override;

     public:



        /// Default Constructor
        DXGraphiAPI();

        /// Destructor
        ~DXGraphiAPI();

        /**
            * @brief public functions
        */

        /**
         * @brief      initMatrixWorld function, to init the world matrix
         * @param      MatrixWorld parameter one, a matrix world to modification 
         * @return     Returns a world matrix initialize
         */
        Matrix4x4 
        initMatrixWorld(Matrix4x4& MatrixWorld) override;

        /**
         * @brief      initMatrixView function, to init the view matrix
         * @param      MatrixView parameter one, a matrix view to modification
         * @param      Eye parameter one, eye for the matrix
         * @param      At parameter one, lookat for the matrix
         * @param      Up parameter one, lookat for the matrix
         * @bug		     No know Bugs
         * @return     Returns a view matrix initialize
         */
        Matrix4x4 
        initMatrixView(Matrix4x4& MatrixView,
                         Vector3& Eye,
                         Vector3& At,
                         Vector3& Up) override;

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
        Matrix4x4 
        initMatrixProjection(Matrix4x4& MatrixProjection,
                               float& Fov,
                               float& Height,
                               float& Width,
                               float& Near,
                               float& Far) override;

        /**
            * @brief      LoadModel function, to load model
            * @param      Model parameter one, object to load model
            * @param      API parameter two, Api to have acces the functions
            * @param      ID parameter three, id for the vertex buffer
            * @bug		   No know Bugs
            * @return     Returns a pointer of CBuffer
        */
        /*Model* loadModel(Model* Model,
                           GraphiAPI* API,
                           InputLayout_Desc InpLayDesc,
                           String Path);*/
        //create

        /**
       * @brief      createVertexBuffer function, to create vertex buffer
       * @param      Ver parameter one, a vector with simpleVertes
       * @param      NumBuffer parameter two, number of buffers
       * @bug		     No know Bugs
       * @return     Returns a pointer of CBuffer
       */

        SPtr<VertexBuffer> 
        createVertexBuffer(const Vector<BoneVertex>& Ver,
                             uint32 NumBuffer = 0) override;

        /**
         * @brief      createIndexBuffer function, to create index buffer
         * @param      Ind parameter one, a vector uint32s of indices
         * @param      NumBuffer parameter two, NumBuffer for the index buffer
         * @bug		     No know Bugs
         * @return     Returns a pointer of CBuffer
         */
        SPtr<IndexBuffer> 
        createIndexBuffer(const Vector<int32_t>& Ind,
                            uint32 NumBuffer = 0) override;

        /**
         * @brief      createConstantBuffer function, to create constant buffer
         *             Never Change
         * @param      BufferSize parameter one, buffer size
         * @param      NumBuffer parameter two, number of buffer
         * @param      Data parameter three, void pointer for the data
         * @bug		     No know Bugs
         * @return     Returns a pointer of CBuffer
         */
        SPtr<ConstantBuffer> 
        createConstantBuffer(uint32 BufferSize,
                               uint32 NumBuffer = 0,
                               const void* Data = nullptr,
                         TYPE_USAGE::E usage = TYPE_USAGE::kTYPE_USAGE_DEFAULT,
                         CPU_ACCESS_FLAG::E cpu_acces =
                         CPU_ACCESS_FLAG::kCPU_ACCESS_DEFAULT) override;

    SPtr<ComputeBuffer>
    createComputeBuffer(uint32 size,
                              uint32 numElemnts,
                              TYPE_USAGE::E usage,
                              TEXTURE_FORMAT::E format,
                              const void* data) override;


        /**
         * @brief      createTexture1D function, to create a texture
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        createTexture1D() override;

      /**
        * @brief      createTexture2D function, to create a texture 2D
        * @param      width parameter one, width of the texture
        * @param      height parameter two, height of the texture
        * @param      numberTexture parameter three, Number of the texture we are create
        * @param      format parameter four, format for the desc of the texture
        * @param      bindFlags parameter five, bind Flags for the desc of the texture
        * @param      Usage parameter six, Usage for the desc of the texture
        * @bug		  No know Bugs
        * @return     Returns a pointer of CTexture
        */
      Texture*
      createTexture2D(uint32 width,
                      uint32 height,
                      uint32 numberTexture, //deberia estar en la clase texture
                      TEXTURE_FORMAT::E format,
                      uint32 bindFlags,
                      TYPE_USAGE::E Usage,
                      const void* Data,
                      uint32 numChanels = 4) override;

        /**
         * @brief      createTexture3D function, to create a texture 3D
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        createTexture3D() override;

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
        SPtr<ShaderProgram> 
        createShaderProgram(const String& FileNameVS,
                              const String& FileNamePS,
                              const String& EntryVS = "",
                              const String& EntryPS = "",
                              const String& ShaderModelVS = "",
                              const String& ShaderModelPS = "",
                              int32 NumVertexShader = 0,
                              int32 NumPixelShader = 0) override; //no va

        /**
     * @brief      createComputeProgram function, to create shader program
     * @param      FileNameCS parameter one, name of the file of the vertex shader
     * @param      EntryCS parameter three, point of entry in the file vertex shader
     * @param      ShaderModelCS parameter five, shader model vertex shader
     * @bug		     No know Bugs
     * @return     Returns a pointer of ShaderProgram
     */
    SPtr<ShaderProgram>
    createComputeShader(const String& FileNameCS,
                        const String& EntryCS = "",
                        const String& ShaderModelCS = "") override;

        /**
       * @brief      createPixelShaders function, to create pixel shader
       * @param      FileName parameter one, name of the file of the pixel shader
       * @param      Entry parameter two, point of entry in the file
       * @param      ShaderModel parameter three, shader model of pixel shader
       * @param      NumPixelShader parameter four, number of the pixel shader
       * @bug		     No know Bugs
       * @return     Returns a pointer of CPixelShader
     */
        SPtr<PixelShader> 
        createPixelShaders(const String& FileName,
                             const String& Entry = "",
                             const String& ShaderModel = "",
                             int32 NumPixelShader = 0) override; //no va


    /**
       * @brief      createVertexShaders function, to create vertex shader
       * @param      FileName parameter one, name of the file of the vertex shader
       * @param      Entry parameter two, point of entry in the file
       * @param      ShaderModel parameter three, shader model of vertex shader
       * @param      NumVertexShader parameter four, number of the vertex shader
       * @bug		     No know Bugs
       * @return     Returns a pointer of CVertexShader
     */
        SPtr<VertexShader> 
        createVertexShaders(const String& FileName,
                              const String& Entry = "",
                              const String& ShaderModel = "",
                              int32 NumVertexShader = 0) override; //no va

        /**
       * @brief      CreateInputLayoutDesc function, to create the descriptor of the
       *             input layout
       * @param      SemanticsVector parameter one, a vector of semantics
       * @param      FormatsVector parameter two, a vector of formats
       * @bug		No know Bugs
       * @return     Returns a pointer of InputLayout_Desc
      */
      InputLayout_Desc 
    CreateInputLayoutDesc(Vector<String> SemanticsVector,
                          Vector<uint32> FormatsVector) override;

    /**
     * @brief      createInputLayout function, to create the input layout
     * @param      Vertex parameter one, a pointer of vertex shader for use his blop
     * @param      SemanticName parameter two, a vector of string with semantic name
     * @param      NumInputLayout parameter three, number of input layout
     * @bug		     No know Bugs
     * @return     Returns a pointer of CInputLayout
     */
        SPtr<InputLayout> 
        createInputLayout(ShaderProgram& Vertex,
                            InputLayout_Desc& LayoutDesc,
                            uint32 NumInputLayout = 0) override; //no va

         /**
         * @brief      createAutomaticInputLayout function, to create an automatic
         *             input layout
         * @param      Vertex parameter one, a pointer of vertex shader for use his blop
         * @bug		     No know Bugs
         * @return     Returns a pointer of CInputLayout
         */
         SPtr<InputLayout>
         createAutomaticInputLayout(ShaderProgram& VS);

        /**
     * @brief      createSamplerState function, to create the sampler state
     * @param      NumSamplerState parameter two, number of sampler state
     * @bug		     No know Bugs
     * @return     Returns a pointer of CSamplerState
     */
        SPtr<SamplerState>
        createSamplerState(uint32 NumSamplerState, 
                             float mipLoDBias,
                       float mionLOD,
                       float maxLOD,
                       COMPARISON_FUNC::E comparisonFun,
                       TEXTURE_ADDRESS_MODE::E textureAddressMode,
                       FILTER::E filter) override; //no va

        /**
         * @brief      createRasterizerState function, to create the sampler state
         * @bug		     No know Bugs
         * @return     Returns a pointer of CRasterizerState
         */
        SPtr<RasterizerState> 
        createRasterizerState(FILL_MODE::E fillMode,
                                CULL_MODE::E cullMode,
                                bool counterClockwise) override; //falta parametros

        /**
     * @brief      creteDepthStencilState function, to create the depth 
     *             stencil state
     * @param      stencilEnable parameter one, 
     * @param      depthEnable parameter two, 
     * @bug		     No know Bugs
     * @return     Returns a pointer of CRasterizerState
     */
    SPtr<DepthStencilState>
    createDepthStencilState(bool stencilEnable, bool depthEnable) override;

    SPtr<BlendState>
    createBlendState() override;


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
        void 
        setVertexBuffer(WeakSptr<VertexBuffer> VerBuff,
                          uint32 StartSlot,
                          uint32 NumBuffers,
                          uint32 stride, //deben estar en la clase buffer
                          uint32 offset) override; //deben estar en la clase buffer

    /**
       * @brief      setIndexBuffer function, to set index buffer
       * @param      IndBuff parameter one, a pointer of CIndexBuffer
       * @param      offset parameter two, offset for set index buffer
       * @bug		     No know Bugs
       * @return     Returns nothing
     */
        void 
        setIndexBuffer(WeakSptr<IndexBuffer> IndBuff,
                         uint32 offset) override; //deben estar en la clase buffer


        /**
       * @brief      setVSConstantBuffer function, to set constant
       *             buffer of the vertex shader
       * @param      ConstBuff parameter one, a pointer of CConstantBuffer
       * @param      StartSlot parameter two, start slot for set constant buffer
       * @param      NumBuffer parameter three, number of buffer
       * @bug		     No know Bugs
       * @return     Returns nothing
     */
        void 
        setVSConstantBuffer(WeakSptr<ConstantBuffer> ConstBuff,
                              uint32 StartSlot,
                              uint32 NumBuffers) override;

        /**
         * @brief      setPSConstantBuffer function, to set constant
         *             buffer of the pixel shader
         * @param      ConstBuff parameter one, a pointer of CConstantBuffer
         * @param      StartSlot parameter two, start slot for set constant buffer
         * @param      NumBuffer parameter three, number of buffer
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        setPSConstantBuffer(WeakSptr<ConstantBuffer> ConstBuff,
                              uint32 StartSlot,
                              uint32 NumBuffers) override;

        /**
     * @brief      setCSConstantBuffer function, to set constant 
     *             buffer of the compute shader
     * @param      ConstBuff parameter one, a pointer of CConstantBuffer
     * @param      StartSlot parameter two, start slot for set constant buffer
     * @param      NumBuffer parameter three, number of buffer
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    void 
    setCSConstantBuffer(WeakSptr<ConstantBuffer> ConstBuff,
                        uint32 StartSlot,
                        uint32 NumBuffers) override;

        void
    setComputeBuffer(WeakSptr<ComputeBuffer> compBuff,
                     uint32 StartSlot,
                     uint32 NumBuffer) override;

        void
    setComputeBufferRTUAV(Texture* compBuffUAV,
                          uint32 StartSlot,
                          uint32 NumBuffer) override;

        /**
         * @brief      setShaderProgram function, to set pixel and vertex shader
         * @param      Pixel parameter one, a pointer of CShaderProgram
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        setShaderProgram(WeakSptr<ShaderProgram> shaderProgram) override;


        void 
    setComputeShader(WeakSptr<ShaderProgram> computeShade) override;


        /**
         * @brief      setPS function, to set pixel shader
         * @param      Pixel parameter one, a pointer of CPixelShader
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        setPS(WeakSptr<PixelShader> Pixel) override;

        /**
         * @brief      setVS function, to set vertex shader
         * @param      Pixel parameter one, a pointer of CVertexShader
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        setVS(WeakSptr<VertexShader> Vertex) override;

    void
    setBackBuffer(Texture* backBuff);

        /**
         * @brief      setInputLayout function, to set input layout
         * @param      Inp parameter one, a pointer of CInputLayout
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        setInputLayout(WeakSptr<InputLayout> Inp) override;

        /**
         * @brief      setSamplerState function, to set sampler state
         * @param      Sam parameter one, a pointer of CSamplerState
         * @param      StartSlot parameter two, start slot for set sampler state
         * @param      NumSamplers parameter three, number of sampler
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        setSamplerState(const Vector<SPtr<SamplerState>>& Sam,
                          uint32 StartSlot) override; //

        void
    setSamplerStateCS(const Vector<SPtr<SamplerState>>& Sam,
                      uint32 StartSlot) override;

    /**
       * @brief      setDepthStencil function, to set depth stencil
       * @bug		     No know Bugs
       * @return     Returns nothing
     */
        void 
        setDepthStencil(WeakSptr<Texture> pDSTex) override; ///necesita recibir una textura

        /**
         * @brief      setRasterizerState function, to set rasteraizer state
         * @param      RasState parameter one, a pointer of CRasterizerState
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        setRasterizerState(WeakSptr<RasterizerState> RasState) override;

        /**
     * @brief      setDepthStencilState function, to set depth stencil state
     * @param      depthStelcilState parameter one, a pointer of DepthStencilState
     * @param      stencilRef parameter two, a uint32 
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    void
    setDepthStencilState(WeakSptr<DepthStencilState> depthStelcilState, 
                               uint32 stencilRef) override;

        /**
         * @brief      setRenderTarget function, to set render target
         * @param      pRTTex parameter one, a pointer of CTexture
         * @param      pDSTex parameter two, a pointer of CTexture
         * @param      NumView parameter three, number of render target view
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        setRenderTarget(const Vector<Texture*>& pRTTex,
                          Texture* pDSTex) override;

        /**
         * @brief      setShaderResouerce function, to set shader resource
         * @param      pRTTex parameter one, a pointer of CTexture
         * @param      pDSTex parameter two, a pointer of CTexture
         * @param      NumView parameter three, number of render target view
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        setShaderResource(const Vector<Texture*>& pRTTex,
                            uint32 StartSlot = 0) override;

    void
    setShaderResourceCS(const Vector<Texture*>& pRTTex,
                        uint32 StartSlot = 0) override;


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
        void 
        setViewport(uint32 NumViewport,
                      float Width,
                      float Height,
                      float TopLeftX = 0,
                      float TopLeftY = 0) override; //falta checar eje z

        /**
       * @brief      setPrimitiveTopology function, to set primitive topology
       * @param      PRIMITIVE_TOPOLOGY parameter one, topology to set
       * @bug		     No know Bugs
       * @return     Returns nothing
     */
        void 
        setPrimitiveTopology(PRIMITIVE_TOPOLOGY::E Topology =
            PRIMITIVE_TOPOLOGY::kPRIMITIVE_TOPOLOGY_TRIANGLELIST) override;

        /**
         * @brief      setDefaultRenderTarget function, to set default render taret
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        setDefaultRenderTarget() override;


    Matrix4x4
    matri4x4Context(const Matrix4x4& matrix) override;

        //clear

        /**
         * @brief      clearRendTarView function, to clear the render target view
         * @param      RT parameter one, a pointer of CTexture
         * @param      ClearColor parameter two, of for the color of back buffer
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        clearRenderTarget(Texture* RT,
                            ColorStruct Color) override;

        /**
     * @brief      clearDepthStenView function, to clear the depth stencil view
     * @param      RT parameter one, a pointer of CTexture
     * @param      ClerFlag parameter two, a flag for clear the depth stencil view
     * @param      Depth parameter three, a depth for clear the depth stencil view
     * @param      Stencil parameter fourth, a stencil for clear the depth stencil view
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
        void 
        clearDepthStencil(Texture* RT,
                            uint32 ClerFlag = CLEAR_FLAG::kCLEAR_DEPTH,
                            float Depth = 1.0f,
                            uint32 Stencil = 0) override;

        /**
         * @brief      clearDefaultRenderTargetAndDepthStencil function, to
         *             clear default render target and depth stencil
         * @param      Color parameter one, of for the color of back buffer
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
      clearDefaultRenderTargetAndDepthStencil(ColorStruct Color) override;


        /**
         * @brief      updateSubresource function, update the source
         * @param      Data parameter one, data to update constant buffer
         * @param      ConstantBufffer parameter two, consant buffer
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        updateSubresource(const void* Data,
                            ConstantBuffer& ConstantBufffer) override;

      /**
       * @brief      textureFromFile function, to load texture from file
       * @param      path parameter one, path of the texture
       * @bug		     No know Bugs
       * @return     Returns nothing
       */
      Texture*
      textureFromFile(String path) override;

      Texture*
    textureFromData(uint32 width,
                      uint32 height,
                      uint32 numberTexture, //deberia estar en la clase texture
                      TEXTURE_FORMAT::E format,
                      uint32 bindFlags,
                      TYPE_USAGE::E Usage,
                  const void* Data,
                  uint32 numChanels) override;

      virtual Vector<Texture*>
      creaturTextureFromRGB(String path) override;

      void
      dispatch(uint32 a, uint32 b, uint32 c) override;


      void
      desbindingUAV(uint32,
                    uint32) override;

      void
      desbindingRT() override;

      void
      desbindingSR(const Vector<Texture*>& pRTTex, uint32 tipeShader)override;

        //draw

        /**
         * @brief      DrawModel function, to draw model
         * @param      Model parameter one, model to draw
         * @param      ShaderPro parameter two, shader program for the model
         * @bug		No know Bugs
         * @return     Returns nothing
         */
        /*void 
        drawModel(Model* Model,
                    ShaderProgram& ShaderPro);*/

        /**
         * @brief      drawIndexed function, to draw
         * @param      SizeIndex parameter one, num of index
         * @param      StartindexLocation parameter two, start index location
         * @param      BaseVertexLocation parameter two, base vertex location
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        drawIndexed(uint32 NumIndex,
                      uint32 StartindexLocation,
                      uint32 BaseVertexLocation,
                      const void* Index) override;

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
      void 
      drawInstanced(uint32 VertexCountPerInstance,
                    uint32 InstanceCount,
                    uint32 StartVertexLocation,
                    uint32 StartInstanceLocation) override;

        /**
         * @brief      draw function, to draw
         * @param      VertexCount parameter one, Number of vertices to draw
         * @param      StartVertexLocation parameter two, Index of the first vertex, which is
                                     usually an offset in a vertex buffer
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        draw(uint32 VertexCount,
               uint32 StartVertexLocation) override;

        //swap

        /**
         * @brief      present function, to do swap with swapchain
         * @bug		     No know Bugs
         * @return     Returns nothing
         */
        void 
        present() override;


        //Clear
        void 
        destroy() override;
    };

  extern "C" XC_PLUGIN_EXPORT GraphicsAPI * createGraphisAPI() {

        auto m_dxGraphiAPI = new DXGraphiAPI();

        return m_dxGraphiAPI;

  }

}
