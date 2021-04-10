#include <xcMatrix4x4.h>
#include <vector>


#include "xcDXGraphiAPI.h"
//#include "TextureDX.h"
#include "xcInputLayoutDX.h"
#include "xcIndexBufferDX.h"
#include "xcVertexBufferDX.h"
#include "xcConstantBufferDX.h"
#include "xcShaderProgramDX.h"
#include "xcVertexShaderDX.h"
#include "xcPixelShaderDX.h"
#include "xcSamplerStateDX.h"
#include "xcRasterizerStateDX.h"
#include "resource.h"



//TODO: Chequeo de errores
using std::vector;
namespace xcEngineSDK {

  LRESULT CALLBACK 
  WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message)
    {
    case WM_PAINT:
      hdc = BeginPaint(hWnd, &ps);
      EndPaint(hWnd, &ps);
      break;

    case WM_DESTROY:
      PostQuitMessage(0);
      break;

    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
  }

  DXGraphiAPI::DXGraphiAPI() {
    m_pd3dDevice = nullptr;
    m_pImmediateContext = nullptr;
    m_pSwapChain = nullptr;
    m_hWnd = nullptr;
  }

  DXGraphiAPI::~DXGraphiAPI() {
  }

  Matrix4x4 
  DXGraphiAPI::initMatrixWorld(Matrix4x4& MatrixWorld) {

    MatrixWorld = MatrixWorld.identity();

    return MatrixWorld.transpose();
  }

  Matrix4x4 
  DXGraphiAPI::initMatrixView(Matrix4x4& MatrixView,
                              Vector3& Eye,
                              Vector3& At,
                              Vector3& Up) {
    ////init view matrix TODO:
    //MatrixView = glm::lookAtLH(Eye,
      //At,
      //Up);

    return MatrixView.transpose();
  }

  Matrix4x4 
  DXGraphiAPI::initMatrixProjection(Matrix4x4& MatrixProjection,
                                    float& Fov,
                                    float& Height,
                                    float& Width,
                                    float& Near,
                                    float& Far) {
    //TODO:
    //MatrixProjection = glm::perspectiveFovLH(Fov,
      //Height,
      //Width,
      //Near,
      //Far);
    return MatrixProjection.transpose();
  }

  Model* 
  DXGraphiAPI::loadModel(Model* _Model, 
                         GraphiAPI* API, 
                         InputLayout_Desc 
                         InpLayDesc, std::string Path)
  {
    return nullptr;
  }

  //fuction to create a window
  void DXGraphiAPI::initWindow(unsigned int width,
                               unsigned int height) {

    auto WindowInstance = reinterpret_cast<HINSTANCE>(GetModuleHandle(nullptr));

    // Register class
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = WindowInstance;
    wcex.hIcon = LoadIcon(WindowInstance, (LPCTSTR)IDI_TUTORIAL1);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "DirectxWindow";
    wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_TUTORIAL1);
    if (!RegisterClassEx(&wcex))
      return;

    // Create window
    RECT rc = { 0, 0, width, height };
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
    m_hWnd = CreateWindow("DirectxWindow", 
                          "Direct3D 11 Tutorial 7", 
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, 
                          CW_USEDEFAULT, 
                          rc.right - rc.left, 
                          rc.bottom - rc.top, 
                          NULL, 
                          NULL, 
                          WindowInstance,
                          NULL);
    if (!m_hWnd)
    {
      std::cout << "//error fallo la creacion de la ventana" << std::endl;
      return;
    }


    ShowWindow(m_hWnd, 5);

    return;
  }

  //fuction to create device and swap chain
  void 
  DXGraphiAPI::createDeviceandSwap() {
    RECT rc;
    GetClientRect(m_hWnd, &rc);
    m_width = rc.right - rc.left;
    m_height = rc.bottom - rc.top;

    D3D_DRIVER_TYPE driverType = D3D_DRIVER_TYPE_NULL;
    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;

    UINT createDeviceFlags = 0;
#ifdef _DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    vector<D3D_DRIVER_TYPE> driverTypes =
    {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE,
    };

    vector<D3D_FEATURE_LEVEL> featureLevels =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };

    DXGI_SWAP_CHAIN_DESC sd;
    memset(&sd, 0, sizeof(sd));
    sd.BufferCount = 1;
    sd.BufferDesc.Width = m_width;
    sd.BufferDesc.Height = m_height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = m_hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;

    HRESULT hr = S_OK;

    for (auto& dType : driverTypes) {
      hr = D3D11CreateDeviceAndSwapChain(nullptr,
        dType,
        nullptr,
        createDeviceFlags,
        featureLevels.data(),
        featureLevels.size(),
        D3D11_SDK_VERSION,
        &sd,
        &m_pSwapChain,
        &m_pd3dDevice,
        &featureLevel,
        &m_pImmediateContext);
      if (SUCCEEDED(hr)) {
        break;
      }
    }
    if (FAILED(hr)) {
      std::cout << "//error fallo la creacion del device y swapchain" << std::endl;
      return;
    }

    auto BackBuffer = new TextureDX();

    hr = m_pSwapChain->GetBuffer(0,
                                 __uuidof(ID3D11Texture2D),
                                 (LPVOID*)&BackBuffer->m_pTexture);

    hr = m_pd3dDevice->CreateRenderTargetView(BackBuffer->m_pTexture,
                                              nullptr,
                                              &BackBuffer->m_pRTV);

    if (FAILED(hr))
    {
      std::cout << "//error fallo la creacion del render target view" << std::endl;
      return;
    }

    m_BackBuffer = BackBuffer;


    // Create default depth stencil texture


    auto DepthStencil = new TextureDX();

    D3D11_TEXTURE2D_DESC descDepth;
    ZeroMemory(&descDepth, sizeof(descDepth));
    descDepth.Width = m_width;
    descDepth.Height = m_height;
    descDepth.MipLevels = 1;
    descDepth.ArraySize = 1;
    descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    descDepth.SampleDesc.Count = 1;
    descDepth.SampleDesc.Quality = 0;
    descDepth.Usage = D3D11_USAGE_DEFAULT;
    descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    descDepth.CPUAccessFlags = 0;
    descDepth.MiscFlags = 0;
    hr = m_pd3dDevice->CreateTexture2D(&descDepth, NULL, &DepthStencil->m_pTexture);
    if (FAILED(hr))
      return;

    // Create the depth stencil view
    D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
    ZeroMemory(&descDSV, sizeof(descDSV));
    descDSV.Format = descDepth.Format;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    descDSV.Texture2D.MipSlice = 0;
    hr = m_pd3dDevice->CreateDepthStencilView(DepthStencil->m_pTexture, &descDSV, &DepthStencil->m_pDSV);
    if (FAILED(hr))
      return;

    m_DepthStencil = DepthStencil;

  }

  void 
  DXGraphiAPI::createDeferredContext() {
    m_pd3dDevice->CreateDeferredContext(0, &m_pImmediateContext);
  }


  //fuction to create a vertex buffer 
  VertexBuffer* 
  DXGraphiAPI::createVertexBuffer(const vector <SimpleVertex>& Ver,
                                  unsigned int BufferSize,
                                  unsigned int NumBuffer) {
    auto VertexBuffer = new VertexBufferDX();
    CD3D11_BUFFER_DESC BufferDesc(Ver.size() * sizeof(SimpleVertex),
                                  D3D11_BIND_VERTEX_BUFFER);

    D3D11_SUBRESOURCE_DATA InitData;
    ZeroMemory(&InitData, sizeof(InitData));
    InitData.pSysMem = Ver.data();

    HRESULT hr = m_pd3dDevice->CreateBuffer(&BufferDesc,
                                            &InitData,
                                            &VertexBuffer->m_pVertexBuffer);
    if (FAILED(hr)) {
      std::cout << "//error fallo la creacion del vertex buffer" << std::endl;
      return nullptr;
    }
    return VertexBuffer;

  }

  //fuction to create an index buffer 
  IndexBuffer* 
  DXGraphiAPI::createIndexBuffer(const std::vector<unsigned int>& Ind,
                                 unsigned int BufferSize,
                                 unsigned int NumBuffer) {
    auto IndexBuffer = new IndexBufferDX();
    CD3D11_BUFFER_DESC BufferDesc(Ind.size() * sizeof(unsigned int),
                                  D3D11_BIND_INDEX_BUFFER);

    D3D11_SUBRESOURCE_DATA InitData;
    ZeroMemory(&InitData, sizeof(InitData));
    InitData.pSysMem = &Ind.at(0);

    HRESULT hr = m_pd3dDevice->CreateBuffer(&BufferDesc,
                                            &InitData,
                                            &IndexBuffer->m_pIndexBuffer);

    if (FAILED(hr)) {
      std::cout << "//error fallo la creacion del Index buffer" << std::endl;
      return nullptr;
    }
    return IndexBuffer;
  }

  //fuction to create a constant buffer 
  ConstantBuffer* 
  DXGraphiAPI::createConstantBuffer(unsigned int BufferSize,
                                    unsigned int NumBuffer,
                                    const void* Data) {
    auto ConsBuffer = new ConstantBufferDX();

    CD3D11_BUFFER_DESC BufferDesc(BufferSize,
                                  D3D11_BIND_CONSTANT_BUFFER);

    HRESULT hr = m_pd3dDevice->CreateBuffer(&BufferDesc,
                                            nullptr,
                                            &ConsBuffer->m_pConstantBuffer);
    if (FAILED(hr)) {
      std::cout << "//Error fallo la creacion del Constant buffer Never" << std::endl;
      return nullptr;
    }
    return ConsBuffer;
  }

  void 
  DXGraphiAPI::createTexture1D() {
  }

  //fuction to create a texture 2D
  TextureB*
  DXGraphiAPI::createTexture2D(unsigned int width,
                               unsigned int height,
                               unsigned int numberTexture,
                               TEXTURE_FORMAT format,
                               unsigned int bindFlags,
                               TYPE_USAGE Usage) {
    HRESULT hr;
    auto texture = new TextureDX();


    CD3D11_TEXTURE2D_DESC desc(static_cast<DXGI_FORMAT>(format),
                               width,
                               height,
                               numberTexture,
                               0,
                               bindFlags,
                               static_cast<D3D11_USAGE>(Usage));

    //Crear textura
    hr = m_pd3dDevice->CreateTexture2D(&desc, 
                                       nullptr, 
                                       &texture->m_pTexture);
    if (FAILED(hr)) {
      std::cout << "//Error fallo la creacion de la textura" << std::endl;
      return nullptr;
    }

    //Checar que interfaces se van a crear
    if (bindFlags & D3D11_BIND_SHADER_RESOURCE) {//Crear SRV
      CD3D11_SHADER_RESOURCE_VIEW_DESC srvDesc(D3D11_SRV_DIMENSION_TEXTURE2D,
                                               static_cast<DXGI_FORMAT>(format));

      hr = m_pd3dDevice->CreateShaderResourceView(texture->m_pTexture,
                                                  &srvDesc,
                                                  &texture->m_pSRV);
      if (FAILED(hr)) {
        std::cout << "//Error fallo la creacion del shader resource" << std::endl;
        return nullptr;
      }

    }
    if (bindFlags & D3D11_BIND_DEPTH_STENCIL) {//Crear DSV


      CD3D11_DEPTH_STENCIL_VIEW_DESC dsvDesc(D3D11_DSV_DIMENSION_TEXTURE2D,
                                             static_cast<DXGI_FORMAT>(format));

      hr = m_pd3dDevice->CreateDepthStencilView(texture->m_pTexture,
                                                &dsvDesc,
                                                &texture->m_pDSV);

      if (FAILED(hr)) {
        std::cout << "//Error fallo la creacion del depth stencil" << std::endl;
        return nullptr;
      }

    }
    if (bindFlags & D3D11_BIND_RENDER_TARGET) {//Crear RTV


      CD3D11_RENDER_TARGET_VIEW_DESC rtvDesc(D3D11_RTV_DIMENSION_TEXTURE2D,
                                             static_cast<DXGI_FORMAT>(format));

      hr = m_pd3dDevice->CreateRenderTargetView(texture->m_pTexture,
                                                &rtvDesc,
                                                &texture->m_pRTV);

      if (FAILED(hr)) {
        std::cout << "//Error fallo la creacion del render target" << std::endl;
        return nullptr;
      }

    }
    if (bindFlags & D3D11_BIND_UNORDERED_ACCESS) {//Crear UAV
      CD3D11_UNORDERED_ACCESS_VIEW_DESC uavDesc(D3D11_UAV_DIMENSION_TEXTURE2D);
      m_pd3dDevice->CreateUnorderedAccessView(texture->m_pTexture,
                                              &uavDesc,
                                              &texture->m_pUAV);

    }
    return texture;

  }

  void
  DXGraphiAPI::createTexture3D() {
  } 

  ShaderProgram* 
  DXGraphiAPI::createShaderProgram(const std::string& FileNameVS,
                                   const std::string& FileNamePS,
                                   const std::string& EntryVS,
                                   const std::string& EntryPS,
                                   const std::string& ShaderModelVS,
                                   const std::string& ShaderModelPS,
                                   int32 NumVertexShader,
                                   int32 NumPixelShader) {

    auto ShaderProgram = new ShaderProgramDX();

    //vertexShder
    std::string Temp = FileNameVS + "_DX.txt";
    ShaderProgram->m_vertexShaderProgram = new VertexShaderDX();
    std::wstring FileVS(Temp.length(), L' ');
    std::copy(Temp.begin(), Temp.end(), FileVS.begin());

    if (!ShaderProgram->m_vertexShaderProgram->compileVertexShaderFromFile(FileVS,
        EntryVS,
        ShaderModelVS,
        &ShaderProgram->m_vertexShaderProgram->m_pVSBlob)) {
      std::cout << "//Error fallo la compilacion del shader" << std::endl;
      delete ShaderProgram;
      return nullptr;
    }

    HRESULT hr = m_pd3dDevice->CreateVertexShader(ShaderProgram->m_vertexShaderProgram
                                                  ->m_pVSBlob->GetBufferPointer(),
                                                  ShaderProgram->m_vertexShaderProgram
                                                  ->m_pVSBlob->GetBufferSize(),
                                                  nullptr,
                                                  &ShaderProgram->m_vertexShaderProgram->
                                                  m_vertexShader);
    if (FAILED(hr)) {
      delete ShaderProgram;
      std::cout << "//Error fallo la creacion del vertex shader" << std::endl;
      ///error
      return nullptr;
    }


    //pixel shader
    Temp = FileNamePS + "_DX.txt";
    ShaderProgram->m_pixelShaderProgram = new PixelShaderDX();

    std::wstring FilePS(Temp.length(), L' ');
    std::copy(Temp.begin(), Temp.end(), FilePS.begin());

    if (!ShaderProgram->m_pixelShaderProgram->
        compilePixelShaderFromFile(FilePS,
                                   EntryPS,
                                   ShaderModelPS,
                                   &ShaderProgram->m_pixelShaderProgram->m_pPSBlob)) {
      std::cout << " //error fallo la compilacion del shader" << std::endl;
      return nullptr;
    }

    hr = m_pd3dDevice->CreatePixelShader(ShaderProgram->m_pixelShaderProgram->
                                         m_pPSBlob->GetBufferPointer(),
                                         ShaderProgram->m_pixelShaderProgram->
                                         m_pPSBlob->GetBufferSize(),
                                         nullptr,
                                         &ShaderProgram->m_pixelShaderProgram->
                                         m_pixelShader);

    if (FAILED(hr)) {
      delete ShaderProgram;
      std::cout << "//error fallo la creacion del Pixel shader" << std::endl;
      return nullptr;
    }

    return ShaderProgram;
  }

  //fuction to create a pixel shader
  PixelShader* DXGraphiAPI::createPixelShaders(const std::string& FileName,
                                               const std::string& Entry,
                                               const std::string& ShaderModel,
                                               int32 NumPixelShader) {
    std::string Temp = FileName + "_DX.txt";
    auto PixelShader = new PixelShaderDX();

    std::wstring File(Temp.length(), L' ');
    std::copy(Temp.begin(), Temp.end(), File.begin());

    if (!PixelShader->compilePixelShaderFromFile(File,
                                                 Entry,
                                                 ShaderModel,
                                                 &PixelShader->m_pPSBlob)) {
      std::cout << " //error fallo la compilacion del shader" << std::endl;
      return nullptr;
    }

    HRESULT hr = m_pd3dDevice->CreatePixelShader(PixelShader->m_pPSBlob->
                                                 GetBufferPointer(),
                                                 PixelShader->m_pPSBlob->
                                                 GetBufferSize(),
                                                 nullptr,
                                                 &PixelShader->m_pixelShader);

    if (FAILED(hr)) {
      PixelShader->m_pPSBlob->Release();
      std::cout << "//error fallo la creacion del Pixel shader" << std::endl;
      return nullptr;
    }

    return PixelShader;
  }

  //fuction to create a vertex shader
  VertexShader* DXGraphiAPI::createVertexShaders(const std::string& FileName,
                                                 const std::string& Entry,
                                                 const std::string& ShaderModel,
                                                 int32 NumVextexShader) {
    std::string Temp = FileName + "_DX.txt";
    auto VertexShaders = new VertexShaderDX();
    std::wstring File(Temp.length(), L' ');
    std::copy(Temp.begin(), Temp.end(), File.begin());

    if (!VertexShaders->compileVertexShaderFromFile(File,
                                                    Entry,
                                                    ShaderModel,
                                                    &VertexShaders->m_pVSBlob)) {
      std::cout << "//Error fallo la compilacion del shader" << std::endl;
      return nullptr;
    }

    HRESULT hr = m_pd3dDevice->CreateVertexShader(VertexShaders->m_pVSBlob->
                                                  GetBufferPointer(),
                                                  VertexShaders->m_pVSBlob->
                                                  GetBufferSize(),
                                                  nullptr,
                                                  &VertexShaders->m_vertexShader);
    if (FAILED(hr)) {
      VertexShaders->m_pVSBlob->Release();
      std::cout << "//Error fallo la creacion del vertex shader" << std::endl;
      ///error
      return nullptr;
    }
    return VertexShaders;
  }

  //fuction to create an input layout,
  InputLayout* DXGraphiAPI::createInputLayout(ShaderProgram& Vertex,
                                               InputLayout_Desc& LayoutDesc,
                                               unsigned int NumInputLayout) {
    auto InputLayout = new InputLayoutDX();
    auto& VertexShaderBlob = reinterpret_cast<ShaderProgramDX&>(Vertex);


    vector<D3D11_INPUT_ELEMENT_DESC> layout;

    unsigned int SemanticIndexPosition = 0;
    unsigned int SemanticIndexTexcoord = 0;
    unsigned int SemanticIndexColor = 0;
    unsigned int SemanticIndexNormal = 0;


    for (int i = 0; i < LayoutDesc.Semantics.size(); ++i) {
      LPCSTR Temp = LayoutDesc.Semantics.at(i).c_str();
      if ("POSITION" == LayoutDesc.Semantics.at(i)) {
        layout.push_back({ "POSITION",
                           SemanticIndexPosition,
                           DXGI_FORMAT_R32G32B32_FLOAT,
                           0,
                           D3D11_APPEND_ALIGNED_ELEMENT,
                           D3D11_INPUT_PER_VERTEX_DATA,
                           0 });
        SemanticIndexPosition++;
      }
      else if ("TEXCOORD" == LayoutDesc.Semantics.at(i)) {
        layout.push_back({ "TEXCOORD",
                           SemanticIndexTexcoord,
                           DXGI_FORMAT_R32G32_FLOAT,
                           0,
                           D3D11_APPEND_ALIGNED_ELEMENT,
                           D3D11_INPUT_PER_VERTEX_DATA,
                           0 });
        SemanticIndexTexcoord++;
      }
      else if ("COLOR" == LayoutDesc.Semantics.at(i)) {
        layout.push_back({ "COLOR",
                           SemanticIndexColor,
                           DXGI_FORMAT_R32G32B32_FLOAT,
                           0,
                           D3D11_APPEND_ALIGNED_ELEMENT,
                           D3D11_INPUT_PER_VERTEX_DATA,
                           0 });
        SemanticIndexColor++;
      }
      else if ("NORMAL" == LayoutDesc.Semantics.at(i)) {
        layout.push_back({ "NORMAL",
                           SemanticIndexNormal,
                           DXGI_FORMAT_R32G32B32_FLOAT,
                           0,
                           D3D11_APPEND_ALIGNED_ELEMENT,
                           D3D11_INPUT_PER_VERTEX_DATA,
                           0 });
        SemanticIndexNormal++;
      }
    }

    HRESULT  hr = m_pd3dDevice->CreateInputLayout(layout.data(),
                                                  layout.size(),
                                                  VertexShaderBlob.m_vertexShaderProgram
                                                  ->m_pVSBlob->GetBufferPointer(),
                                                  VertexShaderBlob.m_vertexShaderProgram
                                                  ->m_pVSBlob->GetBufferSize(),
                                                  &InputLayout->m_pInputLayout);

    VertexShaderBlob.m_vertexShaderProgram->m_pVSBlob->Release();

    if (FAILED(hr))
    {
      std::cout << "//error fallo la creacion del Input layout" << std::endl;
      return nullptr;
    }

    return InputLayout;


  }

  //fuction to create a sampler state

  //faltan parametros
  SamplerState* 
  DXGraphiAPI::createSamplerState(unsigned int NumSamplerState) {
    auto SamplerState = new SamplerStateDX();

    CD3D11_SAMPLER_DESC SamStDesc;

    m_pd3dDevice->CreateSamplerState(&SamStDesc,
                                     &SamplerState->m_pSamplerLinear);

    return SamplerState;
  }

  //fuction to create a rasterizer state

  //faltan parametros
  RasterizerState* DXGraphiAPI::createRasterizerState() {
    auto RasState = new RasterizerStateDX();

    CD3D11_RASTERIZER_DESC RasDesc;

    m_pd3dDevice->CreateRasterizerState(&RasDesc,
                                        &RasState->m_pRasterizerState);
    return RasState;
  }

  //fuction to set a constant buffer of vertex shader
  void 
  DXGraphiAPI::setVertexShaderConstantBuffer(ConstantBuffer* ConstBuff,
    unsigned int StartSlot,
    unsigned int NumBuffer) {
    auto* Buffer = reinterpret_cast<ConstantBufferDX*>(ConstBuff);
    m_pImmediateContext->VSSetConstantBuffers(StartSlot,
                                              NumBuffer,
                                              &Buffer->m_pConstantBuffer);
  }

  //fuction to set a constant buffer of pixel shader
  void 
  DXGraphiAPI::setPixelShaderConstantBuffer(ConstantBuffer* ConstBuff,
                                            unsigned int StartSlot,
                                            unsigned int NumBuffer) {
    auto* Buffer = reinterpret_cast<ConstantBufferDX*>(ConstBuff);

    m_pImmediateContext->PSSetConstantBuffers(StartSlot,
                                              NumBuffer,
                                              &Buffer->m_pConstantBuffer);
  }



  //fuction to set an index buffer 
  void DXGraphiAPI::setIndexBuffer(IndexBuffer* IndBuff,
                                   unsigned int offset) {
    auto* IndexBuff = reinterpret_cast<IndexBufferDX*>(IndBuff);
    IndexBuff->m_offset = offset;

    m_pImmediateContext->IASetIndexBuffer(IndexBuff->m_pIndexBuffer,
                                          DXGI_FORMAT_R32_UINT,
                                          IndexBuff->m_offset);
  }

  //fuction to set a vertex buffer 
  void 
  DXGraphiAPI::setVertexBuffer(VertexBuffer* VerBuff,
                               unsigned int StartSlot,
                               unsigned int NumBuffer,
                               unsigned int stride,
                               unsigned int offset) {

    auto* VertexBuff = reinterpret_cast<VertexBufferDX*>(VerBuff);

    VertexBuff->m_stride = stride;
    VertexBuff->m_offset = offset;
    m_pImmediateContext->IASetVertexBuffers(StartSlot,
                                            NumBuffer,
                                            &VertexBuff->m_pVertexBuffer,
                                            &VertexBuff->m_stride,
                                            &VertexBuff->m_offset);
  }

  void 
  DXGraphiAPI::setShaderProgram(ShaderProgram* ShaderProgram) {

    auto* ShaderPr = reinterpret_cast<ShaderProgramDX*>(ShaderProgram);
    m_pImmediateContext->PSSetShader(ShaderPr->m_pixelShaderProgram->
                                     m_pixelShader,
                                     nullptr,
                                     0);

    m_pImmediateContext->VSSetShader(ShaderPr->m_vertexShaderProgram->
                                     m_vertexShader,
                                     nullptr,
                                     0);
  }

  //fuction to set a pixel shader 
  void
  DXGraphiAPI::setPixelShaders(PixelShader* Pixel) {
    auto* PixelSh = reinterpret_cast<PixelShaderDX*>(Pixel);

    m_pImmediateContext->PSSetShader(PixelSh->m_pixelShader,
                                     nullptr,
                                     0);
  }

  //fuction to set a vertex shader 
  void 
  DXGraphiAPI::setVertexShaders(VertexShader* Vertex) {
    auto* VertexSh = reinterpret_cast<VertexShaderDX*>(Vertex);
    m_pImmediateContext->VSSetShader(VertexSh->m_vertexShader,
                                     nullptr,
                                     0);
  }

  //fuction to set a render target 
  void 
  DXGraphiAPI::setRenderTarget(const std::vector<TextureB*>& pRTTex,
                               TextureB* pDSTex) {
    for (int i = 0; i < pRTTex.size(); ++i) {
      auto pRTDX = reinterpret_cast<TextureDX*>(pRTTex.at(i));

      ID3D11DepthStencilView* pDSV = nullptr;

      if (nullptr != pDSTex) {
        auto pDSDX = reinterpret_cast<TextureDX*>(pDSTex);
        pDSV = pDSDX->m_pDSV;
      }

      m_pImmediateContext->OMSetRenderTargets(pRTTex.size(),
                                              &pRTDX->m_pRTV,
                                              pDSV);

    }
  }


  //fuction to set a input layout 
  void 
  DXGraphiAPI::setInputLayout(InputLayout* Inp) {
    auto* InpLay = reinterpret_cast<InputLayoutDX*>(Inp);
    m_pImmediateContext->IASetInputLayout(InpLay->m_pInputLayout);
  }

  //fuction to set a sampler state 
  void 
  DXGraphiAPI::setSamplerState(const std::vector<SamplerState*>& Sam,
                               unsigned int StartSlot) {
    for (int i = 0; i < Sam.size(); ++i) {
      auto Sampler = reinterpret_cast<SamplerStateDX*>(Sam.at(i));

      m_pImmediateContext->PSSetSamplers(i,
                                         Sam.size(),
                                         &Sampler->m_pSamplerLinear);
    }

  }

  void 
  DXGraphiAPI::setDepthStencil(TextureB* pDSTex){
  }

  //fuction to set a shader resource

  //se debe poder setar cualquier resource
  void 
  DXGraphiAPI::setShaderResource(const std::vector<TextureB*>& pRTTex,
                                 unsigned int StartSlot) {
    for (int i = 0; i < pRTTex.size(); ++i) {
      auto pRTDX = reinterpret_cast<TextureDX*>(pRTTex.at(i));

      m_pImmediateContext->PSSetShaderResources(i,
                                                pRTTex.size(),
                                                &pRTDX->m_pSRV);
    }

  }

  //fuction to set a viewport 
  void 
  DXGraphiAPI::setViewport(unsigned int NumViewport,
                           float Width,
                           float Height,
                           float TopLeftX,
                           float TopLeftY) {
    CD3D11_VIEWPORT Vp(TopLeftX,
                       TopLeftY,
                       Width,
                       Height);

    m_pImmediateContext->RSSetViewports(NumViewport, &Vp);
  }

  void 
  DXGraphiAPI::setPrimitiveTopology(PRIMITIVE_TOPOLOGY Topology) {
    m_pImmediateContext->
    IASetPrimitiveTopology(static_cast<D3D_PRIMITIVE_TOPOLOGY>(Topology));
  }

  void 
  DXGraphiAPI::setDefaultRenderTarget() {
    auto* pRTDX = reinterpret_cast<TextureDX*>(m_BackBuffer);
    auto* pDSDX = reinterpret_cast<TextureDX*>(m_DepthStencil);

    m_pImmediateContext->OMSetRenderTargets(1,
                                            &pRTDX->m_pRTV,
                                            pDSDX->m_pDSV);
  }

  //fuction to set a rasterizer state
  void 
  DXGraphiAPI::setRasterizerState(RasterizerState* RasState) {
    auto* pRasteState = reinterpret_cast<RasterizerStateDX*>(RasState);

    m_pImmediateContext->RSSetState(pRasteState->m_pRasterizerState);
  }

  //fuction to clear render target view
  void 
  DXGraphiAPI::clearRenderTarget(TextureB* RT,
                                 ColorStruct Color) {
    auto* pRTDX = reinterpret_cast<TextureDX*>(RT);

    m_pImmediateContext->ClearRenderTargetView(pRTDX->m_pRTV, &Color.R);
  }

  //fuction to clear depth stenci view
  void 
  DXGraphiAPI::clearDepthStencil(TextureB* DS,
                                 unsigned int ClerFlag,
                                 float Depth,
                                 unsigned int Stencil) {
    auto* pDSDX = reinterpret_cast<TextureDX*>(DS);



    m_pImmediateContext->ClearDepthStencilView(pDSDX->m_pDSV,
                                               static_cast<D3D11_CLEAR_FLAG>(ClerFlag),
                                               Depth,
                                               Stencil);
  }

  void 
  DXGraphiAPI::clearDefaultRenderTargetAndDepthStencil(ColorStruct Color) {

    auto pRTDX = reinterpret_cast<TextureDX*>(m_BackBuffer);
    auto pDSDX = reinterpret_cast<TextureDX*>(m_DepthStencil);

    m_pImmediateContext->ClearRenderTargetView(pRTDX->m_pRTV, &Color.R);

    m_pImmediateContext->ClearDepthStencilView(pDSDX->m_pDSV,
                                               D3D11_CLEAR_DEPTH,
                                               1.0f,
                                               0);
  }

  void 
  DXGraphiAPI::updateSubresource(const void* Data,
                                 ConstantBuffer& ConstantBufffer) {
    auto& ConstantBufferChangeEvery = 
    reinterpret_cast<ConstantBufferDX&>(ConstantBufffer);

    m_pImmediateContext->UpdateSubresource(ConstantBufferChangeEvery.m_pConstantBuffer,
                                           0,
                                           nullptr,
                                           Data,
                                           0,
                                           0);
  }


  void 
  DXGraphiAPI::drawModel(Model* Model, ShaderProgram& ShaderPro) {
  }

  //fuction to draw
  void 
  DXGraphiAPI::drawIndexed(unsigned int NumIndex,
                           unsigned int StartindexLocation,
                           unsigned int BaseVertexLocation,
                           const void* Index) {
    m_pImmediateContext->DrawIndexed(NumIndex,
                                     StartindexLocation,
                                     BaseVertexLocation);
  }

  void DXGraphiAPI::drawInstanced(unsigned int VertexCountPerInstance,
                                  unsigned int InstanceCount,
                                  unsigned int StartVertexLocation,
                                  unsigned int StartInstanceLocation) {

    m_pImmediateContext->DrawInstanced(VertexCountPerInstance,
                                       InstanceCount,
                                       StartVertexLocation,
                                       StartInstanceLocation);
  }

  void 
  DXGraphiAPI::draw(unsigned int VertexCount,
                    unsigned int StartVertexLocation) {
    m_pImmediateContext->Draw(VertexCount,
                              StartVertexLocation);
  }

  //fuction to present the swap chain
  void 
  DXGraphiAPI::present() {
    m_pSwapChain->Present(0, 0);
  }

  void 
  DXGraphiAPI::destroy() {
    //Device Context
    if (m_pImmediateContext) {
      m_pImmediateContext->ClearState();
    }

    //depthstencil
    auto DepthStencil = reinterpret_cast<TextureDX*>(m_DepthStencil);
    if (nullptr != DepthStencil) {
      DepthStencil->m_pTexture->Release();
    }

    auto BackBuffer = reinterpret_cast<TextureDX*>(m_BackBuffer);
    if (nullptr != BackBuffer) {
      BackBuffer->m_pRTV->Release();
    }


    if (m_pSwapChain) {
      m_pSwapChain->Release();
    }

    if (m_pImmediateContext) {
      m_pImmediateContext->Release();
    }

    if (m_pd3dDevice) {
      m_pd3dDevice->Release();
    }
  }
}