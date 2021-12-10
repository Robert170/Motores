#pragma once

#include "xcPrerequisitesDX.h"
#include "xcParticle.h"

namespace xcEngineSDK {

  namespace EMISSION_SHAPE {
    enum E {

    };
  }

  class ParticleSystem
  {
   public:
    ParticleSystem() = default;
    ~ParticleSystem() = default;

    void
    init();

    void
    update(const float& deltaTime);

    void
    destroy();

   private:
     bool m_isLooping = false;
     float particleSyatemTime = 0.0f;
     int32 m_particlePerSecond;
     int32 m_maxNumberOfParticle;

     Vector2 m_rangeOfLifeTime;
     Vector3 m_position;
     Particle m_particles;

  };

}
