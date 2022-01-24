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
#include <xcPrerequisitesCore.h>

namespace xcEngineSDK {

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
