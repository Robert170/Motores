#include "xcPlatformMath.h"

namespace xcEngineSDK {

  const float PlatformMath::PI = static_cast<float>(4.0f * std::atan(1.0f));

  const float PlatformMath::EULER_NUMBER = 2.718;
  const float PlatformMath::SMALL_NUMBER = 1.e-6f;
  const float PlatformMath::KINDA_SMALL_NUMBER = 1.e-4f;
  const float PlatformMath::BIG_NUMBER = 3.4e+38f;
  const float PlatformMath::DELTA = 1.e-5f;
  const float PlatformMath::DEG2RAD = PI / 180.0f;
  const float PlatformMath::RAD2DEG = 180.0f / PI;
}