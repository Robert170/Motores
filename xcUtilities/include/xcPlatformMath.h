/**
 * @struct PlatformMath
 *
 * @brief struct for math
 *
 * This struct contains complex math operations to use
 * in the engine
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 1/25/2021
 *
 *
 * @bug	No know Bugs
 */

#pragma once
#include <cmath>

#include "xcPrerequisitesUtilities.h"

using xcEngineSDK::int32;
namespace xcEngineSDK {
  struct XC_UTILITY_EXPORT PlatformMath {

    /**
     * @brief      sqrt function, function for square root
     * @param      val parameter one, a template for square root
     * @bug	       No know Bugs
     * @return     Returns the square root of a number
     */
    template<typename Type>
    static Type
    sqrt(Type val) {
      return std::sqrt(val);
    }

    /**
     * @brief      sqrtf function, function for square root of floats
     * @param      val parameter one, a float for square root
     * @bug	       No know Bugs
     * @return     Returns the square root of a float
     */
    template<>
    static float
    sqrt(float val) {
      return std::sqrtf(val);
    }

    /**
     * @brief      pow function, function for elevate a number
     * @param      val parameter one, a template for elevate a number
     * @param      ex parameter two, a template number to elevate
     * @bug	       No know Bugs
     * @return     Returns a number elevate to other number
     */
    template<typename Type, typename Type2>
    static Type
    pow(Type val, Type2 ex) {
      return std::pow(val, ex);
    }

    /**
     * @brief      pow function, function for elevate a number 
     * @param      val parameter one, a template for elevate a number
     * @param      ex parameter two, a template number to elevate
     * @bug	       No know Bugs
     * @return     Returns a number elevate to other number
     */
    template<>
    static float
    pow(float val, float ex) {
      return std::powf(val, ex);
    }

    /**
     * @brief      abs function, function for absolute value of a number
     * @param      val parameter one, a template for absolute value of a number
     * @bug	       No know Bugs
     * @return     Returns a absolute value of a number
     */
    template<typename Type>
    static Type
    abs(Type val) {
      return std::abs(val);
    }

    /**
     * @brief      sin function, value of sine
     * @param      val parameter one, a template for sine value
     * @bug	       No know Bugs
     * @return     Returns a number
     */
    template<typename Type>
    static Type
    sin(Type val) {
      return std::sin(val);
    }

    /**
     * @brief      sin function, value of sine in float
     * @param      val parameter one, a template for sine value
     * @bug	       No know Bugs
     * @return     Returns a float
     */
    template<>
    static float
    sin(float val) {
      return std::sinf(val);
    }

    /**
     * @brief      sin function, value of sine in float
     * @param      val parameter one, a template for sine value
     * @bug	       No know Bugs
     * @return     Returns a float
     */
    template<typename Type>
    static Type
    sinh(Type val) {
      return std::sinh(val);
    }

    /**
     * @brief      sin function, value of sine in float
     * @param      val parameter one, a template for sine value
     * @bug	       No know Bugs
     * @return     Returns a float
     */
    template<>
    static float
    sinh(float val) {
      return std::sinhf(val);
    }

    /**
     * @brief      cos function, value of cosine 
     * @param      val parameter one, a template for cosine value
     * @bug	       No know Bugs
     * @return     Returns an int
     */
    template<typename Type>
    static Type
    cos(Type val) {
      return std::cos(val);
    }

    /**
     * @brief      cos function, value of cosine in float
     * @param      val parameter one, a template for cos value
     * @bug	       No know Bugs
     * @return     Returns a float
     */
    template<>
    static float
    cos(float val) {
      return std::cosh(val);
    }


    /**
     * @brief      cosh function, value of cosine hyperbolic
     * @param      val parameter one, a template for cosine hyperbolic value
     * @bug	       No know Bugs
     * @return     Returns an int
     */
    template<typename Type>
    static Type
    cosh(Type val) {
      return std::cosh(val);
    }

    /**
     * @brief      cosh function, value of cosine hyperbolic in float
     * @param      val parameter one, a template for cosine hyperbolic value
     * @bug	       No know Bugs
     * @return     Returns a float
     */
    template<>
    static float
    cosh(float val) {
      return std::coshf(val);
    }

    /**
     * @brief      tan function, value of tangent
     * @param      val parameter one, a template for tangent value
     * @bug	       No know Bugs
     * @return     Returns an int
     */
    template<typename Type>
    static Type
    tan(Type val) {
      return std::tan(val);
    }

    /**
     * @brief      tan function, value of tangent in float
     * @param      val parameter one, a template for tangent value
     * @bug	       No know Bugs
     * @return     Returns a float
     */
    template<>
    static float
    tan(float val) {
      return std::tanf(val);
    }

    /**
     * @brief      tanh function, value of tangent hyperbolic
     * @param      val parameter one, a template for tangent hyperbolic value
     * @bug	       No know Bugs
     * @return     Returns an int
     */
    template<typename Type>
    static Type
    tanh(Type val) {
      return std::tanh(val);
    }


    /**
     * @brief      tanh function, value of tangent hyperbolic in float
     * @param      val parameter one, a template for tangent hyperbolic value
     * @bug	       No know Bugs
     * @return     Returns a float
     */
    template<>
    static float
    tanh(float val) {
      return std::tanhf(val);
    }


    /**
     * @brief      cot function, value of cotangent 
     * @param      val parameter one, a template for cotangent  value
     * @bug	       No know Bugs
     * @return     Returns an int
     */
    template<typename Type>
    static Type
    cot(Type val) {
      return cos(val) / sin(val);
    }

    /**
     * @brief      cot function, value of cotangent  in float
     * @param      val parameter one, a template for cotangent  value
     * @bug	       No know Bugs
     * @return     Returns a float
     */
    template<>
    static float
    cot(float val) {
      return cosf(val) / sinf(val);
    }


    /**
     * @brief      cosec function, value of cosecant 
     * @param      val parameter one, a template for cosecant  value
     * @bug	       No know Bugs
     * @return     Returns an int
     */
    template<typename Type>
    static Type
    cosec(Type val) {
      return 1 / sin(val);
    }

    /**
     * @brief      cosec function, value of cosecant  in float
     * @param      val parameter one, a template for cosecant  value
     * @bug	       No know Bugs
     * @return     Returns a float
     */
    template<>
    static float
    cosec(float val) {
      return 1 / sinf(val);
    }

    /**
     * @brief      sec function, value of secant 
     * @param      val parameter one, a template for secant  value
     * @bug	       No know Bugs
     * @return     Returns an int
     */
    template<typename Type>
    static Type
    sec(Type val) {
      return 1 / cos(val);
    }

    /**
     * @brief      sec function, value of secant  in float
     * @param      val parameter one, a template for secant  value
     * @bug	       No know Bugs
     * @return     Returns a float
     */
    template<>
    static float
    sec(float val) {
      return 1 / cosf(val);
    }

    /**
     * @brief      log function, value of logarithm 
     * @param      val parameter one, a template for logarithm value
     * @bug	       No know Bugs
     * @return     Returns an int
     */
    template<typename Type>
    static Type
    log(Type val) {
      return std::log(val);
    }

    /**
     * @brief      log function, value of logarithm in float
     * @param      val parameter one, a template for logarithm value
     * @bug	       No know Bugs
     * @return     Returns a float
     */
    template<>
    static float
    log(float val) {
      return std::logf(val);
    }

    static bool
    equalFloat(float a, float b);


    static const float PI; 

    static const float EULER_NUMBER; 

    static const float SMALL_NUMBER; 

    static const float KINDA_SMALL_NUMBER; 

    static const float BIG_NUMBER;

    static const float DELTA; 

    static const float DEG2RAD; 

    static const float RAD2DEG;
  };
}