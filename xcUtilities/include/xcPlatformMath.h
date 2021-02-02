#pragma once
#include <cmath>

#include "xcPlatformTypes.h"

using xcEngineSDK::int32;

struct PlatformMath {

  //square root and float square root 
  template<typename Type>
  Type
  opSqr(Type val) {
    return std::sqrt(val);
  }

  template<>
  float
  opSqr(float val) {
    return std::sqrtf(val);
  }

  //pow root and float pow 
  template<typename Type>
  Type
  opPow(Type val, int32 ex) {
    return std::pow(val, ex);
  }

  template<>
  float
  opPow(float val, int32 ex) {
    return std::powf(val, ex);
  }

  //sin and float sin 
  template<typename Type>
  Type
  opSin(Type val) {
    return std::sin(val);
  }

  template<>
  float
  opSin(float val) {
    return std::sinf(val);
  }

  //sinh and float sinh 
  template<typename Type>
  Type
  opSinh(Type val) {
    return std::sinh(val);
  }

  template<>
  float
  opSinh(float val) {
    return std::sinhf(val);
  }

  //cos and float cos
  template<typename Type>
  Type
  opCos(Type val) {
    return std::cos(val);
  }

  template<>
  float
  opCos(float val) {
    return std::cosh(val);
  }


  //cos and float cosh
  template<typename Type>
  Type
  opCosh(Type val) {
    return std::cosh(val);
  }

  template<>
  float
  opCosh(float val) {
    return std::coshf(val);
  }

  //tan and float tan
  template<typename Type>
  Type
  opTan(Type val) {
    return std::tan(val);
  }

  template<>
  float
  opTan(float val) {
    return std::tanf(val);
  }

  //tanh and float tanh
  template<typename Type>
  Type
  opTanh(Type val) {
    return std::tanh(val);
  }

  template<>
  float
  opTanh(float val) {
    return std::tanhf(val);
  }


  //log and float log
  template<typename Type>
  Type
  opLog(Type val) {
    return std::log(val);
  }

  template<>
  float
  opTanh(float val) {
    return std::logf(val);
  }

};