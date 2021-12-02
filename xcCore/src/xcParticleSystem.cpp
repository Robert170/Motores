
#include "xcParticleSystem.h"

namespace xcEngineSDK {

  __global__ void
    checkParticle(bool* isLiving, float* lifeTime) {
    uint32 i = blockDim.x * blockIdx.x + threadIdx.x;
    isLiving[i] = lifeTime[i] > 0;
  }

  void 
  ParticleSystem::init() {
    uint32 threadsPerBlock = 1024;
    uint32 blocksPerGrid = (m_maxNumberOfParticle + threadsPerBlock - 1) 
                           / threadsPerBlock;
  }

  void 
  ParticleSystem::update(const float& deltaTime) {
  }

  void 
  ParticleSystem::destroy() {
  }
}