#include <xcMatrix4x4.h>
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


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
    m_BackBuffer = nullptr;
    m_DepthStencil = nullptr;
  }

  DXGraphiAPI::~DXGraphiAPI() {
  }

  Matrix4x4 
  DXGraphiAPI::initMatrixWorld(Matrix4x4& MatrixWorld) {

    MatrixWorld = Matrix4x4::IDENTITY_MATRIX;

    return MatrixWorld.transpose();
  }

  Matrix4x4 
  DXGraphiAPI::initMatrixView(Matrix4x4& MatrixView,
                              Vector3& Eye,
                              Vector3& At,
                              Vector3& Up) {
    ////init view matrix TODO:
    MatrixView = MatrixView.lookAtLH(Eye,
                                     At,
                                     Up);
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
    MatrixProjection = MatrixProjection.perspectiveFovLH(Fov,
                                                         Height,
                                                         Width,
                                                         Near,
                                                         Far);
    return MatrixProjection.transpose();

  }

  

  //function to create a window
  void 
  DXGraphiAPI::initWindow(uint32 width,
                          uint32 height) {

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
    RECT rc = { 0, 0, LONG(width), LONG(height) };
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


  //function to create device and swap chain
  void 
  DXGraphiAPI::createDeviceandSwap(sf::WindowHandle window) {
    RECT rc;
    GetClientRect(window, &rc);
    m_width = rc.right - rc.left;
    m_height = rc.bottom - rc.top;

    //D3D_DRIVER_TYPE driverType = D3D_DRIVER_TYPE_NULL;
    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;

    UINT createDeviceFlags = 0;
#ifdef _DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    Vector<D3D_DRIVER_TYPE> driverTypes =
    {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE,
    };

    Vector<D3D_FEATURE_LEVEL> featureLevels =
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
    sd.OutputWindow = window;
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
      std::cout << "//error fail the creation of render target view" << std::endl;
      return;
    }

    m_BackBuffer.reset(BackBuffer);


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

    m_DepthStencil.reset(DepthStencil);

  }

  void 
  DXGraphiAPI::createDeferredContext() {
    m_pd3dDevice->CreateDeferredContext(0, &m_pImmediateContext);
  }


  //function to create a vertex buffer 
  SPtr<VertexBuffer> 
  DXGraphiAPI::createVertexBuffer(const Vector <BoneVertex>& Ver,
                                  uint32 NumBuffer) {

    XC_UNREFERENCED_PARAMETER(NumBuffer);

    SPtr<VertexBufferDX> vertexBuffer;
    vertexBuffer.reset(new VertexBufferDX());
    CD3D11_BUFFER_DESC BufferDesc(Ver.size() * sizeof(BoneVertex),
                                  D3D11_BIND_VERTEX_BUFFER);

    D3D11_SUBRESOURCE_DATA InitData;
    ZeroMemory(&InitData, sizeof(InitData));
    InitData.pSysMem = Ver.data();

    HRESULT hr = m_pd3dDevice->CreateBuffer(&BufferDesc,
                                            &InitData,
                                            &vertexBuffer->m_pVertexBuffer);
    if (FAILED(hr)) {
      std::cout << "//error fail the creation of vertex buffer" << std::endl;
      return nullptr;
    }
    return vertexBuffer; 

  }

  //function to create an index buffer 
  SPtr<IndexBuffer> 
  DXGraphiAPI::createIndexBuffer(const Vector<uint32>& Ind,
                                 uint32 NumBuffer) {


    XC_UNREFERENCED_PARAMETER(NumBuffer);
    SPtr<IndexBufferDX> indexBuffer;
    indexBuffer.reset(new IndexBufferDX());
    CD3D11_BUFFER_DESC BufferDesc(Ind.size() * sizeof(uint32),
                                  D3D11_BIND_INDEX_BUFFER);

    D3D11_SUBRESOURCE_DATA InitData;
    ZeroMemory(&InitData, sizeof(InitData));
    InitData.pSysMem = &Ind.at(0);

    HRESULT hr = m_pd3dDevice->CreateBuffer(&BufferDesc,
                                            &InitData,
                                            &indexBuffer->m_pIndexBuffer);

    if (FAILED(hr)) {
      std::cout << "//error fail the creation of Index buffer" << std::endl;
      return nullptr;
    }
    return indexBuffer;
  }

  //function to create a constant buffer 
  SPtr<ConstantBuffer> 
  DXGraphiAPI::createConstantBuffer(uint32 BufferSize,
                                    uint32 NumBuffer,
                                    const void* Data) {

    XC_UNREFERENCED_PARAMETER(NumBuffer);
    XC_UNREFERENCED_PARAMETER(Data);

    SPtr<ConstantBufferDX>consBuffer;
    consBuffer.reset(new ConstantBufferDX());

    CD3D11_BUFFER_DESC BufferDesc(BufferSize,
                                  D3D11_BIND_CONSTANT_BUFFER);

    HRESULT hr;
    if (nullptr !=  Data) {

      D3D11_SUBRESOURCE_DATA dataBuffer;
      ZeroMemory(&dataBuffer, sizeof(dataBuffer));
      dataBuffer.pSysMem = Data;

      hr = m_pd3dDevice->CreateBuffer(&BufferDesc,
                                      &dataBuffer,
                                      &consBuffer->m_pConstantBuffer);
    }
    else {
      hr = m_pd3dDevice->CreateBuffer(&BufferDesc,
                                      nullptr,
                                      &consBuffer->m_pConstantBuffer);

    }

    if (FAILED(hr)) {
      std::cout << "//Error fail the creation of Constant buffer" << std::endl;
      return nullptr;
    }
    return consBuffer;
  }

  void 
  DXGraphiAPI::createTexture1D() {
  }

  //function to create a texture 2D
  Texture*
  DXGraphiAPI::createTexture2D(uint32 width,
                               uint32 height,
                               uint32 numberTexture,
                               TEXTURE_FORMAT format,
                               uint32 bindFlags,
                               TYPE_USAGE Usage,
                               const void* Data) {
    HRESULT hr;
    TextureDX* texture = new TextureDX();

    CD3D11_TEXTURE2D_DESC desc(static_cast<DXGI_FORMAT>(format),
                               width,
                               height,
                               numberTexture,
                               1,
                               bindFlags,
                               static_cast<D3D11_USAGE>(Usage));

    D3D11_SUBRESOURCE_DATA ResourceDataDesc;
    ResourceDataDesc.pSysMem = Data;
    ResourceDataDesc.SysMemPitch = desc.Width * 4;
    ResourceDataDesc.SysMemSlicePitch = 0;

    //create texture
    hr = m_pd3dDevice->CreateTexture2D(&desc, 
                                       &ResourceDataDesc,
                                       &texture->m_pTexture);
    if (FAILED(hr)) {
      std::cout << "//Error fail the creation of la texture" << std::endl;
      //TODO
      //stbi_image_free(Data);
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

  SPtr<ShaderProgram> 
  DXGraphiAPI::createShaderProgram(const String& FileNameVS,
                                   const String& FileNamePS,
                                   const String& EntryVS,
                                   const String& EntryPS,
                                   const String& ShaderModelVS,
                                   const String& ShaderModelPS,
                                   int32 NumVertexShader,
                                   int32 NumPixelShader) {

    XC_UNREFERENCED_PARAMETER(NumVertexShader);
    XC_UNREFERENCED_PARAMETER(NumPixelShader);

    SPtr<ShaderProgramDX> shaderProgram;
    shaderProgram.reset(new ShaderProgramDX());

    //TODO EL VS y PS dben ser objetos
    //vertexShder
    String Temp = FileNameVS + "_DX.txt";
    shaderProgram->m_vertexShaderProgram = new VertexShaderDX();
    WString FileVS(Temp.length(), L' ');
    std::copy(Temp.begin(), Temp.end(), FileVS.begin());

    if (!shaderProgram->m_vertexShaderProgram->compileVertexShaderFromFile(FileVS,
        EntryVS,
        ShaderModelVS,
        &shaderProgram->m_vertexShaderProgram->m_pVSBlob)) {
      std::cout << "//Error fallo la compilacion del shader" << std::endl;
      //delete shaderProgram;
      return nullptr;
    }

    HRESULT hr = m_pd3dDevice->CreateVertexShader(shaderProgram->m_vertexShaderProgram
                                                  ->m_pVSBlob->GetBufferPointer(),
                                                  shaderProgram->m_vertexShaderProgram
                                                  ->m_pVSBlob->GetBufferSize(),
                                                  nullptr,
                                                  &shaderProgram->m_vertexShaderProgram->
                                                  m_vertexShader);
    if (FAILED(hr)) {
      //delete shaderProgram;
      std::cout << "//Error fallo la creacion del vertex shader" << std::endl;
      ///error
      return nullptr;
    }


    //pixel shader
    Temp = FileNamePS + "_DX.txt";
    shaderProgram->m_pixelShaderProgram = new PixelShaderDX();

    WString FilePS(Temp.length(), L' ');
    std::copy(Temp.begin(), Temp.end(), FilePS.begin());

    if (!shaderProgram->m_pixelShaderProgram->
        compilePixelShaderFromFile(FilePS,
                                   EntryPS,
                                   ShaderModelPS,
                                   &shaderProgram->m_pixelShaderProgram->m_pPSBlob)) {
      std::cout << " //error fallo la compilacion del shader" << std::endl;
      return nullptr;
    }

    hr = m_pd3dDevice->CreatePixelShader(shaderProgram->m_pixelShaderProgram->
                                         m_pPSBlob->GetBufferPointer(),
                                         shaderProgram->m_pixelShaderProgram->
                                         m_pPSBlob->GetBufferSize(),
                                         nullptr,
                                         &shaderProgram->m_pixelShaderProgram->
                                         m_pixelShader);

    if (FAILED(hr)) {
      //delete shaderProgram;
      std::cout << "//error fallo la creacion del Pixel shader" << std::endl;
      return nullptr;
    }

    return shaderProgram;
  }

  //function to create a pixel shader
  SPtr<PixelShader> 
  DXGraphiAPI::createPixelShaders(const String& FileName,
                                               const String& Entry,
                                               const String& ShaderModel,
                                               int32 NumPixelShader) {
    XC_UNREFERENCED_PARAMETER(NumPixelShader);

    String Temp = FileName + "_DX.txt";
    SPtr<PixelShaderDX> pixelShader;
    pixelShader.reset(new PixelShaderDX());

    WString File(Temp.length(), L' ');
    std::copy(Temp.begin(), Temp.end(), File.begin());

    if (!pixelShader->compilePixelShaderFromFile(File,
                                                 Entry,
                                                 ShaderModel,
                                                 &pixelShader->m_pPSBlob)) {
      std::cout << " //error fallo la compilacion del shader" << std::endl;
      return nullptr;
    }

    HRESULT hr = m_pd3dDevice->CreatePixelShader(pixelShader->m_pPSBlob->
                                                 GetBufferPointer(),
                                                 pixelShader->m_pPSBlob->
                                                 GetBufferSize(),
                                                 nullptr,
                                                 &pixelShader->m_pixelShader);

    if (FAILED(hr)) {
      pixelShader->m_pPSBlob->Release();
      std::cout << "//error fallo la creacion del Pixel shader" << std::endl;
      return nullptr;
    }

    return pixelShader;
  }

  //function to create a vertex shader
  SPtr<VertexShader> 
  DXGraphiAPI::createVertexShaders(const String& FileName,
                                   const String& Entry,
                                   const String& ShaderModel,
                                   int32 NumVextexShader) {

    XC_UNREFERENCED_PARAMETER(NumVextexShader);
    String Temp = FileName + "_DX.txt";
    SPtr<VertexShaderDX>vertexShaders;
    vertexShaders.reset(new VertexShaderDX());
    WString File(Temp.length(), L' ');
    std::copy(Temp.begin(), Temp.end(), File.begin());

    if (!vertexShaders->compileVertexShaderFromFile(File,
                                                    Entry,
                                                    ShaderModel,
                                                    &vertexShaders->m_pVSBlob)) {
      std::cout << "//Error fallo la compilacion del shader" << std::endl;
      return nullptr;
    }

    HRESULT hr = m_pd3dDevice->CreateVertexShader(vertexShaders->m_pVSBlob->
                                                  GetBufferPointer(),
                                                  vertexShaders->m_pVSBlob->
                                                  GetBufferSize(),
                                                  nullptr,
                                                  &vertexShaders->m_vertexShader);
    if (FAILED(hr)) {
      vertexShaders->m_pVSBlob->Release();
      std::cout << "//Error fallo la creacion del vertex shader" << std::endl;
      ///error
      return nullptr;
    }
    return vertexShaders;
  }

  InputLayout_Desc 
  DXGraphiAPI::CreateInputLayoutDesc(Vector<String> SemanticsVector, 
                                     Vector<uint32> FormatsVector) {

    InputLayout_Desc Temp;

    Temp.Semantics = SemanticsVector;
    Temp.Formats = FormatsVector;

    return Temp;
  }

  //function to create an input layout,
  SPtr<InputLayout> 
  DXGraphiAPI::createInputLayout(ShaderProgram& Vertex,
                                 InputLayout_Desc& LayoutDesc,
                                 uint32 NumInputLayout) {

    XC_UNREFERENCED_PARAMETER(NumInputLayout);
    SPtr<InputLayoutDX> inputLayout; 
    inputLayout.reset(new InputLayoutDX());
    auto& VertexShaderBlob = reinterpret_cast<ShaderProgramDX&>(Vertex);


    Vector<D3D11_INPUT_ELEMENT_DESC> layout;

    uint32 SemanticIndexPosition = 0;
    uint32 SemanticIndexTexcoord = 0;
    uint32 SemanticIndexColor = 0;
    uint32 SemanticIndexNormal = 0;
    uint32 SemanticID = 0;
    uint32 SemanticWeight = 0;


    for (uint32 i = 0; i < LayoutDesc.Semantics.size(); ++i) {
      //LPCSTR Temp = LayoutDesc.Semantics.at(i).c_str();
      if ("POSITION" == LayoutDesc.Semantics.at(i)) {
        layout.push_back({ "POSITION",
                           SemanticIndexPosition,
                           (DXGI_FORMAT)LayoutDesc.Formats[i],
                           0,
                           D3D11_APPEND_ALIGNED_ELEMENT,
                           D3D11_INPUT_PER_VERTEX_DATA,
                           0 });
        SemanticIndexPosition++;
      }
      else if ("TEXCOORD" == LayoutDesc.Semantics.at(i)) {
        layout.push_back({ "TEXCOORD",
                           SemanticIndexTexcoord,
                           (DXGI_FORMAT)LayoutDesc.Formats[i],
                           0,
                           D3D11_APPEND_ALIGNED_ELEMENT,
                           D3D11_INPUT_PER_VERTEX_DATA,
                           0 });
        SemanticIndexTexcoord++;
      }
      else if ("COLOR" == LayoutDesc.Semantics.at(i)) {
        layout.push_back({ "COLOR",
                           SemanticIndexColor,
                           (DXGI_FORMAT)LayoutDesc.Formats[i],
                           0,
                           D3D11_APPEND_ALIGNED_ELEMENT,
                           D3D11_INPUT_PER_VERTEX_DATA,
                           0 });
        SemanticIndexColor++;
      }
      else if ("NORMAL" == LayoutDesc.Semantics.at(i)) {
        layout.push_back({ "NORMAL",
                           SemanticIndexNormal,
                           (DXGI_FORMAT)LayoutDesc.Formats[i],
                           0,
                           D3D11_APPEND_ALIGNED_ELEMENT,
                           D3D11_INPUT_PER_VERTEX_DATA,
                           0 });
        SemanticIndexNormal++;
      }
      else if ("BLENDINDICES" == LayoutDesc.Semantics.at(i)) {
        layout.push_back({ "BLENDINDICES",
                           SemanticID,
                           (DXGI_FORMAT)LayoutDesc.Formats[i],
                           0,
                           D3D11_APPEND_ALIGNED_ELEMENT,
                           D3D11_INPUT_PER_VERTEX_DATA,
                           0 });
        SemanticID++;
      }
      else if ("BLENDWEIGHT" == LayoutDesc.Semantics.at(i)) {
        layout.push_back({ "BLENDWEIGHT",
                           SemanticWeight,
                           (DXGI_FORMAT)LayoutDesc.Formats[i],
                           0,
                           D3D11_APPEND_ALIGNED_ELEMENT,
                           D3D11_INPUT_PER_VERTEX_DATA,
                           0 });
        SemanticWeight++;
      }
    }

    HRESULT  hr = m_pd3dDevice->CreateInputLayout(layout.data(),
                                                  layout.size(),
                                                  VertexShaderBlob.m_vertexShaderProgram
                                                  ->m_pVSBlob->GetBufferPointer(),
                                                  VertexShaderBlob.m_vertexShaderProgram
                                                  ->m_pVSBlob->GetBufferSize(),
                                                  &inputLayout->m_pInputLayout);

    VertexShaderBlob.m_vertexShaderProgram->m_pVSBlob->Release();

    if (FAILED(hr)) {
      std::cout << "//error fallo la creacion del Input layout" << std::endl;
      return nullptr;
    }

    return inputLayout;


  }

  //function to create a sampler state

  SPtr<InputLayout> 
  DXGraphiAPI::createAutomaticInputLayout(ShaderProgram& VS) {
    // Reflect shader info
    ID3D11ShaderReflection* pVertexShaderReflection = nullptr;

    ShaderProgramDX& vsBlob = reinterpret_cast<ShaderProgramDX&>(VS);

    SPtr<InputLayoutDX> inputLayout;
    inputLayout.reset(new InputLayoutDX());


    if (FAILED(D3DReflect(vsBlob.m_vertexShaderProgram->m_pVSBlob->GetBufferPointer(),
        vsBlob.m_vertexShaderProgram->m_pVSBlob->GetBufferSize(),
        IID_ID3D11ShaderReflection, (void**) &pVertexShaderReflection)))  {

       
        return nullptr;
    }
 
    // Get shader info
    D3D11_SHADER_DESC shaderDesc;
    pVertexShaderReflection->GetDesc( &shaderDesc );
 
    // Read input layout description from shader info
    Vector<D3D11_INPUT_ELEMENT_DESC> inputLayoutDesc;

    for ( uint32 i=0; i< shaderDesc.InputParameters; i++ ) {

        D3D11_SIGNATURE_PARAMETER_DESC paramDesc;
        pVertexShaderReflection->GetInputParameterDesc(i, &paramDesc );
 
        // fill out input element desc
        D3D11_INPUT_ELEMENT_DESC elementDesc;
        elementDesc.SemanticName = paramDesc.SemanticName;
        elementDesc.SemanticIndex = paramDesc.SemanticIndex;
        elementDesc.InputSlot = 0;
        elementDesc.AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
        elementDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
        elementDesc.InstanceDataStepRate = 0;   
 
        // determine DXGI format
        if ( paramDesc.Mask == 1 ) {

          if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_UINT32) {

            elementDesc.Format = DXGI_FORMAT_R32_UINT;
          }

          else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_SINT32) { 

            elementDesc.Format = DXGI_FORMAT_R32_SINT; 

          }
          else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_FLOAT32) { 
            elementDesc.Format = DXGI_FORMAT_R32_FLOAT; 
          }
        }
        else if ( paramDesc.Mask <= 3 ) {

          if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_UINT32) { 
            elementDesc.Format = DXGI_FORMAT_R32G32_UINT; 
          }
          else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_SINT32) { 
            elementDesc.Format = DXGI_FORMAT_R32G32_SINT; 
          }
          else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_FLOAT32) { 
            elementDesc.Format = DXGI_FORMAT_R32G32_FLOAT; 
          }
        }
        else if ( paramDesc.Mask <= 7 ) {
          if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_UINT32) {
            elementDesc.Format = DXGI_FORMAT_R32G32B32_UINT;
          }
          else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_SINT32) {
            elementDesc.Format = DXGI_FORMAT_R32G32B32_SINT;
          }
          else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_FLOAT32) {
            elementDesc.Format = DXGI_FORMAT_R32G32B32_FLOAT;
          }
        }
        else if ( paramDesc.Mask <= 15 ) {
          if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_UINT32) {
            elementDesc.Format = DXGI_FORMAT_R32G32B32A32_UINT;
          }
          else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_SINT32) {
            elementDesc.Format = DXGI_FORMAT_R32G32B32A32_SINT;
          }
          else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_FLOAT32) {
            elementDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
          }
        }
 
        //save element desc
        inputLayoutDesc.push_back(elementDesc);
    }       
 
    // Try to create Input Layout
    HRESULT hr = m_pd3dDevice->CreateInputLayout(&inputLayoutDesc[0], 
                                                 inputLayoutDesc.size(), 
                                                 vsBlob.m_vertexShaderProgram->
                                                 m_pVSBlob->GetBufferPointer(), 
                                                 vsBlob.m_vertexShaderProgram->
                                                 m_pVSBlob->GetBufferSize(), 
                                                 &inputLayout->m_pInputLayout);

    vsBlob.m_vertexShaderProgram->m_pVSBlob->Release();

    //Free allocation shader reflection memory
    pVertexShaderReflection->Release();

    if (FAILED(hr)) {
      std::cout << "//error fallo la creacion del Input layout" << std::endl;
      return nullptr;
    }
 

    return inputLayout;
  }

  //faltan parametros
  SPtr<SamplerState> 
  DXGraphiAPI::createSamplerState(uint32 NumSamplerState) {

    XC_UNREFERENCED_PARAMETER(NumSamplerState);
    SPtr<SamplerStateDX> samplerState; 
    samplerState.reset(new SamplerStateDX());

    
   
    D3D11_SAMPLER_DESC SamDesc;
    SamDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    SamDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
    SamDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
    SamDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
    SamDesc.MipLODBias = 0;
    SamDesc.MaxAnisotropy = 1;
    SamDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
    SamDesc.BorderColor[0] = 1.0f;
    SamDesc.BorderColor[1] = 1.0f;
    SamDesc.BorderColor[2] = 1.0f;
    SamDesc.BorderColor[3] = 1.0f;
    SamDesc.MinLOD = -3.402823466e+38F; // -FLT_MAX
    SamDesc.MaxLOD = 3.402823466e+38F; // FLT_MAX

    m_pd3dDevice->CreateSamplerState(&SamDesc,
                                     &samplerState->m_pSamplerLinear);

    return samplerState;
  }

  //function to create a rasterizer state

  //faltan parametros
  SPtr<RasterizerState>
  DXGraphiAPI::createRasterizerState() {
    SPtr<RasterizerStateDX> rasState;
    rasState.reset(new RasterizerStateDX());

    CD3D11_RASTERIZER_DESC RasDesc;

    m_pd3dDevice->CreateRasterizerState(&RasDesc,
                                        &rasState->m_pRasterizerState);
    return rasState;
  }


  //TODO multiples buffers, vector de constantbuffer, tantro para VS y PS
  //function to set a constant buffer of vertex shader
  void 
  DXGraphiAPI::setVSConstantBuffer(WeakSptr<ConstantBuffer> ConstBuff,
                                   uint32 StartSlot,
                                   uint32 NumBuffer) {

    ConstantBufferDX* buffer = 
    reinterpret_cast<ConstantBufferDX*>(ConstBuff.lock().get());
   
    m_pImmediateContext->VSSetConstantBuffers(StartSlot,
                                              NumBuffer,
                                              &buffer->m_pConstantBuffer);
  }

  //function to set a constant buffer of pixel shader
  void 
  DXGraphiAPI::setPSConstantBuffer(WeakSptr<ConstantBuffer> ConstBuff,
                                   uint32 StartSlot,
                                   uint32 NumBuffer) {

    ConstantBufferDX* buffer = 
    reinterpret_cast<ConstantBufferDX*>(ConstBuff.lock().get());

    m_pImmediateContext->PSSetConstantBuffers(StartSlot,
                                              NumBuffer,
                                              &buffer->m_pConstantBuffer);
  }



  //function to set an index buffer 
  void 
  DXGraphiAPI::setIndexBuffer(WeakSptr<IndexBuffer> IndBuff,
                              uint32 offset) {
    IndexBufferDX* indexBuff = 
    reinterpret_cast<IndexBufferDX*>(IndBuff.lock().get());

    indexBuff->m_offset = offset;

    m_pImmediateContext->IASetIndexBuffer(indexBuff->m_pIndexBuffer,
                                          DXGI_FORMAT_R32_UINT,
                                          indexBuff->m_offset);
  }

  //function to set a vertex buffer 
  void 
  DXGraphiAPI::setVertexBuffer(WeakSptr<VertexBuffer> verBuff,
                               uint32 StartSlot,
                               uint32 NumBuffer,
                               uint32 stride,
                               uint32 offset) {

    VertexBufferDX* vertexBuff = 
    reinterpret_cast<VertexBufferDX*>(verBuff.lock().get());

    vertexBuff->m_stride = stride;
    vertexBuff->m_offset = offset;
    m_pImmediateContext->IASetVertexBuffers(StartSlot,
                                            NumBuffer,
                                            &vertexBuff->m_pVertexBuffer,
                                            &vertexBuff->m_stride,
                                            &vertexBuff->m_offset);
  }

  void 
  DXGraphiAPI::setShaderProgram(WeakSptr<ShaderProgram> shaderProgram) {

    ShaderProgramDX* ShaderPr = 
    reinterpret_cast<ShaderProgramDX*>(shaderProgram.lock().get());

    m_pImmediateContext->PSSetShader(ShaderPr->m_pixelShaderProgram->
                                     m_pixelShader,
                                     nullptr,
                                     0);

    m_pImmediateContext->VSSetShader(ShaderPr->m_vertexShaderProgram->
                                     m_vertexShader,
                                     nullptr,
                                     0);
  }

  //function to set a pixel shader 
  void
  DXGraphiAPI::setPS(WeakSptr<PixelShader> pixel) {

    PixelShaderDX* PixelSh = 
    reinterpret_cast<PixelShaderDX*>(pixel.lock().get());

    m_pImmediateContext->PSSetShader(PixelSh->m_pixelShader,
                                     nullptr,
                                     0);
  }

  //function to set a vertex shader 
  void 
  DXGraphiAPI::setVS(WeakSptr<VertexShader> vertex) {
    VertexShaderDX* VertexSh = 
    reinterpret_cast<VertexShaderDX*>(vertex.lock().get());
    m_pImmediateContext->VSSetShader(VertexSh->m_vertexShader,
                                     nullptr,
                                     0);
  }

  //function to set a render target 
  void 
  DXGraphiAPI::setRenderTarget(const Vector<Texture*>& pRTTex,
                               WeakSptr<Texture> pDSTex) {

    for (uint32 i = 0; i < pRTTex.size(); ++i) {

      TextureDX* pRTDX = 
      reinterpret_cast<TextureDX*>(pRTTex.at(i));

      ID3D11DepthStencilView* pDSV = nullptr;

      if (nullptr != pDSTex.lock()) {
        TextureDX* pDSDX = reinterpret_cast<TextureDX*>(pDSTex.lock().get());
        pDSV = pDSDX->m_pDSV;
      }

      m_pImmediateContext->OMSetRenderTargets(pRTTex.size(),
                                              &pRTDX->m_pRTV,
                                              pDSV);

    }
  }


  //function to set a input layout 
  void 
  DXGraphiAPI::setInputLayout(WeakSptr<InputLayout> inp) {
    InputLayoutDX* InpLay = 
    reinterpret_cast<InputLayoutDX*>(inp.lock().get());

    m_pImmediateContext->IASetInputLayout(InpLay->m_pInputLayout);
  }

  //function to set a sampler state 
  void 
  DXGraphiAPI::setSamplerState(const Vector<SamplerState*>& Sam,
                               uint32 StartSlot) {
    for (uint32 i = 0; i < Sam.size(); ++i) {

      SamplerStateDX* Sampler = 
      reinterpret_cast<SamplerStateDX*>(Sam.at(i));

      m_pImmediateContext->PSSetSamplers(i,
                                         Sam.size(),
                                         &Sampler->m_pSamplerLinear);
    }
    XC_UNREFERENCED_PARAMETER(StartSlot);

  }

  void 
  DXGraphiAPI::setDepthStencil(WeakSptr<Texture> pDSTex){
    XC_UNREFERENCED_PARAMETER(pDSTex);
  }

  //function to set a shader resource

  //se debe poder setar cualquier resource
  void 
  DXGraphiAPI::setShaderResource(const Vector<Texture*>& pRTTex,
                                 uint32 StartSlot) {

    for (uint32 i = 0; i < pRTTex.size(); ++i) {

      TextureDX* pRTDX = reinterpret_cast<TextureDX*>(pRTTex[i]);

      m_pImmediateContext->PSSetShaderResources(i,
                                                pRTTex.size(),
                                                &pRTDX->m_pSRV);
    }
    XC_UNREFERENCED_PARAMETER(StartSlot);
  }


  //TODO Prfundidad minima y maxima, cambiar el orden de los parametros
  // Poder crerar más de un viewport
  //function to set a viewport 
  void 
  DXGraphiAPI::setViewport(uint32 NumViewport,
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
    TextureDX* pRTDX = reinterpret_cast<TextureDX*>(m_BackBuffer.get());
    TextureDX* pDSDX = reinterpret_cast<TextureDX*>(m_DepthStencil.get());

    m_pImmediateContext->OMSetRenderTargets(1,
                                            &pRTDX->m_pRTV,
                                            pDSDX->m_pDSV);
  }

  Matrix4x4 
  DXGraphiAPI::matri4x4Context(const Matrix4x4& matrix) {

    Matrix4x4 temp = matrix;
    return temp.transpose();
  }

  //function to set a rasterizer state
  void 
  DXGraphiAPI::setRasterizerState(WeakSptr<RasterizerState> RasState) {

    RasterizerStateDX* pRasteState = 
    reinterpret_cast<RasterizerStateDX*>(RasState.lock().get());

    m_pImmediateContext->RSSetState(pRasteState->m_pRasterizerState);
  }

  //function to clear render target view
  void 
  DXGraphiAPI::clearRenderTarget(WeakSptr<Texture> RT,
                                 ColorStruct Color) {
    TextureDX* pRTDX = reinterpret_cast<TextureDX*>(RT.lock().get());

    m_pImmediateContext->ClearRenderTargetView(pRTDX->m_pRTV, &Color.R);
  }

  //function to clear depth stenci view
  void 
  DXGraphiAPI::clearDepthStencil(WeakSptr<Texture> DS,
                                 uint32 ClerFlag,
                                 float Depth,
                                 uint32 Stencil) {

    TextureDX* pDSDX = reinterpret_cast<TextureDX*>(DS.lock().get());



    m_pImmediateContext->ClearDepthStencilView(pDSDX->m_pDSV,
                                               static_cast<D3D11_CLEAR_FLAG>(ClerFlag),
                                               Depth,
                                               UINT8(Stencil));
  }

  void 
  DXGraphiAPI::clearDefaultRenderTargetAndDepthStencil(ColorStruct Color) {

    TextureDX* pRTDX = reinterpret_cast<TextureDX*>(m_BackBuffer.get());
    TextureDX* pDSDX = reinterpret_cast<TextureDX*>(m_DepthStencil.get());

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

  Texture* 
  DXGraphiAPI::textureFromFile(String path,
                               const String& directory,
                               bool gamma) {

    Texture* texture = new Texture();


    int width, height, nrComponents;
   
    unsigned char* data = stbi_load(path.c_str(),
                                    &width, 
                                    &height, 
                                    &nrComponents, 
                                    4);
    if (data) {
  
      //create texture
      texture = createTexture2D(width,
                                height,
                                1,
                                TF_R8G8B8A8_UNORM,
                                TEXTURE_BIND_SHADER_RESOURCE,
                                TYPE_USAGE_DEFAULT,
                                data);
      //m_texturesloaded.push_back(m_texture);



      stbi_image_free(data);
    }
    else {
      std::cout << "Texture failed to load at path: " << path << std::endl;
      stbi_image_free(data);
    }

    return texture;
  }

  //function to draw
  void 
  DXGraphiAPI::drawIndexed(uint32 NumIndex,
                           uint32 StartindexLocation,
                           uint32 BaseVertexLocation,
                           const void* Index) {
    XC_UNREFERENCED_PARAMETER(Index);
    m_pImmediateContext->DrawIndexed(NumIndex,
                                     StartindexLocation,
                                     BaseVertexLocation);
  }

  void DXGraphiAPI::drawInstanced(uint32 VertexCountPerInstance,
                                  uint32 InstanceCount,
                                  uint32 StartVertexLocation,
                                  uint32 StartInstanceLocation) {

    m_pImmediateContext->DrawInstanced(VertexCountPerInstance,
                                       InstanceCount,
                                       StartVertexLocation,
                                       StartInstanceLocation);
  }

  void 
  DXGraphiAPI::draw(uint32 VertexCount,
                    uint32 StartVertexLocation) {
    m_pImmediateContext->Draw(VertexCount,
                              StartVertexLocation);
  }

  //function to present the swap chain
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
    TextureDX* DepthStencil = reinterpret_cast<TextureDX*>(m_DepthStencil.get());
    if (nullptr != DepthStencil) {
      DepthStencil->m_pTexture->Release();
    }

    TextureDX* BackBuffer = reinterpret_cast<TextureDX*>(m_BackBuffer.get());
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