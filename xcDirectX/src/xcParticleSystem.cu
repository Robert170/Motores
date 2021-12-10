#include "cuda.h"
#include "cuda_runtime.h"
#include "device_functions.h"
#include "device_launch_parameters.h"

#include "xcParticleSystem.cuh"

namespace xcEngineSDK {

  __global__ void
    checkParticle(bool* isLiving, float* lifeTime) {
    unsigned int i = blockDim.x * blockIdx.x + threadIdx.x;
    isLiving[i] = lifeTime[i] > 0;
  }

  void
    ParticleSystem::init() {
    unsigned int threadsPerBlock = 1024;
    unsigned int blocksPerGrid = (m_maxNumberOfParticle + threadsPerBlock - 1)
      / threadsPerBlock;
  }

  void
    ParticleSystem::update(const float& deltaTime) {
  }

  void
    ParticleSystem::destroy() {
  }
}