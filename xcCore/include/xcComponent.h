/*****************************************************************************/
/**
 * @file    xcComponent.h
 * @author  Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/06/7
 * @brief   Represents the component of the actors
 *
 * Represent the component of the actors, you can have a lot of componets
 * per actor
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
/*****************************************************************************/
/**
 * Includes
 */
 /*****************************************************************************/
#include "xcPrerequisitesCore.h"
#include "xcGameObject.h"

namespace xcEngineSDK {

  namespace COMPONENT_ID {
    enum E {

      kModel = 0,
      kMaterial
    };
  }

	class XC_CORE_EXPORT Component
	{
	 public:
		Component() = default;
		~Component() = default;

    virtual void
    update(float deltaTime) = 0;

		virtual void 
		render() = 0;

		void
	  setID(COMPONENT_ID::E id);

		COMPONENT_ID::E
		getID();

	 private:
		 COMPONENT_ID::E m_ID;
	};
}
