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
    return false;
  }
}