#include "CPixelShaderDX.h"
namespace xcEngineSDK {

  CPixelShaderDX::~CPixelShaderDX() {

    if (m_pixelShader) {
      m_pixelShader->Release();
    }
    if (m_pPSBlob) {
      m_pPSBlob->Release();
    }
  }

  bool CPixelShaderDX::compilePixelShaderFromFile(const std::wstring& FileName,
                                                  const std::string& EntryPoint,
                                                  const std::string& ShaderModel,
                                                  ID3DBlob** ppBlobOut) {
    HRESULT hr = S_OK;

    DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;


    ID3DBlob* pErrorBlob;
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

      if (pErrorBlob != nullptr) {
        OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
      }

      if (pErrorBlob) {
        pErrorBlob->Release();
        //error
        return false;
      }
    }

    if (pErrorBlob) {
      pErrorBlob->Release();
    }

    return true;
  }
}
