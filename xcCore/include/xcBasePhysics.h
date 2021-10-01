/*****************************************************************************/
/**
 * @file    xcBasePhysics.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    12/09/2021
 * @brief   Base program to use the physics
 *
 * This .h is for the use of the physics in the engine
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
	class BasePhysics : public Module<BasePhysics>
	{
  	public:
		BasePhysics() = default;
		~BasePhysics() = default;
    FORCEINLINE void
      setObject(BasePhysics* input) {
			BasePhysics::_instance() = input;
    }

	 private:

	};

	/**
	 * @brief export the instance
	 */
	XC_CORE_EXPORT BasePhysics&
  g_physics();

	/**
	 * @Variable funProtoGraphiAPI, instance of the class
	 */
	using funProtoPhysics = BasePhysics * (*)();
}