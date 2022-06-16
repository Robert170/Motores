/*****************************************************************************/
/**
 * @file    xcBaseOmvniverse.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    18/01/2022
 * @brief   Base program to use the Omvniverse
 *
 * This .h is for the use of the Omvniverse in the engine
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
/*****************************************************************************/
/**
 * Includes
 */
 /*****************************************************************************/
#include <xcModule.h>
#include <xcVector3.h>
#include <xcPrerequisitesCore.h>

namespace xcEngineSDK {

  namespace OMNI_OP {
    enum E {
      kTRANSLATE,
      kROTATE,
      kSCALE
    };
  }

  namespace OMNI_PRECISION {
    enum E {
      kDOUBLE,
      kFLOAT
    };
  }


  class BaseOmvniverse : public Module<BaseOmvniverse>
  {
   public:
    BaseOmvniverse() = default;
    ~BaseOmvniverse() = default;

    FORCEINLINE void
    setObject(BaseOmvniverse* omvniverse) {
              BaseOmvniverse::_instance() = omvniverse;
    }
  
    virtual void
    init() {};

    virtual void
    update() {};

    virtual void
    createUSD(String& destinationPath, String& file) {};

    virtual bool
      loadUSD(const String& fileName) {
      XC_UNREFERENCED_PARAMETER(fileName);
      return false;
    };

    virtual bool
    connectFromOmni(const String& fileName) {
      XC_UNREFERENCED_PARAMETER(fileName);
      return false;
    }

    virtual bool
    connectToOmni(const String& fileName) {
      XC_UNREFERENCED_PARAMETER(fileName);
      return false;
    }

    virtual void
    setTransformOp(Vector3 data,
                   OMNI_OP::E operation,
                   OMNI_PRECISION::E precision,
                   String omniPath) {
      /*XC_UNREFERENCED_PARAMETER(data);
      XC_UNREFERENCED_PARAMETER(operation);
      XC_UNREFERENCED_PARAMETER(precision);
      XC_UNREFERENCED_PARAMETER(omniPath);*/
    }

    virtual bool
    getLiveEdit() { return false; }

   private:
  
  };
  
  /**
   * @brief export the instance
   */
  XC_CORE_EXPORT BaseOmvniverse&
  g_omvniverse();
  
  /**
   * @Variable funProtoGraphiAPI, instance of the class
   */
  using funProtoOmvniverse = BaseOmvniverse * (*)();
}
