#include "xcVertexShaderDX.h"
namespace xcEngineSDK {
  VertexShaderDX::~VertexShaderDX()
  {
    if (m_vertexShader)
    {
      m_vertexShader->Release();
    }
    if (m_pVSBlob)
    {
      m_pVSBlob->Release();
    }
  }

  bool 
  VertexShaderDX::compileVertexShaderFromFile(const WString& FileName,
                                              const String& EntryPoint,
                                              const String& ShaderModel,
                                              ID3DBlob** ppBlobOut) {
    HRESULT hr = S_OK;

    DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;


    ID3DBlob* pErrorBlob = nullptr;
    hr = D3DCompileFromFile(FileName.c_str(),
                            nullptr,
                            nullptr,
                            EntryPoint.c_str(),
                            ShaderModel.c_str(),
                            dwShaderFlags,
                            0,
                            ppBlobOut,
                            &pErrorBlob);

    if (FAILED(hr)) {
      if (pErrorBlob) {
        std::cout << "Error al compilar el vertex shader" << std::endl;
        // OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
      }

      if (pErrorBlob) {
        pErrorBlob->Release();
      }

      return false;

    }


    if (pErrorBlob) {
      pErrorBlob->Release();
    }

    return true;

  }
}