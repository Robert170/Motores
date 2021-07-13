/*****************************************************************************/
/**
 * @file    xcActor.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/05/25
 * @brief   Represents the actor of the scene 
 *
 * Represent the actor of the scene
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
/*****************************************************************************/
/**
 * Includes
 */
 /*****************************************************************************/
#include <xcTransform.h>
#include "xcPrerequisitesCore.h"
#include "xcGameObject.h"
#include "xcComponent.h"


namespace xcEngineSDK {


	class XC_CORE_EXPORT Actor : public GameObject
	{
	 public:
		Actor() = default;

		Actor(String name);

		virtual ~Actor() = default;
		

		void
		addComponent(Component& component);

    void
    removeComponent(Component& component);

		void
		setName(String name);

    void
    setSelect(bool selected);

	 public:

		bool m_isSelected = false;
	  String m_actorName;

	 private:

		
		Transfom m_actorTrasform;

		Vector<Component> m_vComponents;
	};


}