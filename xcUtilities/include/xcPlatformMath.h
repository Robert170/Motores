#pragma once
#include <cmath>


#include "xcPrerequisitesUtilities.h"

using xcEngineSDK::int32;

struct PlatformMath {

  //square root and float square root 
  template<typename Type>
  static Type
  sqrt(Type val) {
    return std::sqrt(val);
  }

  template<>
  static float
  sqrt(float val) {
    return std::sqrtf(val);
  }

  //pow root and float pow 
  template<typename Type>
  static Type
  pow(Type val, int32 ex) {
    return std::pow(val, ex);
  }

  template<>
  static float
  pow(float val, int32 ex) {
    return std::powf(val, ex);
  }

  //sin and float sin 
  template<typename Type>
  static Type
  sin(Type val) {
    return std::sin(val);
  }

  template<>
  static float
  sin(float val) {
    return std::sinf(val);
  }

  //sinh and float sinh 
  template<typename Type>
  static Type
  sinh(Type val) {
    return std::sinh(val);
  }

  template<>
  static float
  sinh(float val) {
    return std::sinhf(val);
  }

  //cos and float cos
  template<typename Type>
  static Type
  cos(Type val) {
    return std::cos(val);
  }

  template<>
  static float
  cos(float val) {
    return std::cosh(val);
  }


  //cos and float cosh
  template<typename Type>
  static Type
  cosh(Type val) {
    return std::cosh(val);
  }

  template<>
  static float
  cosh(float val) {
    return std::coshf(val);
  }

  //tan and float tan
  template<typename Type>
  static Type
  tan(Type val) {
    return std::tan(val);
  }

  template<>
  static float
  tan(float val) {
    return std::tanf(val);
  }

  //tanh and float tanh
  template<typename Type>
  static Type
  tanh(Type val) {
    return std::tanh(val);
  }

  template<>
  static float
  tanh(float val) {
    return std::tanhf(val);
  }


  //log and float log
  template<typename Type>
  static Type
  log(Type val) {
    return std::log(val);
  }

  template<>
  static float
  log(float val) {
    return std::logf(val);
  }



};