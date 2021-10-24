#include "xcComputShaderDX.h"

namespace xcEngineSDK {

  ComputeShaderDX::~ComputeShaderDX() {
   
    if (m_computeShader) {
      m_computeShader->Release();
    }
    if (m_pCSBlob) {
      m_pCSBlob->Release();
    }
    
  }

  bool 
  ComputeShaderDX::compileComputeShaderFromFile(const WString& FileName,
                                               const String& EntryPoint, 
                                               const String& ShaderModel, 
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
        std::cout << "Error al compilar el compute shader" << std::endl;
        OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
        std::cout << (char*)pErrorBlob->GetBufferPointer() << std::endl;
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